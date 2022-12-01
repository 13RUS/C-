//
// Created by Aleksey Leshchankin on 22.11.2022.
//

#include "iostream"
#include "vector"
#include "../include/CountingSort.h"

// --------------------------------------
int getMaxElement (int Array[], int ArraySize) {
    int maxElement = Array[0];

    for (int i = 1; i < ArraySize; i++) {
        if (Array[i] > maxElement)
            maxElement = Array[i];
    }
    return maxElement;
}

// --------------------------------------
int getMinElement (int Array[], int ArraySize) {
    int minElement = Array[0];

    for (int i = 1; i < ArraySize; i++) {
        if (Array[i] < minElement)
            minElement = Array[i];
    }
    return minElement;
}

// ---------------------------------------
void PrintArray (const std::vector<int> & arrayToPrint) {
    for (const auto & value: arrayToPrint) std::cout << value << " ";
}

// ---------------------------------------
void PrintArray(int* array, int size) {
    int i;
    for (i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

// ---------------------------------------
void Swap (int& x, int& y, unsigned long& asg) {
    int temp = x;
    x = y;
    y = temp;
    asg += 3;
}

// ---------------------------------------
int BinarySearch (int key, int low, int high, int* arrayToSort, unsigned long& cmp) {
    int middle;
    if (high <= low) {
        if (key > arrayToSort[low])
            return low + 1;
        else
            return low;
    }
    middle = (low + high) / 2;

    cmp++;

    if (key > arrayToSort[middle])
        return BinarySearch(key, middle+1, high, arrayToSort, cmp);
    else
        return BinarySearch(key, low, middle-1, arrayToSort, cmp);
}

// ---------------------------------------
std::vector<int> GenerateArrayRandom (int ArraySize) {
    std::vector<int> GeneratedArray;

    for (int i = 0; i < ArraySize; i++) GeneratedArray.push_back(rand()%500);

    return GeneratedArray;
}

// ---------------------------------------
std::vector<int> GenerateArrayOrdered (int ArraySize) {
    std::vector<int> GeneratedArray;

    for (int i = 0; i < ArraySize; i++) GeneratedArray.push_back(rand()%500);
    std::sort (GeneratedArray.begin(), GeneratedArray.end());

    return GeneratedArray;
}

// ---------------------------------------
std::vector<int> GenerateArrayReversed(int ArraySize) {
    std::vector<int> GeneratedArray;

    for (int i = 0; i < ArraySize; i++) GeneratedArray.push_back(rand()%500);
    std::sort (GeneratedArray.begin(), GeneratedArray.end(),  std::greater<int>());

    return GeneratedArray;
}

// ---------------------------------------
int* GenerateArraysIncremental (int* array, int ArraySize) {
    for (int i = 0; i < ArraySize; i++)
        array[i] = rand()%1000;
    return array;
}
