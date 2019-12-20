// ~/git/PyPhysiCell$ c++ -O3 -Wall -shared -std=c++11 -undefined dynamic_lookup `python3 -m pybind11 --includes` animal.cpp -o example`python3-config --extension-suffix`
// ~/git/PyPhysiCell$ python
// Python 3.6.5 |Anaconda, Inc.| (default, Apr 26 2018, 08:42:37) 
// [GCC 4.2.1 Compatible Clang 4.0.1 (tags/RELEASE_401/final)] on darwin
// Type "help", "copyright", "credits" or "license" for more information.
// >>> import example
// >>> dir(example)
// ['Animal', 'Dog', '__doc__', '__file__', '__loader__', '__name__', '__package__', '__spec__', 'call_go']
// >>> 


#include <pybind11/pybind11.h>

namespace py = pybind11;

class Animal {
public:
    virtual ~Animal() { }
    virtual std::string go(int n_times) = 0;
};

class Dog : public Animal {
public:
    std::string go(int n_times) override {
        std::string result;
        for (int i=0; i<n_times; ++i)
            result += "woof! ";
        return result;
    }
};

std::string call_go(Animal *animal) {
    return animal->go(3);
}

PYBIND11_MODULE(example, m) {
    py::class_<Animal>(m, "Animal")
        .def("go", &Animal::go);

    py::class_<Dog, Animal>(m, "Dog")
        .def(py::init<>());

    m.def("call_go", &call_go);
}

