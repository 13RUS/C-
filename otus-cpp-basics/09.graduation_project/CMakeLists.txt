cmake_minimum_required(VERSION 3.21)
project(09_graduation_project)
set(CMAKE_CXX_STANDARD 17)

add_executable(09_graduation_project main.cpp)

find_package(OpenCV REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS} )

target_link_libraries(09_graduation_project  ${OpenCV_LIBS})