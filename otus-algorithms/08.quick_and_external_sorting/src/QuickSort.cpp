//
// Created by Aleksey Leshchankin on 24.11.2022.
//

#include "chrono"
#include "../include/FunctionsEnablers.h"

// --------------------------------------
int partition (int* arrayToSort, int low, int high, unsigned long& cmp, unsigned long& asg) {
    int pivot = arrayToSort[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        cmp++;
        if (arrayToSort[j] <= pivot) {
            i++;
            Swap(arrayToSort[i], arrayToSort[j], asg);
        }
    }

    Swap(arrayToSort[i + 1], arrayToSort[high], asg);
    return i+1;
}

// --------------------------------------
void QuickSort (int* arrayToSort, int low, int high, unsigned long& cmp, unsigned long& asg, int& time) {
    auto start = std::chrono::high_resolution_clock::now();

    // ---------------------------------------
    if (low < high) {
        int pi = partition (arrayToSort, low, high, cmp, asg);
        QuickSort(arrayToSort, low, pi - 1, cmp, asg, time);
        QuickSort(arrayToSort, pi + 1, high, cmp, asg, time);
    }
    // ---------------------------------------

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    time = elapsed_time.count();
}
