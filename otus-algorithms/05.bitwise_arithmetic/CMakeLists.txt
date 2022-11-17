cmake_minimum_required(VERSION 3.21)
project(05_bitwise_arithmetic)

set(CMAKE_CXX_STANDARD 17)

add_executable(05_bitwise_arithmetic
        main.cpp)

target_include_directories(05_bitwise_arithmetic
        PUBLIC
        include)