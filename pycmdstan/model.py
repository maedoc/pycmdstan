import os
import subprocess
import hashlib


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
        sha.update(self.code)
        return sha.hexdigest()

    def __call__(self, *args, **kwargs) -> 'Run':
        return Run(model=self, *args, **kwargs)


class Run:
    """Run of Stan model.

    - model
    - data set
    - output csv
    - cmd line args
    """

    def __init__(self, model, *args, **kwargs):
        self.model = model
