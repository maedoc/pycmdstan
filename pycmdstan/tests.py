import os
import unittest
import subprocess
import tempfile
import logging
import numpy as np
import numpy.testing
from .io import rdump, rload
from .model import Model, Run, _find_cmdstan, CmdStanNotFound

logging.basicConfig(level=logging.DEBUG)


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
        self.data = {'int': 3, 'real': 2.3, 'mat': np.random.randn(4, 4)}
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


class TestMetrics(BaseTestCase):

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
    # cover code path for ~/.cache/pycmdstan/...
    use_tmp = False

    def test_summary(self):
        data = dict(mu=5.0, **self.data)
        runs = self.model.sample(data=data, chains=4, **self.args)
        self.assertLess(runs.R_hats.max(), 1.2)