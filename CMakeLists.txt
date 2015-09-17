cmake_minimum_required(VERSION 2.8)
project(boost_python_ucharp_example)

find_package(Boost REQUIRED COMPONENTS python)
find_package(PythonLibs REQUIRED)

include_directories(
    include
    ${Boost_INCLUDE_DIRS}
    ${PYTHON_INCLUDE_DIRS}
)

add_library(example_py SHARED
    src/Example_py.cpp
)
target_link_libraries(example_py ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
set_target_properties(example_py PROPERTIES PREFIX "")

add_executable(example src/example.cpp)
target_link_libraries(example example_py)
