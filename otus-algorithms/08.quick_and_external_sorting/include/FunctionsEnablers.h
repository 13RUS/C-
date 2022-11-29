//
// Created by Aleksey Leshchankin on 18.11.2022.
//

#pragma once

#include "iostream"
#include "vector"

void PrintArray (const std::vector<int> & arrayToPrint);
void PrintArray (int array[], int size);
void Swap (int& x, int& y, unsigned long& asg);
int BinarySearch (int key, int low, int high, int* arrayToSort, unsigned long& cmp);

std::vector<int> GenerateArrayRandom (int ArraySize);
std::vector<int> GenerateArrayOrdered (int ArraySize);
std::vector<int> GenerateArrayReversed(int ArraySize);
