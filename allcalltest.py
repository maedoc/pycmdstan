#!/usr/bin/env python3

%pylab inline
import numpy as np
import pylab as pl

#%%
x = np.r_[-5.0:5.0:1000j]
y = foo.gamma_lpdf(x, 3., 4.)
pl.plot(x, y, 'kx--')
