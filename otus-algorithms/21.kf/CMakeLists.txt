cmake_minimum_required(VERSION 3.21)
project(23_KF)

set(CMAKE_CXX_STANDARD 17)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(23_KF main.cpp kf.cpp)
