set(PRJ_NAME cpptest)
project(${PRJ_NAME})
cmake_minimum_required(VERSION 3.16)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)