#include <iostream>
#include "GenericArray.h"
#include "SingleArray.h"
#include "VectorArray.h"
#include "FactorArray.h"
#include "MatrixArray.h"
#include "List_Container.h"
#include "PriorityQueue.h"

// -- Test Method ------------------------
void TestAddMethod (SingleArray<int> array, int count) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < count; i++){
        array.Add(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "for  n = "<< count << " elapsed time is " << elapsed_ms.count() << " ms\n";
}

void TestAddMethod (VectorArray<int> array, int count) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < count; i++){
        array.Add(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "for  n = "<< count << " elapsed time is " << elapsed_ms.count() << " ms\n";
}

void TestAddMethod (FactorArray<int> array, int count) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < count; i++){
        array.Add(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "for  n = "<< count << " elapsed time is " << elapsed_ms.count() << " ms\n";
}

// ---------------------------------------
int main() {

    // -- ARRAYS SECTION ---------------------
    int index, item;

    // -- Single Array Testing ---------------
    std::cout << "\nSINGLE ARRAY TESTING" << std::endl;
    SingleArray <int> test_class_SingleArray;

    for (int i=0; i<5; i++) test_class_SingleArray.Add(i,i);
    std::cout << "Array : "; test_class_SingleArray.Print();
    std::cout << "Size is : " << test_class_SingleArray.Size() << std::endl;

    item = 222;
    index = 2;
    std::cout << "Adding item " << item <<" at position " << index << std::endl;
    test_class_SingleArray.Add(item,index);
    std::cout << "Array : "; test_class_SingleArray.Print();
    std::cout << "Size is : " << test_class_SingleArray.Size() << std::endl;

    index = 2;
    std::cout << "Removing item from position " << index <<" (item=" <<  test_class_SingleArray.Remove(index) << ")" << std::endl;
    std::cout << "Array : "; test_class_SingleArray.Print();
    std::cout << "Size is : " << test_class_SingleArray.Size() << std::endl;

    // -- Vector Array Testing ---------------
    std::cout << "\nVECTOR ARRAY TESTING" << std::endl;
    VectorArray <int> test_class_VectorArray;

    for (int i=0; i<20; i++) test_class_VectorArray.Add(i,i);
    std::cout << "Array : "; test_class_VectorArray.Print();
    std::cout << "Size is : " << test_class_VectorArray.Size() << std::endl;

    item = 222;
    index = 4;
    std::cout << "Adding item " << item <<" at position " << index << std::endl;
    test_class_VectorArray.Add(item, index);
    std::cout << "Array : "; test_class_VectorArray.Print();
    std::cout << "Size is : " << test_class_VectorArray.Size() << std::endl;

    index = 10;
    std::cout << "Removing item from position " << index <<" (item=" <<  test_class_VectorArray.Remove(index) << ")" << std::endl;
    std::cout << "Array : "; test_class_VectorArray.Print();
    std::cout << "Size is : " << test_class_VectorArray.Size() << std::endl;

    // -- Factor Array Testing ---------------
    std::cout << "\nFACTOR ARRAY TESTING" << std::endl;
    FactorArray <int> test_class_FactorArray;

    for (int i=0; i<20; i++) test_class_FactorArray.Add(i,i);
    std::cout << "Array : "; test_class_FactorArray.Print();
    std::cout << "Size is : " << test_class_FactorArray.Size() << std::endl;

    item = 222;
    index = 4;
    std::cout << "Adding item " << item <<" at position " << index << std::endl;
    test_class_FactorArray.Add(item, index);
    std::cout << "Array : "; test_class_FactorArray.Print();
    std::cout << "Size is : " << test_class_FactorArray.Size() << std::endl;

    index = 10;
    std::cout << "Removing item from position " << index <<" (item=" <<  test_class_FactorArray.Remove(index) << ")" << std::endl;
    std::cout << "Array : "; test_class_FactorArray.Print();
    std::cout << "Size is : " << test_class_FactorArray.Size() << std::endl;

    // -- Matrix Array Testing ---------------
    std::cout << "\nMATRIX ARRAY TESTING" << std::endl;
    MatrixArray<int> test_class_MatrixArray;
    for (int i=0; i<20; i++) test_class_MatrixArray.Add(i);
    std::cout << "Array : "; test_class_MatrixArray.Print();
    std::cout << "Size is : " << test_class_MatrixArray.Size() << std::endl;


    // -- ARRAYS SECTION SPEED TEST ----------
    std::cout << "\n** Array Speed Test **" << std::endl;
    SingleArray <int> test_class_SingleArrayAddSpeedTest;
    VectorArray <int> test_class_VectorArrayAddSpeedTest;
    FactorArray <int> test_class_FactorArrayAddSpeedTest;
    for (int i = 1; i <= 10000; i*=10) TestAddMethod(test_class_SingleArrayAddSpeedTest, i);
    for (int i = 1; i <= 100000; i*=10) TestAddMethod(test_class_VectorArrayAddSpeedTest, i);
    for (int i = 1; i <= 100000000; i*=10) TestAddMethod(test_class_FactorArrayAddSpeedTest, i);

    //-- QUEUE SECTION -----------------------
    // -- List Contianer Testing -------------

    std::cout << "\nQUEUE TESTING" << std::endl;

    std::cout << "** List Class Testing **" << std::endl;
    List_Container <int> test_class_List;

    std::cout << "Container elements : ";
    for (unsigned int i = 0; i < 10; i ++) {test_class_List.push_back(i);}
    test_class_List.print_container();

    std::cout << "Container size: " << test_class_List.size() << std::endl;
    PriorityQueue<int>test_class_PriorityQueue;

    std::cout << "\n** Priority Queue Testing **" << std::endl;
    test_class_PriorityQueue.enqueu(2,21);
    test_class_PriorityQueue.enqueu(2,22);
    test_class_PriorityQueue.enqueu(1,11);
    test_class_PriorityQueue.enqueu(3,31);

    test_class_PriorityQueue.dequeue();
    test_class_PriorityQueue.dequeue();
    test_class_PriorityQueue.dequeue();

    return 0;
}
