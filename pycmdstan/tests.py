import os
import unittest
import subprocess
import tempfile
import numpy as np
import numpy.testing
from . import io, model


class BaseTestCase(unittest.TestCase):
    def setUp(self):
        self.tmp_dir = tempfile.TemporaryDirectory()

    def tearDown(self):
        self.tmp_dir.cleanup()

    def tmp_fname(self, fname):
        return os.path.join(self.tmp_dir.name, fname)


class SimpleIOTests(BaseTestCase):
    def test_write_read(self):
        data = {'int': 3, 'real': 2.3, 'mat': np.random.randn(4, 4)}
        fname = self.tmp_fname('write_read.R')
        io.rdump(fname, data)
        data_ = io.rload(fname)
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
        with self.assertRaises(model.CmdStanNotFound):
            model._find_cmdstan()
        os.environ['CMDSTAN'] = cmdstan

    def test_model1(self):
        fname = self.tmp_fname('model1.stan')
        with open(fname, 'w') as fd:
            fd.write(self.model1_code)
        model.preprocess_model(fname)
        model.compile_model(fname)
        cmd = '{0} sample num_warmup=1 num_samples=1 output file={1}'
        csv_fname = self.tmp_fname('model1.csv')
        cmd = cmd.format(fname.split('.stan')[0], csv_fname)
        subprocess.check_call(cmd.split())
        csv = io.parse_csv(csv_fname)
        for key in 'lp__ x'.split():
            self.assertIn(key, csv)
        mat_ = csv['mat'][0]
        mat = (np.r_[:12] + 1.0).reshape((3, 4)).T
        self.assertTrue(np.allclose(mat, mat_))
