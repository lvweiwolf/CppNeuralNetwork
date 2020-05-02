cmake_minimum_required(VERSION 3.0.0)
project(CppNeuralNetwork)

set(APPLICATION_SOURCE ./src/hello.cpp)
SET(DLL_SOURCE ./MachineLearningLib/export.cpp)


add_library(export SHARED ${DLL_SOURCE})
add_executable(hello ${APPLICATION_SOURCE})
target_link_libraries(hello export)