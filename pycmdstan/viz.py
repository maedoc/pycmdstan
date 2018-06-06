from .io import parse_csv
from math import sqrt
import numpy as np
import pylab as pl


def _plot_key(fn, csv, *keys):
    alpha = 1.0 / sqrt(len(keys))
    for key in keys:
        fn(csv[key], label=key, alpha=alpha)
    pl.legend()


def plot_key(csv, *keys):
    """Create a trace plot for keys (parameter names) in sample set.
    """
    _plot_key(pl.plot, csv, *keys)


def hist_key(csv, *keys):
    """Create a histogram for keys (parameter names) in sample set.
    """
    def _(x, **kwargs):
        pl.hist(x.reshape((-1, )), bins=int(sqrt(len(x))), **kwargs)

    _plot_key(_, csv, *keys)


def trace_nuts(csv, extras='', skip=0, n_col=4):
    """Trace plots of NUTS state, along with other model parameters.
    """
    from pylab import subplot, plot, gca, title, grid, xticks
    if isinstance(csv, dict):
        csv = [csv]
    if isinstance(extras, str):
        extras = extras.split()
    n_nuts_params = 7
    n_subplots = len(extras) + n_nuts_params
    n_row = n_subplots // n_col + 1
    for csvi in csv:
        i = 1
        for key in csvi.keys():
            if key.endswith('__') or key in extras:
                subplot(n_row, n_col, i)
                plot(csvi[key][skip:], alpha=0.5)
                if key in ('stepsize__', ):
                    gca().set_yscale('log')
                title(key)
                grid(1)
                # e.g. 3x3 subplots, w/ 7 used, want 5,6,7 to have x ticks
                if i < (n_subplots - n_col):
                    xticks(xticks()[0], [])
                i += 1


def pairs(csv, keys, skip=0):
    """Create a pairs plot for keys in the given dataset.
    """
    import pylab as pl
    n = len(keys)
    if isinstance(csv, dict):
        csv = [csv]  # following assumes list of chains' results
    for i, key_i in enumerate(keys):
        for j, key_j in enumerate(keys):
            pl.subplot(n, n, i * n + j + 1)
            for csvi in csv:
                if i == j:
                    pl.hist(csvi[key_i][skip:], 20, log=True)
                else:
                    pl.plot(csvi[key_j][skip:], csvi[key_i][skip:], '.')
            if i == 0:
                pl.title(key_j)
            if j == 0:
                pl.ylabel(key_i)


def parallel_coordinates(csv, keys, marker='ko-'):
    """Create a parallel coordinates plot for keys in the given dataset.
    """
    nsamp = csv['lp__'].shape[0]
    flats = {k: v.reshape((nsamp, -1)) for k, v in csv.items() if k in keys}
    key_i = 0
    mats = []
    key_idx = []
    key_val = []
    for k, v in flats.items():
        mats.append(v)
        key_idx.append(key_i)
        key_val.append(k)
        key_i += v.shape[1]
    mats = np.hstack(mats)
    mats = ((mats - mats.min(axis=0)) / mats.ptp(axis=0)).T
    pl.plot(mats, 'ko-', alpha=1 / np.sqrt(nsamp))
    pl.xticks(key_idx, key_val)
    pl.yticks([])
    pl.grid(1)