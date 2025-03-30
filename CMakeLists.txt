cmake_minimum_required(VERSION 3.10)
project(smavalue)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 20)

add_executable(smavalue main.cpp EstimateEfficiency.hpp smaValue.hpp generateOutput.hpp)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

add_executable(smatest smaTest.cpp)
target_link_libraries(smatest gtest)

add_test(NAME    smatest 
         COMMAND smatest)
