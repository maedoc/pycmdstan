import os
import unittest
import subprocess
import tempfile
import numpy as np
import numpy.testing
from .io import rdump, rload
from .model import Model, Run, _find_cmdstan, CmdStanNotFound


class BaseTestCase(unittest.TestCase):
    def setUp(self):
        self.tmp_dir = tempfile.TemporaryDirectory()
        os.environ['PYCMDSTAN_MODEL_PATH'] = self.tmp_dir.name

    def tearDown(self):
        self.tmp_dir.cleanup()

    def tmp_fname(self, fname):
        return os.path.join(self.tmp_dir.name, fname)


class SimpleIOTests(BaseTestCase):
    def test_write_read(self):
        data = {'int': 3, 'real': 2.3, 'mat': np.random.randn(4, 4)}
        fname = self.tmp_fname('write_read.R')
        rdump(fname, data)
        data_ = rload(fname)
        for key, val in data.items():
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
        model = Model(self.model1_code)
        run = Run(
            model, 'sample', method_args={
                'num_warmup': 1,
                'num_samples': 1
            })
        for key in 'lp__ x'.split():
            self.assertIn(key, run.csv)
        mat_ = run['mat'][0]
        mat = (np.r_[:12] + 1.0).reshape((3, 4)).T
        self.assertTrue(np.allclose(mat, mat_))


class TestPSIS(BaseTestCase):

    model_code = '''
data { vector[20] x; real mu; }
parameters { real sig; }
model { x ~ normal(mu, sig); sig ~ normal(1, 0.01); }
generated quantities {
    vector[20] log_lik;
    for (i in 1:20) log_lik[i] = normal_lpdf(x[i] | mu, sig);
}
'''

    def test_model(self):
        model = Model(code=self.model_code)
        base_data = {'x': np.random.randn(20) + 5.0}
        loo = []
        for mu in np.r_[1.0, 3.0, 5.0, 7.0, 9.0]:
            data = {'mu': mu}
            data.update(base_data)
            run = Run(
                model,
                'sample',
                data,
                method_args={
                    'num_warmup': 200,
                    'num_samples': 200
                })
            self.assertIn('log_lik', run.csv)
            loo.append(run['loo'])
        loo = np.array(loo)
        self.assertEqual(np.argmin(loo), 2)
