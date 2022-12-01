cmake_minimum_required(VERSION 3.21)
project(09_linear_sorting)

set(CMAKE_CXX_STANDARD 17)

add_executable(09_linear_sorting main.cpp
        src/FunctionEnablers.cpp
        src/CountingSort.cpp
        src/RadixSort.cpp
        src/BucketSort.cpp)
