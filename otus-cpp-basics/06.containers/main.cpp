#include <iostream>
#include "Sequential_Container.h"
#include "List_Container.h"

//-------------------------------------------------------
int main() {

    // variables for testing
    unsigned int inserted_value, inserted_position;
    int erase_position, extract_position;

    //-- LIST CONTAINER RELATED --
    std::cout << "** List Container Testing **" << std::endl;
    List_Container <int> test_class_list;

    std::cout << "Container elements         : ";
    for (unsigned int i = 0; i < 10; i ++) {test_class_list.push_back(i);}
    test_class_list.print_container();

    std::cout << "Container size: " << test_class_list.size() << std::endl;

    inserted_value = 10;
    inserted_position = 1;
    std::cout << "Insert " << inserted_value << " at the beginning : ";
    test_class_list.insert(inserted_value, inserted_position);
    test_class_list.print_container();

    inserted_value = 20;
    std::cout << "Insert " << inserted_value << " at the middle    : ";
    test_class_list.insert(inserted_value, test_class_list.size()/2+1);
    test_class_list.print_container();

    inserted_value = 30;
    std::cout << "Insert " << inserted_value << " at the end       : ";
    test_class_list.push_back(30);
    test_class_list.print_container();


    erase_position = 3;
    std::cout << "Remove " << erase_position << " element           : ";
    test_class_list.erase (erase_position);
    test_class_list.print_container();

    erase_position = -33;
    std::cout << "Remove from " << erase_position << " position   : ";
    test_class_list.erase (erase_position);

    std::cout << "Container elements         : ";
    test_class_list.print_container();

    extract_position = 7;
    std::cout << "Extract " << extract_position << " element using [] : " << test_class_list[extract_position] << std::endl;

    extract_position = 3;
    std::cout << "Extract " << extract_position << " element using get() : " << test_class_list.getelement(extract_position) << std::endl;

    //-- SEQUENTIAL CONTAINER RELATED --
    std::cout << "\n** Sequential Container Testing **" << std::endl;
    Sequential_Container <int> test_class_sequential;

    for (unsigned int i = 0; i < 10; i ++) {test_class_sequential.push_back(i);}
    std::cout << "Container elements         : ";
    test_class_sequential.print_container();

    std::cout << "Container size: " << test_class_sequential.size() << std::endl;

    inserted_value = 10;
    inserted_position = 1;
    std::cout << "Insert " << inserted_value << " at the beginning : ";
    test_class_sequential.insert(inserted_value, inserted_position);
    test_class_sequential.print_container();

    inserted_value = 20;
    std::cout << "Insert " << inserted_value << " at the middle    : ";
    test_class_sequential.insert(inserted_value, test_class_sequential.size()/2+1);
    test_class_sequential.print_container();

    inserted_value = 30;
    std::cout << "Insert " << inserted_value << " at the end       : ";
    test_class_sequential.push_back(30);
    test_class_sequential.print_container();

    std::cout << "Remove elements №№3, 5, 7  : ";
    test_class_sequential.erase_three_values(3,5,7);
    test_class_sequential.print_container();

    erase_position = 3;
    std::cout << "Remove " << erase_position << " element           : ";
    test_class_sequential.erase (erase_position);
    test_class_sequential.print_container();

    erase_position = -33;
    std::cout << "Remove from " << erase_position << " position   : ";
    test_class_sequential.erase (erase_position);

    std::cout << "Container elements         : ";
    test_class_sequential.print_container();

    return 0;
}
