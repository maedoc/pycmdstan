import os
import enum
import subprocess
import hashlib
import logging
import tempfile
import threading
import filelock
import numpy as np
from . import io, psis

logger = logging.getLogger('pycmdstan.model')


class CmdStanNotFound(RuntimeError):
    pass


def _find_cmdstan(path=''):
    if path:
        path = os.path.expanduser(os.path.expandvars(path))
        os.environ['CMDSTAN'] = path
    path = os.environ.get('CMDSTAN', 'cmdstan')
    if not os.path.exists(os.path.join(path, 'runCmdStanTests.py')):
        raise CmdStanNotFound(
            'please provide CmdStan path, e.g. lib.cmdstan_path("/path/to/")')
    return path


def preprocess_model(stan_fname, hpp_fname=None, overwrite=False):
    hpp_fname = hpp_fname or stan_fname.replace('.stan', '.hpp')
    stanc_path = os.path.join(_find_cmdstan(), 'bin', 'stanc')
    cmd = [stanc_path, f'--o={hpp_fname}', f'{stan_fname}']
    cwd = os.path.abspath(os.path.dirname(stan_fname))
    subprocess.check_call(cmd, cwd=cwd)


def compile_model(stan_fname, opt_lvl):
    path = os.path.abspath(os.path.dirname(stan_fname))
    name = stan_fname[:-5]
    target = os.path.join(path, name)
    proc = subprocess.Popen(
        ['make', f'O={opt_lvl}', target],
        cwd=_find_cmdstan(),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
    stdout = proc.stdout.read().decode('ascii').strip()
    if stdout:
        print(stdout)
    stderr = proc.stderr.read().decode('ascii').strip()
    if stderr:
        print(stderr)


def stansummary_csv(csv_in):
    if not isinstance(csv_in, list):
        csv_in = [csv_in]
    exe = os.path.join(_find_cmdstan(), 'bin', 'stansummary')
    with tempfile.TemporaryDirectory() as td:
        csv_out = os.path.join(td, 'summary.csv')
        cmd = [exe, f'--csv_file={csv_out}'] + csv_in
        subprocess.check_call(cmd, stdout=subprocess.DEVNULL)
        summary = io.parse_summary_csv(csv_out)
    return summary


def model_path() -> str:
    key = 'PYCMDSTAN_MODEL_PATH'
    if key not in os.environ:
        os.environ[key] = os.path.join(
            os.path.expanduser('~'), '.cache', 'pycmdstan')
    if not os.path.exists(os.environ[key]):
        logger.debug(f'creating cache dir {os.environ[key]}')
        os.makedirs(os.environ[key])
    logger.debug(f'have model path {os.environ[key]}')
    return os.environ[key]


class Model:
    """Stan model.
    """

    def __init__(self, code: str = None, fname: os.PathLike = None, opt_lvl=3):
        self.code = code
        self.opt_lvl = opt_lvl
        if fname and code is None:
            with open(fname, 'r') as fd:
                self.code = fd.read().decode('ascii')

    @property
    def sha256(self) -> str:
        sha = hashlib.sha256()
        sha.update(self.code.encode('ascii'))
        return f'sha256{sha.hexdigest()}'

    def _compile(self, stan_fname):
        with open(stan_fname, 'w') as fd:
            fd.write(self.code)
        compile_model(stan_fname, opt_lvl=self.opt_lvl)

    def compile(self, path=None):
        self.path = path or model_path()
        self.stan_fname = os.path.join(self.path, f'{self.sha256}.stan')
        self.exe, _ = self.stan_fname.rsplit('.stan')
        self._lock = filelock.FileLock(f'{self.exe}.lock')
        with self._lock:
            if not os.path.exists(self.exe):
                self._compile(self.stan_fname)

    def sample(self, **kwargs):
        return self.run(method='sample', **kwargs)

    def variational(self, **kwargs):
        return self.run(method='variational', **kwargs)

    def optimize(self, **kwargs):
        return self.run(method='optimize', **kwargs)

    def run(self, method, chains=1, wait=False, **kwargs):
        rng = np.random.RandomState()
        rng.seed(kwargs.pop('id', 0))
        runs = [
            Run(model=self,
                method=method,
                id=rng.random_integers(99999),
                **kwargs) for _ in range(chains)
        ]
        if len(runs) == 1:
            return runs[0]
        else:
            return RunSet(*runs)


class Method(enum.Enum):
    optimize = 'optimize'
    sample = 'sample'
    variational = 'variational'


class Run:
    def __init__(self,
                 model: Model,
                 method: Method,
                 data: dict = None,
                 id: int = None,
                 log_lik: str = 'log_lik',
                 start: bool = True,
                 wait: bool = False,
                 **method_args):
        self.model = model
        self.id = id
        self.log_lik = log_lik
        self.method = method.value if isinstance(method, Method) else method
        self.method_args = method_args
        self.data = data
        self.tmp_dir = tempfile.TemporaryDirectory()
        self.output_csv_fname = os.path.join(self.tmp_dir.name, 'output.csv')
        if data:
            self.data_R_fname = os.path.join(self.tmp_dir.name, 'data.R')
            io.rdump(self.data_R_fname, data)
        self.start(wait=wait)

    def __del__(self):
        self.tmp_dir.cleanup()

    def start(self, wait=True):
        if not hasattr(self.model, 'exe'):
            self.model.compile()
        self.cmd = cmd = [self.model.exe]
        if self.id is not None:
            cmd.append(f'id={self.id}')
        cmd.append(self.method)
        if self.method_args:
            for key, val in self.method_args.items():
                cmd.append(f'{key}={val}')
        if self.data:
            cmd.extend(['data', f'file={self.data_R_fname}'])
        cmd.extend(['output', f'file={self.output_csv_fname}'])
        logger.info('starting run with cmd %s', ' '.join(cmd))
        self.proc = subprocess.Popen(cmd)
        if wait:
            self.wait()

    def wait(self):
        if not hasattr(self, 'proc'):
            self.start(wait=False)
        self.proc.wait()
        if self.proc.returncode != 0:
            msg = 'Stan model exited with an error (%d)'
            raise RuntimeError(msg, self.proc.returncode)

    @property
    def csv(self):
        if not hasattr(self, '_csv'):
            self.wait()
            self._csv = io.parse_csv(self.output_csv_fname)
            if self.log_lik in self._csv:
                self._csv.update(psis.psisloo(-self._csv[self.log_lik]))
        return self._csv

    def __getitem__(self, key):
        return self.csv[key]


class RunSet:
    def __init__(self, *runs):
        self.runs = runs

    @property
    def summary(self):
        if not hasattr(self, '_summary'):
            self.niter, self._summary = stansummary_csv(
                [r.output_csv_fname for r in self.runs])
        return self._summary

    def __getitem__(self, key):
        return self.summary[key]

    def flat_field(self, field, only_params=True):
        vals = []
        for key, val in self.summary.items():
            if only_params and key.endswith('__'):
                continue
            vals.append(val[field].reshape((-1, )))
        return np.hstack(vals)

    @property
    def R_hats(self):
        return self.flat_field('R_hat')

    @property
    def N_eff(self):
        return self.flat_field('N_eff')