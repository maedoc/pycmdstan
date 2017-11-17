#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include "foo.hpp"

// only need this once
struct stan_rng {
  boost::ecuyer1988 rng;
  stan_rng(int seed=42) : rng(foo_functions::__create_rng(seed)) { }
};

// autogen this part with pycmdstan.densities module
double stan_rng_gamma(stan_rng &r, double a, double b) {
  return foo_functions::stan_gamma_rng(a, b, r.rng, &std::cout);
}

namespace py = pybind11;
PYBIND11_MODULE(foo, m) {
    m.doc() = "foo module wraps stuff from stan";
    py::class_<stan_rng>(m, "rng").def(py::init<>());
    m.def("gamma", py::vectorize(stan_rng_gamma), "");
}
