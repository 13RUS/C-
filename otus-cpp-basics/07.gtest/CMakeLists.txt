cmake_minimum_required(VERSION 3.2)

project(ProjectWithGTest)

# Lookup for pre-built gtest
find_package(GTest)

# Main target
add_executable(
    demo
    src/main.cpp
    src/list.hpp
    src/vector.hpp
)

# Test target list
add_executable(
    test_list
    test/test_list.cpp
)

# Test target vector
add_executable(
    test_vector
    test/test_vector.cpp
)

set_target_properties(
        demo
        test_list
        test_vector

        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

# Add src to the include directories for the test target
target_include_directories(
    test_list PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
target_include_directories(
    test_vector PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Add googletest to the include directories for the test target
target_include_directories(
    test_list PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_include_directories(
   test_vector PRIVATE
   ${GTEST_INCLUDE_DIRS}
)

# Link test target against gtest libraries
target_link_libraries(
    test_list PRIVATE
    ${GTEST_BOTH_LIBRARIES}
)

target_link_libraries(
     test_vector PRIVATE
     ${GTEST_BOTH_LIBRARIES}
)

if (MSVC)
    target_compile_options(
        demo PRIVATE
        /W4
    )
    target_compile_options(
        test_list PRIVATE
        /W4
    )
    target_compile_options(
        test_vector PRIVATE
        /W4
    )
else ()
    target_compile_options(
        demo PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
        test_list PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
         test_vector PRIVATE
        -Wall -Wextra -pedantic -Werror
    )

endif()

