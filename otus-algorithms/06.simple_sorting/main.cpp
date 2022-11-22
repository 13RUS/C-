#include <iostream>
#include "vector"

#include "include/FunctionsFile.h"
#include "include/FunctionsEnablers.h"
#include "include/FunctionsTesting.h"

#include "include/BubbleSort.h"
#include "include/InsertionSort.h"
#include "include/ShellSort.h"

// ---------------------------------------
int main() {

    /*std::string path;
    path = "../TestArrays/";
    auto v = ReadArray (path);
    std::cout << "\narray from file : "; PrintArray(v);
    WritingToFile(v, path+"Bubble.out");*/

    std::cout << "\n// -------------- Bubble -------------------------- ";
    RunCorrectnessTest(Bubble);
    std::cout << "\n// -------------- Insertion ----------------------- ";
    RunCorrectnessTest(Insertion);
    std::cout << "\n// -------------- Insertion Shift ------------------ ";
    RunCorrectnessTest(InsertionShift);
    std::cout << "\n// -------------- Insertion Binary Search ---------- ";
    RunCorrectnessTest(InsertionBinarySearch);
    std::cout << "\n// -------------- Shell ---------------------------- ";
    RunCorrectnessTest(Shell);
    std::cout << "\n// -------------- Shell Optimized Steps ------------ ";
    RunCorrectnessTest(ShellHSteps);

    std::cout << "\n// -------------- Bubble --------------------------- ";
    RunTimeEstimation(Bubble,               100000);
    std::cout << "\n// -------------- Insertion ------------------------ ";
    RunTimeEstimation(Insertion,            100000);
    std::cout << "\n// -------------- Insertion Shift ------------------ ";
    RunTimeEstimation(InsertionShift,       100000);
    std::cout << "\n// -------------- Insertion Binary Search ---------- ";
    RunTimeEstimation(InsertionBinarySearch,100000);
    std::cout << "\n// -------------- Shell ---------------------------- ";
    RunTimeEstimation(Shell,                10000000);
    std::cout << "\n// -------------- Shell Optimized Steps ------------ ";
    RunTimeEstimation(ShellHSteps,          10000000);

    return 0;
}
