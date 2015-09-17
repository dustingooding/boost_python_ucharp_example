#include <boost/python.hpp>
#include "Example.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(example_py)
{
    class_<ExampleClass>("ExampleClass")
    .def("printBuffer", &ExampleClass::printBuffer)
    ;
}
