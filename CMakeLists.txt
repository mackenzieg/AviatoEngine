cmake_minimum_required(VERSION 3.5)
project(AviatoEngine)

set(CMAKE_BUILD_TYPE Debug)

include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)

if(COMPILER_SUPPORTS_CXX14)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
elseif(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++14 or C++11 support. Please use a different C++ compiler.")
endif()

include_directories(util)
include_directories(graphics)
include_directories(math)

set(SOURCE_FILES
        main.cpp
        util/AVI_Memory.h
        math/AVI_Math.h
        math/Vector3.h
        graphics/api/Platform.h
        graphics/Window.cpp graphics/Window.h
        graphics/api/WIN32/Win32Window.cpp graphics/api/WIN32/Win32Window.h
        graphics/api/Platform.h util/string/AVI_String8.cpp util/string/AVI_String8.h util/string/AVI_String16.cpp util/string/AVI_String16.h)

file(GLOB SOURCES "AviatoEngine/*.cpp")
file(GLOB HEADERS "AviatoEngine/*.h")

add_executable(AviatoEngine ${SOURCE_FILES})