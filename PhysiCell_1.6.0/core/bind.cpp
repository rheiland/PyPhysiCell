// c++ -O3 -Wall -shared -std=c++11 -undefined dynamic_lookup `python3 -m pybind11 --includes` bind.cpp -o bind`python3-config --extension-suffix`

#include <pybind11/pybind11.h>

namespace py = pybind11;

#include "PhysiCell_cell.h"

PYBIND11_MODULE(bind, m) {
    // m.doc() = "pybind11 pcell plugin"; // optional module docstring
    py::class_<PhysiCell::Cell_Definition>(m, "Cell_Definition")
        .def(py::init<const std::string &>())
        // .def("setName", &Cell_Definition::setName)
        .def("getName", &PhysiCell::Cell_Definition::getName);

    // m.def("add", &add, "A function which adds two numbers");
}

// py::class_<Cell_Definition>(m, "Cell_Definition")
//     .def(py::init<const std::string &>())
//     .def_property("name", &Cell_Definition::getName, &Cell_Definition::setName)
    // ... remainder ...

// int add(int i, int j) {
//     return i + j;
// }