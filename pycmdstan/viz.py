from .io import parse_csv
from math import sqrt
import pylab as pl


def _plot_key(fn, csv_fname, *keys):
    pl.style.use('bmh')
    csv = parse_csv(csv_fname)
    if len(keys) == 0:
        print(' '.join(csv.keys()))
        return
    alpha = 1.0 / sqrt(len(keys))
    for key in keys:
        fn(csv[key], label=key, alpha=alpha)
    pl.title(csv_fname)
    pl.legend()
    pl.show()


def plot_key(csv_fname, *keys):
    _plot_key(pl.plot, csv_fname, *keys)


def hist_key(csv_fname, *keys):
    def _(x, **kwargs):
        pl.hist(x.reshape((-1, )), bins=int(sqrt(len(x))), **kwargs)

    _plot_key(_, csv_fname, *keys)
