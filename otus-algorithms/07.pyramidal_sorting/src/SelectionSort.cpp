//
// Created by Aleksey Leshchankin on 22.11.2022.
//
#include "chrono"
#include "../include/FunctionsEnablers.h"

// ---------------------------------------
void SelectionSort (int* arrayToSort, int arrayToSort_size, unsigned long& cmp, unsigned long& asg, int& time) {
    auto start = std::chrono::high_resolution_clock::now();

    // ---------------------------------------
    cmp = 0;
    asg = 0;
    time = 0;

    for (int step = 0; step < arrayToSort_size; step++) {
        int min_idx = step;

        for (int i = step + 1; i < arrayToSort_size; i++) {
            cmp++;
            if (arrayToSort[i] < arrayToSort[min_idx]) {
                min_idx = i;
                asg++;
            }
        }
        Swap(arrayToSort[min_idx], arrayToSort[step], asg);
    }
    // ---------------------------------------

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    time = elapsed_time.count();
}

