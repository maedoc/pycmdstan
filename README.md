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

A brief tour of the API (not all parts are implemented yet):
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

## Rationale

Why use this instead of PyStan?

### More robust runtime

Building shared object extensions to Python is always fraught with questions like, will it crash in the middle of my session? Using an external executable trades lower interop performance for better stability.

### Simpler deployment

For some projects, CmdStan's toolchain is a simpler deployment, because we're dealing only with a make & a C++ compiler, not the whole Python toolchain as well.  This makes it easier to tune optimization flags freely as well.

### Make-based workflows

Some of our workflows are already in Make, and CmdStan fits in, and we just needed a little extra Python to smooth things over.

### License

Some of our projects require commercial-friendly license in order to get funded.