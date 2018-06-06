# pycmdstan

[![pipeline status](https://gitlab.thevirtualbrain.org/tvb/pycmdstan/badges/master/pipeline.svg)](https://gitlab.thevirtualbrain.org/tvb/pycmdstan/commits/master) [![coverage report](https://gitlab.thevirtualbrain.org/tvb/pycmdstan/badges/master/coverage.svg)](https://gitlab.thevirtualbrain.org/tvb/pycmdstan/commits/master) [![PyPI package version](https://img.shields.io/pypi/v/pycmdstan.svg)](https://pypi.org/project/pycmdstan/) [![Documentation Status](https://readthedocs.org/projects/pycmdstan/badge/?version=latest)](https://pycmdstan.readthedocs.io/en/latest/?badge=latest)

Python interface to CmdStan.

## Usage
After installing,  `pip install -U pycmdstan`, a contrived example would be
```python
from pycmdstan import Model, Run

model = Model('''
data { vector[20] x; real mu; }
parameters { real sig; }
model { x ~ normal(mu, sig); }
''')

assert model.sample(data={'mu': 5.0, x: randn(20)}, chains=4).R_hat.max() < 1.2
```
See the [docs](https://pycmdstan.readthedocs.io/en/latest/) for more.

## Contributing

Contributions are welcome, please start in the issue tracker. 
Use YAPF to format the code.  The Dockerfile can ease local development, 
```
docker build -t pycmdstan .
docker run --rm -it pycmdstan pytest -n4 pycmdstan/tests.py
```

## Acknowledgements

- PSIS code is by Aki Vehtari & Tuomas Sivula (BSD licensed, [repo here](https://github.com/avehtari/PSIS))