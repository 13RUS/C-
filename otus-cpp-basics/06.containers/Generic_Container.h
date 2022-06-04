//
// Created by Aleksey Leshchankin on 31.05.2022.
//

#pragma once

template <typename T>
class Generic_container{
public:
    Generic_container(){};
    virtual ~Generic_container(){};

    //void push_back (const T value);
    //void insert (const T value, unsigned int index);
    //void erase (const unsigned int index);
    //void erase_three_values (const unsigned int index1, const unsigned int index2, const unsigned int index3);
    //virtual unsigned int size() const;
    //T & operator [] (const unsigned int index);

    // additional support functions
    //void print_container() const;
    //void pop_back ();
    //void clear ();

private:
    unsigned int current_size; //number of elements currently present in the vector
    unsigned int capacity;     //total storage capacity of the vector - maximum size of the vector
    T* buffer;                 //pointer to a data type
};