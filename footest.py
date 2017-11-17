#!/usr/bin/env python3
import os
os.system('python3 setup.py build')
import glob
import sys
sys.path.append(glob.glob('build/lib.*')[0])
import foo
import numpy as np
import pylab as pl
r = foo.rng()
a, b = np.r_[1.0:2.0:5j], np.r_[2.3]
print(foo.gamma(r, a, b))
print(foo.gamma(r, 3, 4))
