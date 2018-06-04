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


def follow_hmc(csv_fname):
    from .io import follow_csv
    from threading import Thread
    import numpy as np
    keys = 'lp accept_stat stepsize treedepth n_leapfrog divergent energy'.split(
    )
    fig = pl.figure()
    pl.show()
    data = []

    line, = pl.plot(data)

    def cb(s):
        try:
            status = s.split(',')[:len(keys)]
            print(status)
            data.append(float(status[0]))
            line.set_data(np.r_[:len(data)], np.array(data))
            pl.draw()
        except Exception as exc:
            print(exc)

    # t = Thread(target=follow_csv, args=(csv_fname, cb))
    # t.start()
    # return t
    follow_csv(csv_fname, cb)