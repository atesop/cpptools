cmake_minimum_required(VERSION 3.3)
project(tools)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES test.cpp)
add_executable(tools ${SOURCE_FILES})