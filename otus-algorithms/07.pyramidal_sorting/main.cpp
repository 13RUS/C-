#include <iostream>

#include "include/FunctionsFile.h"
#include "include/FunctionsEnablers.h"
#include "include/FunctionsTesting.h"

#include "include/SelectionSort.h"
#include "include/HeapSort.h"

// ---------------------------------------
int main() {

    std::string path;
    std::string AlgorythmName;
    path = "../sorting-tests/0.random/";

    std::cout << "\n// -------------- Selection Random ------------------- ";
    path = "../sorting-tests/0.random/";
    RunCorrectnessTestFromFile(SelectionSort, path,5, "Selection");
    std::cout << "\n// -------------- Selection Digits ------------------- ";
    path = "../sorting-tests/1.digits/";
    RunCorrectnessTestFromFile(SelectionSort, path,5,"Selection");
    std::cout << "\n// -------------- Selection Sorted ------------------- ";
    path = "../sorting-tests/2.sorted/";
    RunCorrectnessTestFromFile(SelectionSort, path,5,"Selection");
    std::cout << "\n// -------------- Selection Revers ------------------- ";
    path = "../sorting-tests/3.revers/";
    RunCorrectnessTestFromFile(SelectionSort, path,5,"Selection");

    std::cout << "\n// -------------- Heap Random ------------------------ ";
    path = "../sorting-tests/0.random/";
    RunCorrectnessTestFromFile(HeapSort, path, 8, "Heap");
    std::cout << "\n// -------------- Heap Digits ------------------------ ";
    path = "../sorting-tests/1.digits/";
    RunCorrectnessTestFromFile(HeapSort, path, 8, "Heap");
    std::cout << "\n// -------------- Heap Sorted ------------------------ ";
    path = "../sorting-tests/2.sorted/";
    RunCorrectnessTestFromFile(HeapSort, path, 8, "Heap");
    std::cout << "\n// -------------- Heap Revers ------------------------ ";
    path = "../sorting-tests/3.revers/";
    RunCorrectnessTestFromFile(HeapSort, path, 8, "Heap");

}
