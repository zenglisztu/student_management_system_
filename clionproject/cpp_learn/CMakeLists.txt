cmake_minimum_required(VERSION 3.25)
project(cpp_learn)

set(CMAKE_CXX_STANDARD 11)

find_package(PythonInterp REQUIRED)
find_package(PythonLibs REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})

add_executable(cpp_learn cpp_call_py2.cpp)

target_link_libraries(cpp_learn ${PYTHON_LIBRARIES})
