#include "maxsphere_library/sublib/MAX2spherebatch.h"

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>


namespace py = pybind11;

PYBIND11_MODULE(_core, m)
{
  auto sublib = m.def_submodule("sublib");
  sublib.def("max2sphere", CheckFrames);
}