cmake_minimum_required(VERSION 3.21)
project(03_check_value)

set(CMAKE_CXX_STANDARD 17)

add_executable(03_check_value
        main.cpp
        target_value_generator.cpp
        target_value_generator.h
        write_new_high_score.cpp
        write_new_high_score.h
        read_the_high_score_file.cpp
        read_the_high_score_file.h)
