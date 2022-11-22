//
// Created by Aleksey Leshchankin on 20.11.2022.
//

#include "chrono"
#include "../include/FunctionsEnablers.h"

// ---------------------------------------
void Insertion (int* arrayToSort, int arrayToSort_size, unsigned long& cmp, unsigned long& asg, int& time) {
    auto start = std::chrono::high_resolution_clock::now();

    // ---------------------------------------
    cmp = 0;
    asg = 0;
    time = 0;

    for (int j = 1; j < arrayToSort_size; j++){
        for (int i = j-1; i >=0 && arrayToSort[i] > arrayToSort[i+1]; i--) {
            cmp++;
            Swap(arrayToSort[i], arrayToSort[i+1], asg);
        }
    }
    // ---------------------------------------

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    time = elapsed_time.count();
}

// ---------------------------------------
void InsertionShift (int* arrayToSort, int arrayToSort_size, unsigned long& cmp, unsigned long& asg, int& time) {
    auto start = std::chrono::high_resolution_clock::now();

    // ---------------------------------------
    cmp = 0;
    asg = 0;
    time = 0;
    int i = 0;

    for (int j = 1; j < arrayToSort_size; j++){
        int K = arrayToSort[j]; asg++;
        for (i = j-1; i >=0 && (++cmp > 0) && arrayToSort[i] > K; i--) {
            arrayToSort[i+1] = arrayToSort[i]; asg++;
        }
        arrayToSort[i+1] = K; asg++;
    }
    // ---------------------------------------

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    time = elapsed_time.count();
}

// ---------------------------------------
void InsertionBinarySearch (int* arrayToSort, int arrayToSort_size, unsigned long& cmp, unsigned long& asg, int& time) {
    auto start = std::chrono::high_resolution_clock::now();

    // ---------------------------------------
    cmp = 0;
    asg = 0;
    time = 0;
    int i;

    for (int j = 1; j < arrayToSort_size; j++){
        int K = arrayToSort[j]; asg++;
        int p = BinarySearch(K, 0, j-1, arrayToSort, cmp);
        for (i = j-1; i >= p; i--) {
            arrayToSort[i+1] = arrayToSort[i]; asg++;
        }
        arrayToSort[i+1] = K; asg++;
    }
    // ---------------------------------------

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    time = elapsed_time.count();
}
