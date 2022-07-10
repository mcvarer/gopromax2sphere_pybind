cmake_minimum_required(VERSION 3.8)
project(maxsphere)

set(CMAKE_CXX_STANDARD 17)


find_package(PythonInterp REQUIRED)
find_package(PythonLibs "${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}" REQUIRED )
if (PYTHONLIBS_FOUND)
    include_directories(${PYTHON_INCLUDE_DIRS})
    message("Using default python version: " ${PYTHONLIBS_VERSION_STRING})
endif()


add_subdirectory(external/pybind11)
include_directories(SYSTEM external/pybind11/include)
include_directories(SYSTEM external/eigen)
file(GLOB_RECURSE SOURCES src/**.c)
add_library(maxsphere_library STATIC ${SOURCES})
set_property(TARGET maxsphere_library PROPERTY POSITION_INDEPENDENT_CODE ON)
target_include_directories(maxsphere_library PUBLIC ./include)


add_subdirectory(maxsphere)