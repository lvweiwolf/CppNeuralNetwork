cmake_minimum_required(VERSION 3.0.0)
project(CppNeuralNetwork)

set(APPLICATION_SOURCE ./src/hello.cpp)
set(ML_SOURCE ./MachineLearningLib/export.cpp)

# 头文件路径
set(openBLAS_INC_DIR openBLAS/include)
# lib库路径
set(openBLAS_LINK_DIR openBLAS/lib)

# 头文件
include_directories(${openBLAS_INC_DIR})
link_directories(${openBLAS_LINK_DIR})
link_libraries(openblas)

add_library(export SHARED ${ML_SOURCE})
add_executable(hello ${APPLICATION_SOURCE})
# 链接openBLAS
target_link_libraries(hello export)