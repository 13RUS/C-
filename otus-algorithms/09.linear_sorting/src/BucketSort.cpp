//
// Created by Aleksey Leshchankin on 29.11.2022.
//

#include "iostream"
#include "vector"
#include "../include/FunctionsEnablers.h"
#include "../include/RadixSort.h"
#include "../include/CountingSort.h"

// --------------------------------------
void BucketSort (int *Array, int ArraySize) {

    int numOfBuckets = 6;

    int minElement = getMinElement(Array, ArraySize);
    int maxElement = getMaxElement(Array, ArraySize);

    int range = maxElement - minElement;

    std::vector<int> BucketsVector[numOfBuckets];

    for (int i=0; i < ArraySize; i++) {
        int index = int ((Array[i] * numOfBuckets) / range);
        if (Array[i] == maxElement) index = numOfBuckets - 1;
        BucketsVector[index].push_back(Array[i]);
    }

    for (int i = 0; i < numOfBuckets; i++) {
        sort(BucketsVector[i].begin(), BucketsVector[i].end());
    }

    int index = 0;
    for (int i = 0; i < numOfBuckets; i++)
        for (int j = 0; j < BucketsVector[i].size(); j++) {
            Array[index] = BucketsVector[i][j];
            index++;
        }
}
