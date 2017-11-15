# pycmdstan

Python interface to CmdStan.

## Install

## Use

 The main assumption is that
CmdStan works, is built and can be found on the filesystem at
`$CMDSTAN` or `%CMDSTAN%`, e.g.

```bash
$ (cd Downloads; unzip cmdstan-2.17.0.zip; cd cmdstan-*; make -j build)
$ export CMDSTAN=~/Downloads/cmdstan-2.17.0
$ cd work/proj
$ pycmdstan compile_model foo.stan
$ ./foo optimize ... output file=opt.csv
$ pycmdstan opt_to_init opt.{csv,R}
$ ./foo sample init=opt.R ...
$ python <<<EOF
import pycmdstan as pcs
samples = pcs.read_csv('foo-*.csv')
plot(samples['x'][:, -1]...)
...
```
Not all that is implemented quite yet, though.

## Roadmap

- bring in scattered bits of code I have elsewhere
- I/O functions, `rdump`, `read_csv`, `csv2R`, `read_summary` etc
- coordinators `opt_to_init`, `sim_fit` which can sequence model invocations for common cases
- typical makefile suspects `invoke_stanc`, `compile_model`, etc
- call functions from ctypes (e.g. gen `extern "C"` decls & ctypes specs)
- pyqt gui to choose/visualize density parameters
