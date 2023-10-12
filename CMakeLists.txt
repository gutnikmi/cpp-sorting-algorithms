cmake_minimum_required(VERSION 3.26)
project(cpp_sorting_algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cpp_sorting_algorithms
        main.cpp
        Sort.cpp
        Sort.h)
