//
// Created by Aleksey Leshchankin on 31.05.2022.
//

#pragma once

#include <iostream>
#include "Generic_Container.h"

template <class T>
struct Node{
    Node<T>* next;
    Node<T>* prev;
    T data;
};

template <typename T>
class List_Container : public Generic_container <T>{
public:

    List_Container();
    ~List_Container() override;

    // main interface
    void push_back (const T value);
    void insert (const T value, unsigned int index);
    void erase (const unsigned int index);
    unsigned int size() const;
    T & operator [] (const unsigned int index);

    // additional methods
    Node<T>* Move (unsigned int index);
    void print_container() const;
    void clear ();
    T getelement (unsigned int index);
    bool is_index_correct (unsigned int index);
    void push_head (const T value);

private:
    Node<T>* head;
    Node<T>* tail;
    unsigned int m_size;
};

template <typename T>
List_Container<T>::List_Container() {
    head = tail = nullptr;
    m_size = 0;
}

template <typename T>
List_Container<T>::~List_Container<T>() {
    clear();
}

// main interface
template <typename T>
void List_Container<T>::push_back(const T value) {
    try {
        Node<T> *new_node = new Node<T>;

        new_node->prev = tail;
        new_node->next = nullptr;
        new_node->data = value;

        if (tail != nullptr)
            tail->next = new_node;

        if (m_size == 0) {
            head = tail = new_node;
        }
        else
            tail = new_node;

        m_size ++;
    }
    catch (std::bad_alloc e) {
        std::cout << e.what() << std::endl;
    }
};

template <typename T>
void List_Container<T>::insert(const T value, unsigned int index) {
    if (!is_index_correct(index-1)) {
        std::cout << "Incorrect index" << std::endl;
        return;
    }

    if (index-1 == m_size){
        push_back(value);
        return;
    }

    if (index-1 == 0){
        push_head(value);
        return;
    }

    try {
        Node<T>* node_prev = Move (index - 2);
        Node<T>* current_node = Move (index - 1);
        Node<T>* new_node = new Node<T>;

        new_node->data = value;
        new_node->prev = node_prev;
        new_node->next = current_node;

        node_prev->next = new_node;
        current_node->prev = new_node;

        m_size++;
    }
    catch (std::bad_alloc e) {
        std::cout << e.what() << std::endl;
    }
}

template <typename T>
void List_Container<T>::erase(const unsigned int index) {

    if (m_size == 0) return;

    if (!is_index_correct(index-1)) {
        std::cout << "Incorrect index" << std::endl;
        return;
    }

    Node<T>* deleted_node = Move(index - 1);
    Node<T>* deleted_node_prev = deleted_node->prev;
    Node<T>* deleted_node_next = deleted_node->next;

    // if not the first element is removed
    if ((m_size > 1) && (deleted_node_prev != nullptr))
        deleted_node_prev -> next = deleted_node_next;

    // if not the last element is removed
    if ((deleted_node_next != nullptr) && (m_size > 1))
        deleted_node_next->prev = deleted_node_prev;

    // if first element is removed
    if (index == 1)
        head = deleted_node_next;

    // if last element is removed
    if (index == m_size)
        tail = deleted_node_prev;

    delete deleted_node;
    m_size--;
}

template<typename T>
unsigned int List_Container<T>::size() const {
    return m_size;
}

template<typename T>
T & List_Container<T>::operator[](const unsigned int index) {
    Node<T>* new_node = Move(index-1);
    return new_node->data;
}

// additional methods
template <class T>
Node<T>* List_Container<T>::Move(unsigned int index) {
    Node<T>* new_node = head;

    for (unsigned int i = 0; i < index; i++){
        new_node = new_node->next;
    }

    return new_node;
}

template <typename T>
void List_Container<T>::print_container() const {
    Node<T>* node = head;

    for (unsigned int i = 0; i < m_size; i++){
        std::cout << node->data <<" ";
        node = node -> next;
    }
    std::cout << std::endl;
}

template <typename T>
void List_Container<T>::clear() {
    unsigned int count = m_size;

    for (unsigned int i = 0; i < count; i++)
        erase(1);
}

template <typename T>
T List_Container<T>::getelement(unsigned int index) {
    if (!is_index_correct(index))
        throw std::out_of_range ("Incorrect index");

    Node<T>* temp_node = Move(index - 1);
    return temp_node->data;
}

template <typename T>
bool List_Container<T>::is_index_correct(unsigned int index) {
    return (index-1 >= 0) && (index <= m_size);
}

template <typename T>
void List_Container<T>::push_head(const T value) {
    try {
        Node<T> *new_node = new Node<T>;

        new_node->prev = nullptr;
        new_node->next = head;
        new_node->data = value;

        if (m_size > 0){
            head->prev = new_node;
            head = new_node;
        }
        else {
            head = tail = new_node;
        }

        m_size ++;
    }
    catch (std::bad_alloc e) {
        std::cout << e.what() << std::endl;
    }
};