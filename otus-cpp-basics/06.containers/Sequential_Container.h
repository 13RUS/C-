//
// Created by Aleksey Leshchankin on 31.05.2022.
//

#pragma once

#include <iostream>
#include "Generic_Container.h"

template <typename T>
class Sequential_Container : public Generic_container <T>{
public:
    Sequential_Container();
    ~Sequential_Container() override;

    // main interface
    void push_back (const T value);
    void insert (const T value, unsigned int index);
    void erase (const unsigned int index);
    unsigned int size() const;
    T & operator [] (const unsigned int index);

    // additional methods
    void erase_three_values (const unsigned int index1, const unsigned int index2, const unsigned int index3);
    void print_container() const;
    void pop_back ();
    void clear ();
    bool is_index_correct (unsigned int index);

private:
    unsigned int current_size; //number of elements currently present in the vector
    unsigned int capacity;     //total storage capacity of the vector - maximum size of the vector
    T* buffer;                 //pointer to a data type
};

template<typename T>
Sequential_Container<T>::Sequential_Container() {
    current_size = 0;
    capacity = 0;
    buffer = 0;
}

template<typename T>
Sequential_Container<T>::~Sequential_Container<T>() {
    delete[] buffer;
}

// main interface
template <typename T>
void Sequential_Container<T>::push_back(const T value) {
    T *new_buffer = new T[current_size + 1];
    for (unsigned int i = 0; i < current_size; ++i) {
        new_buffer[i] = buffer[i];
    }
    new_buffer[current_size] = value;
    delete[] buffer;
    buffer = new_buffer;
    current_size += 1;
}

template <typename T>
void Sequential_Container<T>::insert(const T value, unsigned int index) {

    if (!is_index_correct(index-1)) {
        std::cout << "Incorrect index" << std::endl;
        return;
    }

    T *new_buffer = new T[current_size + 1];

    for (unsigned int i = 0; i < index-1; ++i) {
        new_buffer[i] = buffer[i];
    }

    new_buffer[index-1] = value;

    for (unsigned int i = index; i <= current_size+1; ++i) {
        new_buffer[i] = buffer[i-1];
    }
    delete[] buffer;
    buffer = new_buffer;
    current_size += 1;
}

template <typename  T>
void Sequential_Container<T>::erase(const unsigned int index) {

    if (current_size == 0) return;

    if (!is_index_correct(index-1)) {
        std::cout << "Incorrect index" << std::endl;
        return;
    }

    T *new_buffer = new T[current_size-1];

    unsigned int j=0;
    for (unsigned int i = 0; i < current_size; ++i) {

        if (i == index-1) i++;
        new_buffer[j] = buffer[i];
        j++;
    }
    delete[] buffer;
    buffer = new_buffer;
    current_size -=1;
}

template<typename T>
unsigned int Sequential_Container<T>::size() const {
    return current_size;
}

template <typename T>
T & Sequential_Container<T>::operator[](const unsigned int index) {
    return buffer[index];
}

// additional methods
template <typename  T>
void Sequential_Container<T>::erase_three_values(const unsigned int index1, const unsigned int index2,
                                                 const unsigned int index3) {

    T *new_buffer = new T[current_size-3];

    unsigned int j=0;
    for (unsigned int i = 0; i < index1-1; ++i) {
        new_buffer[j] = buffer[i];
        j++;
    }

    for (unsigned int i = index1; i < index2-1; ++i) {
        new_buffer[j] = buffer[i];
        j++;
    }

    for (unsigned int i = index2; i < index3-1; ++i) {
        new_buffer[j] = buffer[i];
        j++;
    }

    for (unsigned int i = index3; i <= current_size; ++i) {
        new_buffer[j] = buffer[i];
        j++;
    }

    delete[] buffer;
    buffer = new_buffer;
    current_size -=3;
}

template <typename T>
void Sequential_Container<T>::print_container() const {
    for (unsigned int i = 0; i < current_size; i++){
        std::cout << buffer[i] <<" ";
    }
    std::cout << std::endl;
}

template <typename T>
void Sequential_Container <T>::pop_back() {
    current_size --;
}

template <typename T>
void Sequential_Container <T>::clear() {
    current_size = 0;
    buffer = 0;
}

template <typename T>
bool Sequential_Container<T>::is_index_correct(unsigned int index) {
    return (index-1 >= 0) && (index <= current_size);
}