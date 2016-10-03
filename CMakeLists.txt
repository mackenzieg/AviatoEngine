cmake_minimum_required(VERSION 3.5)
project(AviatoEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp util/String16.cpp util/String16.h math/Vector3.h)
add_executable(AviatoEngine ${SOURCE_FILES})