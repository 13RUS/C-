//
// Created by Aleksey Leshchankin on 11.11.2022.
//

#pragma  once

#include <iostream>

template <typename T>
class SingleArray : public GenericArray <T>{
public:
    SingleArray();
    SingleArray(unsigned int size);
    ~SingleArray();

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
};

// ---------------------------------------
// -- Constructor ------------------------
template <typename T>
SingleArray<T>::SingleArray() {
    array = nullptr;
    current_size = 0;
}

template <typename T>
SingleArray<T>::SingleArray(unsigned int size) {
    array = new T[size];
    current_size = size;

    for (int i = 0; i < current_size; i ++)
        array[i] = i;
}

// -- Destructor -------------------------
template <typename T>
SingleArray<T>::~SingleArray<T>() {
    delete [] array;
}

// -- Main Interface ---------------------
template <typename T>
unsigned int SingleArray<T>::Size() const{
    return current_size;
}

template <typename T>
void SingleArray<T>::Add(const T item, unsigned int index) {
    Resize();

    int *newArray = new T [current_size+1];

    for (int i = 0; i < index; i++) {
        newArray[i] = array[i];
    }
    newArray[index] = item;

    for (int i = index+1; i < current_size; i++) {
        newArray[i] = array[i-1];
    }
    array = newArray;
}

template <typename T>
void SingleArray<T>::Add(const T item) {
        Resize();

    array[current_size] = item;
    current_size++;
}

// -- Removes Element --------------------
template <typename T>
T SingleArray<T>::Remove(unsigned int index) {
    T Item;
    if ((index < 0) || (index >= current_size)) throw std::out_of_range ("\nExit due to an incorrect index");

    int *newArray = new T [current_size-1];

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
void SingleArray<T>::Resize() {
    int *newArray = new T [current_size + 1];

    for (int index = 0; index < current_size; index ++) {
        newArray[index] = array[index];
    }
    array = newArray;
    current_size ++;
}

template <typename T>
void SingleArray<T>::Print() {
    for (int i = 0; i < current_size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T & SingleArray<T> :: operator[](unsigned int index){
    if ((index < 0) || (index >= current_size)) throw std::out_of_range ("\nExit due to an incorrect index");
    else return array[index];
}