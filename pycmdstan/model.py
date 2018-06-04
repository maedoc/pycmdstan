import os
import enum
import subprocess
import hashlib
import logging
import tempfile
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


def compile_model(stan_fname):
    path = os.path.abspath(os.path.dirname(stan_fname))
    name = stan_fname[:-5]
    target = os.path.join(path, name)
    proc = subprocess.Popen(
        ['make', target],
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


def model_path() -> str:
    key = 'PYCMDSTAN_MODEL_PATH'
    home = os.path.expanduser('~')
    if key not in os.environ:
        os.environ[key] = os.path.join(home, '.cache', 'pycmdstan')
    return os.environ[key]


class Model:
    """Stan model.
    """

    def __init__(self, code: str = None, fname: os.PathLike = None):
        self.code = code
        if fname and code is None:
            with open(fname, 'r') as fd:
                self.code = fd.read().decode('ascii')

    @property
    def sha256(self) -> str:
        sha = hashlib.sha256()
        sha.update(self.code.encode('ascii'))
        return f'sha256{sha.hexdigest()}'

    def compile(self, path=None):
        path = path or model_path()
        stan_fname = os.path.join(path, f'{self.sha256}.stan')
        with open(stan_fname, 'w') as fd:
            fd.write(self.code)
        compile_model(stan_fname)
        self.exe, _ = stan_fname.rsplit('.stan')


class Method(enum.Enum):
    optimize = 'optimize'
    sample = 'sample'
    variational = 'variational'


class Run:
    def __init__(self,
                 model: Model,
                 method: Method,
                 data: dict = None,
                 method_args: dict = None,
                 id: int = None,
                 log_lik: str = 'log_lik'):
        self.model = model
        self.id = id
        self.log_lik = log_lik
        self.method = method.value if isinstance(method, Method) else method
        self.method_args = method_args
        self.data = data
        self.tmp_dir = tempfile.TemporaryDirectory()
        self.output_csv_fname = os.path.join(self.tmp_dir.name, 'output.csv')
        self.data_R_fname = os.path.join(self.tmp_dir.name, 'data.R')
        io.rdump(self.data_R_fname, data or {})
        self.start()

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
        cmd.extend(['data', f'file={self.data_R_fname}'])
        cmd.extend(['output', 'refresh=1', f'file={self.output_csv_fname}'])
        logger.warning('starting run with cmd %s', ' '.join(cmd))
        self.proc = subprocess.Popen(cmd)
        if wait:
            self.wait()

    def wait(self):
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
