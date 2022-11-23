//
// Created by Aleksey Leshchankin on 22.11.2022.
//
#include "chrono"
#include "../include/FunctionsEnablers.h"

// ---------------------------------------
void heapify (int* array, int n, int i, unsigned long& cmp, unsigned long& asg) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    cmp++;
    if (left < n && array[left] > array[largest]) {
        largest = left;
        asg++;
    }
    cmp++;
    if (right < n && array[right] > array[largest]) {
        largest = right;
        asg++;
    }

    cmp++;
    if (largest != i) {
        Swap(array[i],array[largest], asg);
        heapify (array, n, largest, cmp, asg);
    }
}

// ---------------------------------------
void HeapSort (int* arrayToSort, int arrayToSort_size, unsigned long& cmp, unsigned long& asg, int& time) {
    auto start = std::chrono::high_resolution_clock::now();

    // ---------------------------------------
    cmp = 0;
    asg = 0;
    time = 0;

    for (int i = arrayToSort_size / 2; i >= 0; i--) {
        heapify(arrayToSort, arrayToSort_size, i, cmp, asg);
    }

    for (int i = arrayToSort_size-1; i >= 0; i--) {
        Swap(arrayToSort[0], arrayToSort[i], asg);

        heapify(arrayToSort, i, 0, cmp, asg);
    }
    // ---------------------------------------

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    time = elapsed_time.count();
}
