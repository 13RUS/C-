//
// Created by Aleksey Leshchankin on 25.11.2022.
//

#include "chrono"
#include "../include/FunctionsEnablers.h"

// --------------------------------------
void merge (int array[], int p, int q, int r) {

    int LeftSubArray_size = q - p + 1;
    int RightSubArray_size = r - q;

    int LeftSubArray[LeftSubArray_size], RightSubArray[RightSubArray_size];

    for (int i = 0; i < LeftSubArray_size; i ++) LeftSubArray[i] = array [p + i];
    for (int j = 0; j < RightSubArray_size; j ++) RightSubArray[j] = array [q + 1 + j];

    // Index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Copy smaller element into sorted array
    while (i < LeftSubArray_size && j < RightSubArray_size) {
        if (LeftSubArray[i] <= RightSubArray[j]) {
            array[k] = LeftSubArray[i];
            i++;
        } else {
            array[k] = RightSubArray[j];
            j++;
        }
        k++;
    }
    // Pick up the remaining elements
    while (i < LeftSubArray_size) {
        array[k] = LeftSubArray[i];
        i++;
        k++;
    }

    while (j < RightSubArray_size) {
        array[k] = RightSubArray[j];
        j++;
        k++;
    }
}

// --------------------------------------
void MergeSort (int array[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSort(array, l, m);
        MergeSort(array, m + 1, r);
        merge (array, l, m,  r);
    }
}

// --------------------------------------
void merge (int *array, int p, int q, int r, unsigned long& cmp, unsigned long& asg) {

    int LeftSubArray_size = q - p + 1;
    int RightSubArray_size = r - q;

    int LeftSubArray[LeftSubArray_size], RightSubArray[RightSubArray_size];

    for (int i = 0; i < LeftSubArray_size; i ++) LeftSubArray[i] = array [p + i];
    for (int j = 0; j < RightSubArray_size; j ++) RightSubArray[j] = array [q + 1 + j];

    // Index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Copy smaller element into sorted array
    while (i < LeftSubArray_size && j < RightSubArray_size) {
        cmp++;
        cmp++;
        if (LeftSubArray[i] <= RightSubArray[j]) {
            array[k] = LeftSubArray[i];
            i++;
            asg++;
        } else {
            array[k] = RightSubArray[j];
            j++;
            asg++;
        }
        k++;
    }

    // Pick up the remaining elements
    while (i < LeftSubArray_size) {
        cmp++;
        array[k] = LeftSubArray[i];
        i++;
        k++;
        asg++;
    }

    while (j < RightSubArray_size) {
        cmp++;
        array[k] = RightSubArray[j];
        j++;
        k++;
        asg++;
    }
}

// --------------------------------------
void MergeSort (int* array, int left, int right, unsigned long& cmp, unsigned long& asg, int& time) {
    auto start = std::chrono::high_resolution_clock::now();

    // ---------------------------------------
    if (left < right) {
        int middle = left + (right - left) / 2;
        MergeSort(array, left, middle);
        MergeSort(array, middle + 1, right);
        merge (array, left,  middle,  right, cmp, asg);
    }
    // ---------------------------------------

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    time = elapsed_time.count();
}