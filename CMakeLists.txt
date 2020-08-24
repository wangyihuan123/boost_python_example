cmake_minimum_required(VERSION 3.5)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

project(test)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-std=c++11 -ggdb -O3)

find_package( OpenCV REQUIRED )

find_package(PythonLibs 2.7 REQUIRED)
find_package(PythonInterp REQUIRED)
find_package(Boost COMPONENTS python REQUIRED)


include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(/usr/local/lib/python2.7/dist-packages/numpy/core/include/)


FILE(GLOB PYTHON_SOURCE_LIST
        conversion.cpp
        conversion.h
        pyTest.cpp)


set(PythonMODULE pyTest)
python_add_module(${PythonMODULE} ${PYTHON_SOURCE_LIST})

target_link_libraries(${PythonMODULE}
        boost_python
        ${PYTHON_LIBRARIES}
        ${Boost_LIBRARIES}
        ${OpenCV_LIBS})