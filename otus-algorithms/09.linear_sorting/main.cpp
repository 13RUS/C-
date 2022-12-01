#include <iostream>

#include "include/FunctionsEnablers.h"

#include "include/CountingSort.h"
#include "include/RadixSort.h"
#include "include/BucketSort.h"

// ---------------------------------------
template <typename T>
void TestingArray (const T& function_name) {

    for (int i = 10; i<=1000000; i *= 10) {
        int* ArrayToTest = new int[i];
        GenerateArraysIncremental(ArrayToTest, i);

        if (i==10) { std:: cout << "Validation:\n" << "Random Array: "; PrintArray(ArrayToTest, i); }

        // ---------------------------------------
        auto start = std::chrono::high_resolution_clock::now();

        function_name(ArrayToTest, i);

        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        // ---------------------------------------

        if (i==10) { std:: cout << "Sorted Array: "; PrintArray(ArrayToTest, i); }
        std::cout << "\nfor size = " << i << " time = " << elapsed_time.count();

        delete [] ArrayToTest;
    }
}

int main() {

    std::cout << "\n// -------------- CountingSort -----------------------\n";
    TestingArray (CountingSort);

    std::cout << "\n// -------------- RadixSort --------------------------\n";
    TestingArray (RadixSort);

    std::cout << "\n// -------------- BucketSort -------------------------\n";
    TestingArray (BucketSort);

//    int array [] =  {121, 564, 432, 23, 1, 45, 4};
//    int n = sizeof(array) / sizeof(array[0]);
//
//    BucketSort(array, n);
//
//   // std::cout << "\n"; PrintArray(array, n);

    //float arrayf[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };

    return 0;
}
