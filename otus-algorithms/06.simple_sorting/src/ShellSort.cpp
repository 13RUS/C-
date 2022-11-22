//
// Created by Aleksey Leshchankin on 21.11.2022.
//

#include "chrono"
#include "../include/FunctionsEnablers.h"

// ---------------------------------------
void Shell (int* arrayToSort, int arrayToSort_size, unsigned long& cmp, unsigned long& asg, int& time) {
    auto start = std::chrono::high_resolution_clock::now();

    // ---------------------------------------
    cmp = 0;
    asg = 0;
    time = 0;

    for (int step = arrayToSort_size / 2; step > 0; step /= 2) {
        for (int i = step; i < arrayToSort_size; i++) {
            int j = i;
            while ( j >= step && arrayToSort[j-step] > arrayToSort[j]) {
                cmp++;
                Swap(arrayToSort[j], arrayToSort[j-step], asg);
                j -= step;
            }
        }
    }
    // ---------------------------------------

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    time = elapsed_time.count();
}

// ---------------------------------------
void ShellHSteps (int* arrayToSort, int arrayToSort_size, unsigned long& cmp, unsigned long& asg, int& time) {
    auto start = std::chrono::high_resolution_clock::now();

    // ---------------------------------------
    cmp = 0;
    asg = 0;
    time = 0;
    int step = 1;

    while (step < arrayToSort_size/3) step = 3*step + 1;

    while (step >= 1) {
        for (int i = step; i < arrayToSort_size; i++) {
            int j = i;
            while ( j >= step && arrayToSort[j-step] > arrayToSort[j]) {
                cmp++;
                Swap(arrayToSort[j], arrayToSort[j-step], asg);
                j -= step;
            }
        }
        step = step/3;
    }
    // ---------------------------------------

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    time = elapsed_time.count();
}