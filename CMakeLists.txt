cmake_minimum_required(VERSION 3.5)
project(AviatoEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(util)
include_directories(graphics)
include_directories(math)

set(SOURCE_FILES
        main.cpp
        util/String16.cpp util/String16.h
        util/Memory.h
        math/AVI_Math.h
        math/Vector3.h
        graphics/api/Platform.h
        graphics/Window.cpp graphics/Window.h)

add_executable(AviatoEngine ${SOURCE_FILES})