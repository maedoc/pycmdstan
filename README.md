# pycmdstan

[![Build Status](https://travis-ci.org/maedoc/pycmdstan.svg?branch=master)](https://travis-ci.org/maedoc/pycmdstan) [![Coverage Status](https://coveralls.io/repos/github/maedoc/pycmdstan/badge.svg?branch=master)](https://coveralls.io/github/maedoc/pycmdstan?branch=master)

Python interface to CmdStan.

## Install

Pycmdstan is a pure-Python repo which can be installed from
the GitHub repo
```
pip install -e git+https://github.com/maedoc/pycmdstan
```
or (eventually) from PyPI
```
pip install pycmdstan
```

## Usage

An idea of the API (not yet complete)
```python
import pycmdstan.all as stan
stan.use('~/Downloads/CmdStan-2.17.1')

model = stan.Model.from_file('bernoulli.stan')
model.compile()

run = model.sample(data={...})

run.status
# Iter 200 / 400

run.plot_trace(nuts=True, extra='K sigma')
```
a notable goal is to be able to diagnose warmup while it's
running.

## Roadmap (wishlist)

- [x] preprocess & compile Stan model with support for `#include`s
- [ ] run model w/ multiple chains
- [ ] invoke summary or other executables
- [x] read/write Rdump format (modulo a bug somewhere)
- [x] read sample & summary CSV format
- [ ] common visualizations (trace, pairs, rhat hist)
- coordinators `opt_to_init`, `sim_fit` which can sequence model invocations for common cases
- typical makefile suspects `invoke_stanc`, `compile_model`, etc
- bind standalone funcs via ctypes
- bind density functions + jupyter widgets to tune dist params interactively
- auto get cmdstan sources & build
- model comparison, at least WAIC & PSIS LOO
