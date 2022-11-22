//
// Created by Aleksey Leshchankin on 18.11.2022.
//

#include "chrono"
#include "iostream"
#include "../include/FunctionsEnablers.h"

// ---------------------------------------
void Bubble (int* arrayToSort, int arrayToSort_size, unsigned long& cmp, unsigned long& asg, int& time) {
    auto start = std::chrono::high_resolution_clock::now();

    // ---------------------------------------
    cmp = 0;
    asg = 0;
    time = 0;

    for (int j = arrayToSort_size - 1; j >=0; j--){
        for (int i = 0; i < j; i++) {
            cmp++;
            if (arrayToSort[i] > arrayToSort[j]) Swap(arrayToSort[i], arrayToSort[j], asg);
        }
    }
    // ---------------------------------------

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    time = elapsed_time.count();
}

// ---------------------------------------
void BubbleDetailedPrint (int* arrayToSort, int arrayToSort_size, unsigned long& cmp, unsigned long& asg, int& time) {
    auto start = std::chrono::high_resolution_clock::now();

    // ---------------------------------------
    cmp = 0;
    asg = 0;
    time = 0;

    for (int j = arrayToSort_size - 1; j >=0; j--){
        bool flag = false;
        std::cout <<"\nj = " << j << " element =  " << arrayToSort[j] ;
        for (int i = 0; i < j; i++) {
            cmp++;
            std::cout <<"\n       i = " << i << " element =  " << arrayToSort[i];
            if (arrayToSort[i] > arrayToSort[j]) {
                std::cout <<"\n              i = " << i << " element =  " << arrayToSort[i];
                flag = true;
                Swap(arrayToSort[i], arrayToSort[j], asg);
                std::cout << "\n                  ";
                for (int k=0; k<arrayToSort_size;k++) std::cout << arrayToSort[k] << " ";
            }
        }
        std::cout << "\narray = ";
        for (int p=0; p<arrayToSort_size;p++) std::cout << arrayToSort[p] << " ";
    }
    // ---------------------------------------

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    time = elapsed_time.count();
}

