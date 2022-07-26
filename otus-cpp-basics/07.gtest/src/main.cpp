#include "list.hpp"
#include "vector.hpp"

#include <iostream>

int main(int, char**) {
    std::cout << "Hello from Global Main" << std::endl;
    std::cout << "Vector Testing" << std::endl;

    homeworkspace::Vector<size_t> vector;
    size_t count = 10;

    for (size_t i = 0; i < count; ++i) {
        vector.push_back(i);
    }

    for (size_t i = 0; i < count; ++i) {
        std::cout << vector[i] << ' ';
    }

     return 0;
}