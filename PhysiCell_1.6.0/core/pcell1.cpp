// c++ -O3 -Wall -shared -std=c++11 -undefined dynamic_lookup `python3 -m pybind11 --includes` pcell1.cpp -o pcell1`python3-config --extension-suffix`

#include <pybind11/pybind11.h>

namespace py = pybind11;

class Cell_Definition
{
 private:
 public: 
	int type; 
	std::string name; 
 
	// Microenvironment* pMicroenvironment; 
	
	// Cell_Parameters parameters; 
	// Custom_Cell_Data custom_data; 
	// Cell_Functions functions; 
	// Phenotype phenotype; 

	// Cell_Definition();  // done 

	Cell_Definition(const std::string &name) : name(name) { }
    // void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }
	// Cell_Definition( Cell_Definition& cd ); // copy constructor 
	// Cell_Definition& operator=( const Cell_Definition& cd ); // copy assignment 
};


PYBIND11_MODULE(pcell1, m) {
    // m.doc() = "pybind11 pcell plugin"; // optional module docstring
    py::class_<Cell_Definition>(m, "Cell_Definition")
        .def(py::init<const std::string &>())
        // .def("setName", &Cell_Definition::setName)
        .def("getName", &Cell_Definition::getName);

    // m.def("add", &add, "A function which adds two numbers");
}

// py::class_<Cell_Definition>(m, "Cell_Definition")
//     .def(py::init<const std::string &>())
//     .def_property("name", &Cell_Definition::getName, &Cell_Definition::setName)
    // ... remainder ...

// int add(int i, int j) {
//     return i + j;
// }