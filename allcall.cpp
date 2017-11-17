#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <pybind11/iostream.h>
#include "allcall.hpp"

namespace py = pybind11;
PYBIND11_MODULE(allcall, m) {
    m.doc() = "Wraps Stan density functions.";
    py::class_<boost::ecuyer1988>(m, "ecuyer1988").def(py::init<>());
#include "allcall_methods.hpp"
}
