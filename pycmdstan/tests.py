import os
import unittest
import tempfile
import numpy as np
import numpy.testing
from . import io


class BaseTestCase(unittest.TestCase):
    
    def setUp(self):
        self.tmp_dir = tempfile.TemporaryDirectory()
        
    def tearDown(self):
        self.tmp_dir.cleanup()
        
    def tmp_fname(self, fname):
        return os.path.join(self.tmp_dir.name, fname)
    

class SimpleIOTests(BaseTestCase):
    
    def test_write_read(self):
        data = {
            'int': 3,
            'real': 2.3,
            'mat': np.random.randn(4, 4)
        }
        fname = self.tmp_fname('write_read.R')
        io.rdump(fname, data)
        data_ = io.rload(fname)
        for key, val in data.items():
            val_ = data_[key]
            if key in 'int real'.split():
                self.assertEqual(val, val_)
            else:
                self.assertTrue(
                    np.allclose(val, val_))