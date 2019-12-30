// Rf. Makefile: 'bind' target
// clang++ -O3 -fomit-frame-pointer -Xpreprocessor -fopenmp -m64 -std=c++11   -O3 -I./core -I./modules -Wall -shared -std=c++11 -undefined dynamic_lookup `python3 -m pybind11 --includes` bind.cpp -o pyphysicell`python3-config --extension-suffix` BioFVM_vector.o BioFVM_mesh.o BioFVM_microenvironment.o BioFVM_solvers.o BioFVM_matlab.o BioFVM_utilities.o BioFVM_basic_agent.o BioFVM_MultiCellDS.o BioFVM_agent_container.o   pugixml.o PhysiCell_phenotype.o PhysiCell_cell_container.o PhysiCell_standard_models.o PhysiCell_cell.o PhysiCell_custom.o PhysiCell_utilities.o  PhysiCell_SVG.o PhysiCell_pathology.o PhysiCell_MultiCellDS.o PhysiCell_various_outputs.o PhysiCell_pugixml.o PhysiCell_settings.o heterogeneity.o  -L/usr/local/opt/libomp/lib -lomp

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include "PhysiCell_cell.h"
#include "PhysiCell_phenotype.h"
#include "PhysiCell_settings.h"

PYBIND11_MODULE(pyphysicell, m) {
    // m.doc() = "pybind11 pcell plugin"; // optional module docstring
    py::class_<PhysiCell::Cell_Definition>(m, "Cell_Definition")
        .def(py::init<const std::string &>())
        // .def("setName", &Cell_Definition::setName)
        .def("getName", &PhysiCell::Cell_Definition::getName);
    py::class_<PhysiCell::Cell_Functions>(m, "Cell_Functions").def(py::init<>());
    // py::class_<PhysiCell::Cell_Functions>(m, "Cell_Functions")
        // .def("getName", &PhysiCell::Cell_Function::getName);
        // .def(py::init<const std::string &>())
        // .def("setName", &Cell_Definition::setName)
        // .def("getName", &PhysiCell::Cell_Definition::getName);

    py::class_<BioFVM::Microenvironment>(m, "Microenvironment")
    // .def(py::init<>());
        .def_readwrite("decay_rates", &BioFVM::Microenvironment::decay_rates);

    py::class_<BioFVM::Microenvironment_Options>(m, "Microenvironment_Options")
    // .def(py::init<>());
        .def_readwrite("simulate_2D", &BioFVM::Microenvironment_Options::simulate_2D);

    // py::class_<BioFVM::Microenvironment>(m, "Microenvironment")
    //     .def_static("__new__", [](py::object) { return BioFVM::Microenvironment::instance(); )},
    //     py::return_value_policy::reference_internal);

    // py::class_<BioFVM::Microenvironment>(mod, "Single").def(py::init<>());
    // py::class_<CppSingle>(mod, "Single")

    m.def("initialize_microenvironment", &BioFVM::initialize_microenvironment, "Initialize the microenv");
    m.def("get_microenvironment", &BioFVM::get_microenvironment, "Get the default microenv");
    m.def("get_microenvironment_options", &BioFVM::get_microenvironment_options, "Get the default microenv options");

    // m.def_property("microenvironment", 
        // []() {return BioFVM::microenvironment; });

    // m.def("add", &add, "A function which adds two numbers");
    m.def("load_PhysiCell_config_file", &PhysiCell::load_PhysiCell_config_file, "Load config params from XML");
}

// py::class_<Cell_Definition>(m, "Cell_Definition")
//     .def(py::init<const std::string &>())
//     .def_property("name", &Cell_Definition::getName, &Cell_Definition::setName)
    // ... remainder ...

// int add(int i, int j) {
//     return i + j;
// }