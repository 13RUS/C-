#include <iostream>

#include "include/FunctionsFile.h"
#include "include/FunctionsEnablers.h"
#include "include/FunctionsTesting.h"

#include "include/QuickSort.h"
#include "include/MergerSort.h"

int main() {

    std::string path;
    std::string AlgorythmName;
    path = "../sorting-tests/0.random/";

/*  std::cout << "\n// -------------- QuickSort ----------------------- ";
    RunCorrectnessTest(QuickSort, 1);
    std::cout << "\n// -------------- MergerSort ---------------------- ";
    RunCorrectnessTest(MergeSort, 2);
*/
    std::cout << "\n// -------------- QuickSort Random ------------------- ";
    path = "../sorting-tests/0.random/";
    RunCorrectnessTestFromFile(QuickSort, path, 1, 6, "QuickSort");
    std::cout << "\n// -------------- QuickSort Digits ------------------- ";
    path = "../sorting-tests/1.digits/";
    RunCorrectnessTestFromFile(QuickSort, path, 1, 6, "QuickSort");
    std::cout << "\n// -------------- QuickSort Sorted ------------------- ";
    path = "../sorting-tests/2.sorted/";
    RunCorrectnessTestFromFile(QuickSort, path, 1, 6, "QuickSort");
    std::cout << "\n// -------------- QuickSort Revers ------------------- ";
    path = "../sorting-tests/3.revers/";
    RunCorrectnessTestFromFile(QuickSort, path, 1, 5, "QuickSort");

    std::cout << "\n// -------------- MergeSort Random ------------------- ";
    path = "../sorting-tests/0.random/";
    RunCorrectnessTestFromFile(MergeSort, path, 1, 6, "MergeSort");
    std::cout << "\n// -------------- MergeSort Digits ------------------- ";
    path = "../sorting-tests/1.digits/";
    RunCorrectnessTestFromFile(MergeSort, path, 1, 7, "MergeSort");
    std::cout << "\n// -------------- MergeSort Sorted ------------------- ";
    path = "../sorting-tests/2.sorted/";
    RunCorrectnessTestFromFile(MergeSort, path, 1, 7, "MergeSort");
    std::cout << "\n// -------------- MergeSort Revers ------------------- ";
    path = "../sorting-tests/3.revers/";
    RunCorrectnessTestFromFile(MergeSort, path, 1, 7, "MergeSort");

    return 0;
}
