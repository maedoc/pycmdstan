import os
import subprocess


class CmdStanNotFound(RuntimeError):
    pass


def _find_cmdstan():
    try:
        return os.environ['CMDSTAN']
    except:
        raise CmdStanNotFound


def preprocess_model(stan_fname, hpp_fname, overwrite=False):
    stanc_path = os.path.join(_find_cmdstan(), 'bin', 'stanc')
    subprocess.check_call(
        [stanc_path, f'--o={hpp_fname}', f'{stan_fname}'],
        cwd=os.path.dirname(stan_fname)
    )

# TODO wrap functions w/ ctypes