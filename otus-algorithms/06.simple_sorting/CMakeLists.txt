cmake_minimum_required(VERSION 3.21)
project(06_sorting)

set(CMAKE_CXX_STANDARD 17)

add_executable(06_sorting
        main.cpp
        src/BubbleSort.cpp
        src/InsertionSort.cpp
        src/ShellSort.cpp
        src/FunctionEnablers.cpp)
