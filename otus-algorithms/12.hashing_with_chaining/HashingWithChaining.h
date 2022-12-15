//
// Created by Aleksey Leshchankin on 15.12.2022.
//

#pragma once

#include <list>
#include <iostream>

class HashingWithChaining {

public:
    HashingWithChaining(int capacity);
    ~HashingWithChaining();

    int hashingFunction (int key);
    void insertValue (int key);
    void deleteKey (int key);

    void printHashTable ();

private:
    int NumOfCells;
    std::list<int> *hashTable;
};
// ---------------------------------------
HashingWithChaining::HashingWithChaining(int capacity) {
    NumOfCells = capacity;
    hashTable = new std::list<int>[NumOfCells];
}

// ---------------------------------------
HashingWithChaining::~HashingWithChaining() {
   hashTable->clear();
}

// ---------------------------------------
int HashingWithChaining::hashingFunction(int key) {
    return key % NumOfCells;
}

// ---------------------------------------
void HashingWithChaining::insertValue(int key) {
    int cellNumber = hashingFunction(key);
    hashTable[cellNumber].push_back(key);
}

// ---------------------------------------
void HashingWithChaining::deleteKey(int key) {
    int cellNumber = hashingFunction(key);

    std::list <int>::iterator i;

    for (i = hashTable[cellNumber].begin(); i != hashTable[cellNumber].end(); i++) {
        if (*i == key) break;
    }

    if (i != hashTable[cellNumber].end())
        hashTable[cellNumber].erase(i);
}

// ---------------------------------------
void HashingWithChaining::printHashTable() {
    for (int i = 0; i < NumOfCells; i++) {
        std::cout << "cell [" << i << "]";
        for (auto x : hashTable[i])
            std::cout << " - " << x;
        std::cout << std::endl;
    }
}