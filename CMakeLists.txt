cmake_minimum_required(VERSION 3.6)
project(AviatoEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(util)
include_directories(graphics)
include_directories(math)

set(SOURCE_FILES
        main.cpp
        util/AVI_String.cpp util/AVI_String.h
        util/AVI_WString.cpp util/AVI_WString.h
        util/AVI_Memory.h
        math/AVI_Math.h
        math/Vector3.h
        graphics/api/Platform.h
        graphics/Window.cpp graphics/Window.h)

add_executable(AviatoEngine ${SOURCE_FILES})