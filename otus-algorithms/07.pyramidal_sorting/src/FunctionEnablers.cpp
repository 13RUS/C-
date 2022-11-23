//
// Created by Aleksey Leshchankin on 22.11.2022.
//

#include "iostream"
#include "vector"

// ---------------------------------------
void PrintArray (const std::vector<int> & arrayToPrint) {
    for (const auto & value: arrayToPrint) std::cout << value << " ";
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

    for (int i = 0; i < ArraySize; i++) GeneratedArray.push_back(rand()%100);

    return GeneratedArray;
}

// ---------------------------------------
std::vector<int> GenerateArrayOrdered (int ArraySize) {
    std::vector<int> GeneratedArray;

    for (int i = 0; i < ArraySize; i++) GeneratedArray.push_back(rand()%100);
    std::sort (GeneratedArray.begin(), GeneratedArray.end());

    return GeneratedArray;
}

// ---------------------------------------
std::vector<int> GenerateArrayReversed(int ArraySize) {
    std::vector<int> GeneratedArray;

    for (int i = 0; i < ArraySize; i++) GeneratedArray.push_back(rand()%100);
    std::sort (GeneratedArray.begin(), GeneratedArray.end(),  std::greater<int>());

    return GeneratedArray;
}

