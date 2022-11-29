cmake_minimum_required(VERSION 3.21)
project(08_quick_and_external_sorting)

set(CMAKE_CXX_STANDARD 17)

add_executable(08_quick_and_external_sorting
        main.cpp
        src/FunctionEnablers.cpp
        src/QuickSort.cpp
        src/MergerSort.cpp)
