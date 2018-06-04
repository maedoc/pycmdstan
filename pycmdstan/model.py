import os
import enum
import subprocess
import hashlib
import logging
import tempfile
from . import io

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
        return sha.hexdigest()

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
    """Run of Stan model.

    - model
    - data set
    - output csv
    - cmd line args
    """

    def __init__(self,
                 model: Model,
                 method: Method,
                 data: dict,
                 method_args: dict = None,
                 id: int = None):
        self.model = model
        self.id = id
        self.method = method
        self.method_args = method_args
        self.data = data
        self.tmp_dir = tempfile.TemporaryDirectory()
        self.output_csv_fname = os.path.join(self.tmp_dir.name, 'output.csv')
        self.data_R_fname = os.path.join(self.tmp_dir.name, 'data.R')
        io.rdump(self.data_R_fname, data)
        self.start()

    def start(self):
        cmd = [
            self.model.exe,
            self.method.value,
        ]
        if self.method_args:
            for key, val in self.method_args.items():
                cmd.append(f'{key}={val}')
        logger.debug('starting run with cmd %s', ' '.join(cmd))
        self.proc = subprocess.Popen()
