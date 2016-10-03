cmake_minimum_required(VERSION 3.6)
project(AviatoEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp math/Vector3.cpp math/Vector3.h)
add_executable(AviatoEngine ${SOURCE_FILES})