//
// Created by Aleksey Leshchankin on 16.11.2022.
//

#include <iostream>
#include <fstream>
#include "CountingSingleBits.h"

template <typename T>
void runtests_type (std::string path, int number_of_tests, const T& function_name) {
    int iteration = 0;
    std::string inputPath;
    std::string outputPath;

    unsigned int num_of_moves = 0;
    unsigned long bitmask;

    std::string position;
    std::string num_of_moves_expected;
    std::string bitmask_expected;

    std::fstream inputstream;
    std::fstream outputstream;

    while (iteration < number_of_tests) {
        inputPath = path+"test."+ std::to_string(iteration)+".in";
        outputPath = path+"test."+ std::to_string(iteration)+".out";

        // ---------------------------------------
        inputstream.open(inputPath);
        getline(inputstream,position);

        outputstream.open(outputPath);
        getline(outputstream,num_of_moves_expected);
        getline(outputstream,bitmask_expected);

        // ---------------------------------------
        std::cout << "TEST " << iteration;
        std::cout << " : position = " << std::stoi(position) << std::endl;
        std::cout << "expected # of moves : " << std::stoi(num_of_moves_expected);
        std::cout << " | expected bitmask    : " << std::stoul(bitmask_expected) << std::endl;

        bitmask = function_name (std::stoi(position));
        num_of_moves = CountingSingleBits3 (bitmask);

        std:: cout << "calculated # moves  : " << num_of_moves;
        std:: cout << " | calculated bitmask  : " << bitmask << std::endl;

        if ((num_of_moves == std::stoi(num_of_moves_expected)) && (bitmask = std::stoul(bitmask_expected))) std::cout <<"PASSED\n" << std::endl;
        else std::cout <<"FAILED\n" << std::endl;

        // ---------------------------------------
        inputstream.close();
        outputstream.close();

        // ---------------------------------------
        iteration ++;
    }
}


