//
// Created by Aleksey Leshchankin on 12.11.2022.
//

#pragma  once

#include <iostream>

template <typename T>
class FactorArray : public GenericArray <T>{
public:
    FactorArray();
    FactorArray(unsigned int size);
    ~FactorArray();

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
    T *array;
    unsigned int current_size;
    unsigned int resize_coefficient = 2;
    unsigned int capacity = 0;
};

// ---------------------------------------
// -- Constructor ------------------------
template <typename T>
FactorArray<T>::FactorArray() {
    array = new T[0];
    current_size = 0;
    capacity = 0;
}

template <typename T>
FactorArray<T>::FactorArray(unsigned int size) {
    array = new T[size];
    current_size = size;

    for (int i = 0; i < current_size; i ++)
        array[i] = i;
}

// -- Destructor -------------------------
template <typename T>
FactorArray<T>::~FactorArray<T>() {
    delete[] array;
}

// -- Main Interface ---------------------
template <typename T>
unsigned int FactorArray<T>::Size() const{
    return current_size;
}

template <typename T>
void FactorArray<T>::Add(const T item, unsigned int index) {
    if (current_size == capacity) {
        Resize();
    }
    int *newArray = new int [capacity];

    for (int i = 0; i < index; i++) {
        newArray[i] = array[i];
    }
    newArray[index] = item;

    for (int i = index+1; i <= current_size; i++) {
        newArray[i] = array[i-1];
    }
    array = newArray;
    current_size++;
}

template <typename T>
void FactorArray<T>::Add(const T item) {
    if (current_size == capacity) {
        Resize();
    }

    array[current_size] = item;
    current_size++;
}

// -- Removes Element --------------------
template <typename T>
T FactorArray<T>::Remove(unsigned int index) {
    T Item;
    if ((index < 0) || (index >= current_size)) throw std::out_of_range ("\nExit due to an incorrect index");

    int *newArray = new T [capacity];

    Item = array[index];

    for (int i = 0; i < index; i++) {
        newArray[i] = array[i];
    }

    for (int i = index+1; i < current_size; i++) {
        newArray[i-1] = array[i];
    }
    array = newArray;
    current_size --;
    return Item;
}

// -- Enablers ---------------------------
template <typename T>
void FactorArray<T>::Resize() {

    T *newArray = new T [current_size * resize_coefficient + 1];
    capacity = current_size * resize_coefficient + 1;

    for (int index = 0; index < current_size; index ++) {
        newArray[index] = array[index];
    }
    array = newArray;
}

template <typename T>
void FactorArray<T>::Print() {
    for (int i = 0; i < current_size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T & FactorArray<T> :: operator[](unsigned int index){
    if ((index < 0) || (index >= current_size)) throw std::out_of_range ("\nExit due to an incorrect index");
    else return array[index];
}