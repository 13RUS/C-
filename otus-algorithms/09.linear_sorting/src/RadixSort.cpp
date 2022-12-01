//
// Created by Aleksey Leshchankin on 28.11.2022.
//

#include "../include/FunctionsEnablers.h"

// --------------------------------------
void CountingSort (int Array [], int ArraySize, int place) {
    const int max = 10;
    int output[ArraySize];
    int count[max];

    for (int i = 0; i < max; i++)
        count[i] = 0;

    for (int i = 0; i < ArraySize; i++)
        count[(Array[i] / place) % 10]++;

    for (int i = 1; i < max; i++)
        count[i] += count [i-1];

    for (int i = ArraySize - 1; i >=0; i--){
        output[count[(Array[i] / place) % 10] - 1] = Array[i];
        count[(Array[i] / place) % 10] --;
    }

    for (int i = 0; i < ArraySize; i++)
        Array[i] = output[i];
}

// --------------------------------------
void RadixSort (int* Array, int ArraySize) {
    int maxElement = getMaxElement(Array, ArraySize);

    for (int place = 1; maxElement /place > 0; place *= 10)
        CountingSort(Array, ArraySize, place);
}
