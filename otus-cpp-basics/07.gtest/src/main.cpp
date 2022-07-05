#include "list.hpp"
#include "vector.hpp"

#include <iostream>

int main(int, char**) {
    std::cout << "Hello from Global Main" << std::endl;
    std::cout << "Vector Testing" << std::endl;

    homeworkspace::Vector<size_t> vector;
    size_t count_test = 10;

    for (size_t i = 0; i < count_test; ++i) {
        vector.push_back(i);
    }

    vector.pop_middle();

    for (size_t i = 0; i < count_test-1 ; ++i) {
        std::cout << vector.front() << ' ';
        vector.pop_front();
    }

    //std::cout << "\n vector size = " << vector.size();
    //std::cout << "\n vector size typedef = " << typeid(int(vector.size())).name();

    /*
     size_t count_test = 10;
     homeworkspace::List<size_t> list;

     for (size_t i = 0; i < count_test; ++i) {
        list.push_back(i);}

       for (size_t i = 0; i < count; ++i) {
           list.push_back(i);
           list.push_front(i);
       }

       for (size_t i = 0; i < count * 2; ++i) {
           std::cout << list.front() << ' ';
           list.pop_front();
       }
    */
     return 0;
}