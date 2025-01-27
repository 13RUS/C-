//
// Created by Aleksey Leshchankin on 19.11.2022.
//

#pragma once

#include "cctype"

// --------------------------------------
template <typename T>
void RunCorrectnessTest (const T& function_name) {

    int array_size = 0;
    unsigned long numOfComparison = 0;
    unsigned long numOfAssignment = 0;
    int time = 0;

    std::cout << "\n--  VALIDATION  --";
    auto array = GenerateArrayRandom(15);
    std::cout << "\narray Random   : "; PrintArray(array);
    function_name(array.data(), array.size(), numOfComparison, numOfAssignment, time);
    std::cout << "\narray sorted   : ";  PrintArray(array); std::cout << std::endl;

    array = GenerateArrayOrdered(15);
    std::cout << "\narray Ordered  : "; PrintArray(array);
    function_name(array.data(), array.size(), numOfComparison, numOfAssignment, time);
    std::cout << "\narray sorted   : ";  PrintArray(array); std::cout << std::endl;

    array = GenerateArrayReversed(15);
    std::cout << "\narray Reversed : "; PrintArray(array);
    function_name(array.data(), array.size(), numOfComparison, numOfAssignment, time);
    std::cout << "\narray sorted   : ";  PrintArray(array); std::cout << std::endl;
}

// --------------------------------------
template <typename T>
void RunCorrectnessTest (const T& function_name, int isQuickOrMergerSortAlgorithm) {

    int array_size = 0;
    unsigned long numOfComparison = 0;
    unsigned long numOfAssignment = 0;
    int time = 0;

    std::cout << "\n--  VALIDATION  --";

        auto array = GenerateArrayRandom(15);
        std::cout << "\narray Random   : "; PrintArray(array);
        function_name(array.data(), 0, array.size() - 1, numOfComparison, numOfAssignment, time);
        std::cout << "\narray sorted   : ";  PrintArray(array); std::cout << std::endl;

        array = GenerateArrayOrdered(15);
        std::cout << "\narray Ordered  : "; PrintArray(array);
        function_name(array.data(), 0, array.size() - 1, numOfComparison, numOfAssignment, time);
        std::cout << "\narray sorted   : ";  PrintArray(array); std::cout << std::endl;

        array = GenerateArrayReversed(15);
        std::cout << "\narray Reversed : "; PrintArray(array);
        function_name(array.data(), 0, array.size() - 1, numOfComparison, numOfAssignment, time);
        std::cout << "\narray sorted   : ";  PrintArray(array); std::cout << std::endl;

}

// --------------------------------------
template <typename T>
void RunCorrectnessTestFromFile (const T& function_name, std::string path, int amountOfTestFiles, std::string AlgorythmName) {

    int array_size = 0;
    unsigned long numOfComparison = 0;
    unsigned long numOfAssignment = 0;
    int time = 0;
    std::string FileNameToWriteIn;

    for (int i = 0; i <= amountOfTestFiles-1; i++) {
        auto array = ReadArray(path, i);
        //std::cout << "\narray : "; PrintArray(array);
        function_name(array.data(), array.size(), numOfComparison, numOfAssignment, time);
        //std::cout << "\narray sorted   : "; PrintArray(array);
        std::cout << "\narray size : " << array.size() <<" comparisons : " << numOfAssignment <<" assignments : " << numOfComparison << " time : " << time;
        FileNameToWriteIn = "../sorting-tests-result/" + AlgorythmName + std::to_string(i) + ".out";
        WritingToFile(array,FileNameToWriteIn);
    }
}

// --------------------------------------
template <typename T>
void RunCorrectnessTestFromFile (const T& function_name, std::string path, int isQuickOrMergerSortAlgorithm, int amountOfTestFiles, std::string AlgorythmName) {

    int array_size = 0;
    unsigned long numOfComparison = 0;
    unsigned long numOfAssignment = 0;
    int time = 0;
    std::string FileNameToWriteIn;

    //amountOfTestFiles = 3;

    for (int i = 0; i <= amountOfTestFiles-1; i++) {
        auto array = ReadArray(path, i);
        //std::cout << "\narray : "; PrintArray(array);
        function_name(array.data(), 0, array.size() - 1, numOfComparison, numOfAssignment, time);
        //std::cout << "\narray sorted   : "; PrintArray(array);
        std::cout << "\narray size : " << array.size() <<" comparisons : " << numOfAssignment <<" assignments : " << numOfComparison << " time : " << time;
        FileNameToWriteIn = "../sorting-tests-result/" + AlgorythmName + std::to_string(i) + ".out";
        WritingToFile(array,FileNameToWriteIn);
    }
}

// --------------------------------------
template <typename T>
void RunTimeEstimation (const T& function_name, unsigned int limit) {

    int array_size = 0;
    unsigned long numOfComparison = 0;
    unsigned long numOfAssignment = 0;
    int time = 0;

    std::cout << "\n--  TIME ESTIMATION  --";
    std::cout << "\n--  Random array  --" << std::endl;
    for (int i = 10; i <=limit; i=i*10) {
        auto array = GenerateArrayRandom(i);
        function_name(array.data(), array.size(), numOfComparison, numOfAssignment, time);
        std::cout << "array size : " << array.size() <<" comparisons : " << numOfAssignment <<" assignments : " << numOfComparison << " time : " << time << std::endl;
    }

    std::cout << "\n--  Ordered array  --" << std::endl;
    for (int i = 10; i <=limit; i=i*10) {
        auto array = GenerateArrayOrdered(i);
        function_name(array.data(), array.size(), numOfComparison, numOfAssignment, time);
        std::cout << "array size : " << array.size() <<" comparisons : " << numOfAssignment <<" assignments : " << numOfComparison << " time : " << time << std::endl;
    }

    std::cout << "\n--  Reversed array  --" << std::endl;
    for (int i = 10; i <=limit; i=i*10) {
        auto array = GenerateArrayReversed(i);
        function_name(array.data(), array.size(), numOfComparison, numOfAssignment, time);
        std::cout << "array size : " << array.size() <<" comparisons : " << numOfAssignment <<" assignments : " << numOfComparison << " time : " << time << std::endl;
    }
}