// Rf. Makefile: 'bind' target
// clang++ -O3 -fomit-frame-pointer -Xpreprocessor -fopenmp -m64 -std=c++11   -O3 -I./core -I./modules -Wall -shared -std=c++11 -undefined dynamic_lookup `python3 -m pybind11 --includes` bind.cpp -o pyphysicell`python3-config --extension-suffix` BioFVM_vector.o BioFVM_mesh.o BioFVM_microenvironment.o BioFVM_solvers.o BioFVM_matlab.o BioFVM_utilities.o BioFVM_basic_agent.o BioFVM_MultiCellDS.o BioFVM_agent_container.o   pugixml.o PhysiCell_phenotype.o PhysiCell_cell_container.o PhysiCell_standard_models.o PhysiCell_cell.o PhysiCell_custom.o PhysiCell_utilities.o  PhysiCell_SVG.o PhysiCell_pathology.o PhysiCell_MultiCellDS.o PhysiCell_various_outputs.o PhysiCell_pugixml.o PhysiCell_settings.o heterogeneity.o  -L/usr/local/opt/libomp/lib -lomp

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include "PhysiCell_cell.h"
#include "PhysiCell_phenotype.h"
#include "PhysiCell_settings.h"
#include "heterogeneity.h"

PYBIND11_MODULE(pyphysicell, m) {

    //---------------------------------------------
    // PhysiCell-specific
    //
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

    py::class_<PhysiCell::PhysiCell_Settings>(m, "PhysiCell_Settings")
        // .def(py::init<>());
        .def_readwrite("max_time", &PhysiCell::PhysiCell_Settings::max_time)
        .def_readwrite("omp_num_threads", &PhysiCell::PhysiCell_Settings::omp_num_threads);

    m.def("get_physicell_settings", &PhysiCell::get_physicell_settings, "Get XML settings");
    // m.def("get_user_parameters", &PhysiCell::get_user_parameters, "Get XML user params");


    py::class_<PhysiCell::PhysiCell_Globals>(m, "PhysiCell_Globals")
        // .def(py::init<>());
    // double current_time = 0.0; 
	// double next_full_save_time = 0.0; 
	// double next_SVG_save_time = 0.0; 
	// int full_output_index = 0; 
	// int SVG_output_index = 0; 
        .def_readwrite("current_time", &PhysiCell::PhysiCell_Globals::current_time)
        .def_readwrite("next_SVG_save_time", &PhysiCell::PhysiCell_Globals::next_SVG_save_time);


    //py::class_<PhysiCell::Cell_Container::update_all_cells>(m, "PhysiCell_Globals")
    // 	void update_all_cells(double t);  
    // py::class_<PhysiCell::Cell_Container>(m, "Cell_Container")
        // .def("update_all_cells", &PhysiCell::Cell_Container::update_all_cells(double t), py::arg("t") );
        // .def("update_all_cells", &PhysiCell::Cell_Container::update_all_cells(double t), py::arg("t") );
        // .def("update_all_cells", &PhysiCell::Cell_Container::update_all_cells<double> );



    m.def("get_physicell_globals", &PhysiCell::get_physicell_globals, "Get global time values");
    // m.def("create_cell_container_for_microenvironment", &PhysiCell::create_cell_container_for_microenvironment, "Create container for all cells");
    m.def("create_cell_container2", &PhysiCell::create_cell_container2, "Create container for all cells");
    m.def("get_cells_pos2D", &PhysiCell::get_cells_pos2D, "Get all x,y positions of 2D cells");
    m.def("get_num_cells", &PhysiCell::get_num_cells, "Get number of cells");
    m.def("update_all_cells", &PhysiCell::update_all_cells,"Update all cells at dt_diffusion", py::arg("t") = 0.01 );


    //---------------------------------------------
    // BioFVM-specific
    //
    py::class_<BioFVM::Microenvironment>(m, "Microenvironment")
    // .def(py::init<>());
        .def("simulate_diffusion_decay", &BioFVM::Microenvironment::simulate_diffusion_decay)
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
    m.def("get_instance_microenvironment", &BioFVM::get_instance_microenvironment, "Get the default microenv");
    m.def("get_microenvironment_options", &BioFVM::get_microenvironment_options, "Get the default microenv options");

    // Custom model function (in /custom_modules) 
    m.def("create_cell_types", &create_cell_types, "Create the cell types");
    m.def("setup_tissue", &setup_tissue, "Create the cells (tissue)");
    m.def("setup_tissue1", &setup_tissue1, "Create 1 cell");

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