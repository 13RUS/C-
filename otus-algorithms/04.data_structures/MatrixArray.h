//
// Created by Aleksey Leshchankin on 13.11.2022.
//

#pragma  once

#include <iostream>

template <typename T>
class MatrixArray : public GenericArray <T>{
public:
    MatrixArray();
    MatrixArray(unsigned int size);
    ~MatrixArray();

    // -- Main Interface --
    unsigned int Size() const;
    void Add (const T item);
    void Add (const T item, unsigned int index);
    T Remove (unsigned int index);

    // -- Enablers --
    T & operator [] (unsigned int index);
    void Resize();
    void Print ();

private:
    FactorArray<SingleArray<T>> arrays;
    unsigned int current_size;
    unsigned int subarray_size = 6;
    unsigned int capacity = 0;
};

// ---------------------------------------
// -- Constructor ------------------------
template <typename T>
MatrixArray<T>::MatrixArray() {
    current_size = 0;
    capacity = 0;
}

// -- Destructor -------------------------
template <typename T>
MatrixArray<T>::~MatrixArray<T>() {
}

// -- Main Interface ---------------------
template <typename T>
unsigned int MatrixArray<T>::Size() const{
    return current_size;
}

template <typename T>
void MatrixArray<T>::Add(const T item) {

    capacity = arrays.Size() * subarray_size;

    if (current_size == capacity) {
        SingleArray<T> tempSingleArray;
        arrays.Add(tempSingleArray);
    }

    arrays[current_size/subarray_size].Add(item);
    current_size++;
}

template <typename T>
void MatrixArray<T>::Print() {
    for (int i = 0; i <= current_size/subarray_size; i++) {
        arrays[i].Print();
    }
}