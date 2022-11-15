//
// Created by Aleksey Leshchankin on 13.11.2022.
//

#pragma once
#include "List_Container.h"
#include <vector>

template <typename T>
class PriorityQueue{
public:

    PriorityQueue();
    ~PriorityQueue();

    // -- Main Interface --
    void enqueu (int priority, T item);
    void dequeue();

    // -- Enablers --

private:
    unsigned int m_size;
    std::vector<List_Container<T>> array;
};

// ---------------------------------------
// -- Constructor ------------------------
template <typename T>
PriorityQueue<T>::PriorityQueue() {
    List_Container<T> high_priority_queue;
    List_Container<T> mid_priority_queue;
    List_Container<T> low_priority_queue;
    array.push_back (high_priority_queue);
    array.push_back (mid_priority_queue);
    array.push_back (low_priority_queue);
}

// -- Destructor -------------------------
template <typename T>
PriorityQueue<T>::~PriorityQueue<T>() {
    array.clear();
}

// -- Main Interface ---------------------
template <typename T>
void PriorityQueue<T>::enqueu(int priority, T item) {

    std::cout <<"Enqueue operation: " << "priority = " << priority << " item = " << item << std::endl;

    if (priority == 1) array[0].push_back(item);
    if (priority == 2) array[1].push_back(item);
    if (priority == 3) array[2].push_back(item);
}

template <typename T>
void PriorityQueue<T>::dequeue() {

    std::cout <<"\nDeque Called:"<<std::endl;
    std::cout <<"Queue before Deque operation:"<<std::endl;
    std::cout <<"[H] "; array[0].print_container();
    std::cout <<"[M] "; array[1].print_container();
    std::cout <<"[L] "; array[2].print_container();

    if (array[0].size()!=0) array[0].erase(1);
    else if (array[1].size()!=0) array[1].erase(1);
    else if  (array[2].size()!=0) array[2].erase(1);

    else std::cout <<"Queue is empty\n";

    std::cout <<"\nQueue after Deque operation:"<<std::endl;;
    std::cout <<"[H] "; array[0].print_container();
    std::cout <<"[M] "; array[1].print_container();
    std::cout <<"[L] "; array[2].print_container();

}