//
// Created by Aleksey Leshchankin on 28.11.2022.
//

// --------------------------------------
void CountingSort (int *array, int ArraySize) {

    int max = array[0];
    int output[ArraySize];
    int count [1000000];

    // -- Count array with zeros -------
    for (int i = 1; i < ArraySize; i++) {
        if (array[i] > max) max = array[i];
    }

    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    //-- Count of each element ---------
    for (int i = 0; i < ArraySize; i++) {
        count[array[i]] ++;
    }

    //-- Commulative count -------------
    for (int i = 1; i <= max; i++) {
        count[i] += count [i-1];
    }

    for (int i = ArraySize - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]] --;
    }
    for (int i = 0; i < ArraySize; i++) {
        array[i] = output[i];
    }
}