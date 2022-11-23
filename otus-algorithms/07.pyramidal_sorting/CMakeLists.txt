cmake_minimum_required(VERSION 3.21)
project(07_pyramidal_sorting)

set(CMAKE_CXX_STANDARD 17)

add_executable(07_pyramidal_sorting
        main.cpp
        src/FunctionEnablers.cpp
        src/SelectionSort.cpp
        src/HeapSort.cpp)
