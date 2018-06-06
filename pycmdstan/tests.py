import functools
import re
import os
import unittest
import subprocess
import tempfile
import logging
import numpy as np
import numpy.testing
import matplotlib
matplotlib.use('Agg')
from .io import rdump, rload, parse_csv
from .model import Model, Run, _find_cmdstan, CmdStanNotFound
from .viz import plot_key, hist_key, trace_nuts, pairs, parallel_coordinates
from .__main__ import main

logging.basicConfig(level=logging.INFO)


class BaseTestCase(unittest.TestCase):
    use_tmp = True

    def setUp(self):
        self.tmp_dir = tempfile.TemporaryDirectory()
        if self.use_tmp:
            os.environ['PYCMDSTAN_MODEL_PATH'] = self.tmp_dir.name

    def tearDown(self):
        self.tmp_dir.cleanup()

    def tmp_fname(self, fname):
        return os.path.join(self.tmp_dir.name, fname)


class SimpleIOTests(BaseTestCase):
    def setUp(self):
        super().setUp()
        self.data = {
            'int': 3,
            'real': 2.3,
            'mat': np.random.randn(4, 4),
            'vec': np.r_[1, 2, 3]
        }
        self.fname = self.tmp_fname('write_read.R')

    def test_write_read(self):
        rdump(self.fname, self.data)
        data_ = rload(self.fname)
        for key, val in self.data.items():
            val_ = data_[key]
            if key in 'int real'.split():
                self.assertEqual(val, val_)
            else:
                self.assertTrue(np.allclose(val, val_))

    def test_bad_value(self):
        bad_fname = self.tmp_fname('bad.R')
        with open(bad_fname, 'w') as fd:
            fd.write('b <- foo')
        with self.assertRaises(ValueError):
            rload(bad_fname)


class ModelTest(BaseTestCase):

    model1_code = '''
parameters { real x; }
model { x ~ normal(0, 1); }
generated quantities {
    matrix[3, 4] mat;
    for (i in 1:3)
        for (j in 1:4)
            mat[i, j] = (i - 1)*4 + j;
}
'''

    def test_not_found(self):
        import os
        cmdstan = os.environ['CMDSTAN']
        del os.environ['CMDSTAN']
        with self.assertRaises(CmdStanNotFound):
            _find_cmdstan()
        os.environ['CMDSTAN'] = cmdstan

    def test_model1(self):
        model = Model(self.model1_code, opt_lvl=0)
        model.compile()
        run = model.sample(num_warmup=1, num_samples=1)
        for key in 'lp__ x'.split():
            self.assertIn(key, run.csv)
        mat_ = run['mat'][0]
        mat = (np.r_[:12] + 1.0).reshape((3, 4)).T
        self.assertTrue(np.allclose(mat, mat_))

    def test_code_from_file(self):
        fname = self.tmp_fname('code.stan')
        with open(fname, 'w') as fd:
            fd.write(self.model1_code)
        model = Model(fname=fname, opt_lvl=0)
        self.assertEqual(self.model1_code, model.code)


class TestMetrics(BaseTestCase):
    # cache model on test machine and cover code path for ~/.cache/pycmdstan/...
    use_tmp = False

    model_code = '''
data { vector[20] x; real mu; }
parameters { real sig; }
model { x ~ normal(mu, sig); sig ~ normal(1, 0.01); }
generated quantities {
    vector[20] log_lik;
    for (i in 1:20) log_lik[i] = normal_lpdf(x[i] | mu, sig);
}
'''

    def setUp(self):
        super().setUp()
        self.model = Model(code=self.model_code, opt_lvl=0)
        self.data = {'x': np.random.randn(20) + 5.0}
        self.args = dict(num_warmup=200, num_samples=200)

    def test_psis(self):
        loo = []
        for mu in np.r_[1.0, 3.0, 5.0, 7.0, 9.0]:
            run = self.model.sample(data=dict(mu=mu, **self.data), **self.args)
            loo.append(run['loo'])
        loo = np.array(loo)
        self.assertEqual(np.argmin(loo), 2)


class TestSummary(TestMetrics):
    def test_summary(self):
        data = dict(mu=5.0, **self.data)
        runs = self.model.sample(data=data, chains=4, **self.args)
        runs['lp__']
        self.assertLess(runs.R_hats.max(), 1.2)
        # cover parse_csv & merge paths
        csv = parse_csv([r.output_csv_fname for r in runs])
        csv = runs.csv
        self.assertGreater(runs.niter, 0)
        self.assertGreater(runs.N_Eff_per_iter.min(), 0.2)


class TestComplexArgs(TestMetrics):
    def test_complex_args(self):
        run = self.model.sample(
            data=dict(mu=5.0, **self.data),
            num_samples=1,
            num_warmup=1,
            adapt_='delta=0.8',
            algorithm='hmc engine=nuts max_depth=12',
            start=False)
        run.start(wait=True)
        cmd = ' '.join(run.cmd)
        self.assertIsNotNone(re.search('adapt delta', cmd))
        self.assertIsNotNone(re.search('algorithm=hmc engine=nuts', cmd))


def savefig(f):
    @functools.wraps(f)
    def test(self):
        import pylab as pl
        pl.figure()
        f(self)
        pl.savefig(f'{f.__name__}.png')
        pl.close()

    return test


class TestPlots(BaseTestCase):
    def setUp(self):
        super().setUp()
        self.data = {k: v for k, v in zip('xyz', np.random.randn(3, 100))}

    @savefig
    def test_plot_key(self):
        plot_key(self.data, 'x')

    @savefig
    def test_hist_key(self):
        hist_key(self.data, 'x')

    @savefig
    def test_pairs(self):
        pairs(self.data, 'x y z'.split(), skip=100)


class TestPlotNutsTrace(TestMetrics):
    @savefig
    def test_trace_nuts(self):
        data = dict(mu=5.0, **self.data)
        run = self.model.sample(data=data, **self.args)
        with self.assertRaises(RuntimeError):
            run.start()
        trace_nuts(run.csv, 'sig', skip=100)


class TestPlotParCoord(BaseTestCase):
    @savefig
    def test_plot_parallel_coordinates(self):
        nsamp = 100
        csv = dict(
            x=randn(nsamp, 3, 3) * randn(3, 3) + sin(r_[:9] / 4).reshape(
                (3, 3)),
            y=randn(nsamp, 2)**2,
            z=abs(randn(nsamp))**0.5,
            z1=randn(nsamp)**3,
            lp__=randn(nsamp))
        keys = 'x y z'.split()
        parallel_coordinates(csv, keys)


class TestStanError(TestMetrics):
    def test_stan_error(self):
        data = dict(mu=5.0, **self.data)
        with self.assertRaises(RuntimeError):
            run = self.model.sample(foo='bar')
            run.csv
