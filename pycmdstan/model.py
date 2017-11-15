import os
import subprocess


class CmdStanNotFound(RuntimeError):
    pass


def _find_cmdstan():
    try:
        return os.environ['CMDSTAN']
    except:
        raise CmdStanNotFound


def preprocess_model(stan_fname, hpp_fname=None, overwrite=False):
    hpp_fname = hpp_fname or stan_fname.replace('.stan', '.hpp')
    stanc_path = os.path.join(_find_cmdstan(), 'bin', 'stanc')
    cmd = [stanc_path, f'--o={hpp_fname}', f'{stan_fname}']
    cwd = os.path.abspath(os.path.dirname(stan_fname))
    subprocess.check_call(
        cmd,
        cwd=cwd
    )

# TODO wrap functions w/ ctypes