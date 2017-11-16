#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "foo.hpp"
int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;

PYBIND11_MODULE(foo, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: python_example

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    m.def("gamma_rng", [](int n, double a, double b) {
      boost::ecuyer1988 rng = foo_functions::__create_rng(42);
      return foo_functions::stan_gamma_rng(n, a, b, rng, &std::cout);
    }, "call stan gamma rng");

    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
