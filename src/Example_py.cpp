#include <vector>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>
#include "Example.h"

/// @brief Auxiliary function used to allow a Python iterable object with char
///        elements to be passed to ExampleClass.printBuffer().
void printBuffer_py(ExampleClass& self, boost::python::object py_buffer)
{
    // `str` objects do not implement the iterator protcol (__iter__),
    // but do implement the sequence protocol (__getitem__).  Use the
    // `iter()` builtin to create an iterator for the buffer.
    // >>> __builtins__.iter(py_buffer)
    boost::python::object locals(boost::python::borrowed(PyEval_GetLocals()));
    boost::python::object py_iter = locals["__builtins__"].attr("iter");
    boost::python::stl_input_iterator<char> begin(py_iter(py_buffer)), end;

    // Copy the py_buffer into a local buffer with known continguous memory.
    std::vector<char> buffer(begin, end);

    // Cast and delegate to the printBuffer member function.
    self.printBuffer(reinterpret_cast<uint8_t*>(&buffer[0]), buffer.size());
}

BOOST_PYTHON_MODULE(example_py)
{
    boost::python::class_<ExampleClass>("ExampleClass")
    .def("printBuffer", &printBuffer_py)
    ;
}