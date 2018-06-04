# pycmdstan

[![pipeline status](https://gitlab.thevirtualbrain.org/tvb/pycmdstan/badges/master/pipeline.svg)](https://gitlab.thevirtualbrain.org/tvb/pycmdstan/commits/master) [![coverage report](https://gitlab.thevirtualbrain.org/tvb/pycmdstan/badges/master/coverage.svg)](https://gitlab.thevirtualbrain.org/tvb/pycmdstan/commits/master)

Python interface to CmdStan.

## Install

Pycmdstan is a pure-Python package which can be installed from
the Git repo
```
pip install -e git+https://gitlab.thevirtualbrain.org/tvb/pycmdstan
```
or (eventually) from PyPI
```
pip install pycmdstan
```

## Usage

```python
import os
os.environ['CMDSTAN'] = '~/src/cmdstan-2.17.1'
from pycmdstan import Model, Run

model = Model('''
data { vector[20] x; real mu; }
parameters { real sig; }
model { x ~ normal(mu, sig); }
generate quantities {
    vector[20] log_lik;
    for (i in 1:20) log_lik[i] = normal_lpdf(x[i] | mu, sig);
}
''')

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
    loo.append(run['loo'])
loo = np.array(loo)
```
a notable goal is to be able to inspect warmup while it's
running.

## Roadmap (wishlist)

- [x] preprocess & compile Stan model with support for `#include`s
- [ ] run model w/ multiple chains
- [ ] invoke summary or other executables
- [x] read/write Rdump format (modulo a bug somewhere)
- [x] read sample & summary CSV format
- [x] model comparison, at least PSIS LOO
- [ ] common visualizations (trace, pairs, rhat hist)
- [ ] coordinators `opt_to_init`, `sim_fit` which can sequence model invocations for common cases
- [ ] typical makefile suspects `invoke_stanc`, `compile_model`, etc
- [ ] bind standalone funcs via ctypes
- [ ] bind density functions + jupyter widgets to tune dist params interactively
- [ ] auto get cmdstan sources & build

## Dev

Use YAPF to format the code.  The Dockerfile can ease local development, 

```
docker build -t pycmdstan .
docker run --rm -it -v `pwd`:/opt/pycmdstan pycmdstan python -m unittest discover
```

## Acknowledgements

- PSIS code is by Aki Vehtari & Tuomas Sivula (BSD licensed, [repo here](https://github.com/avehtari/PSIS))