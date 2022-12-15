#include <iostream>
#include "HashingWithChaining.h"


int main() {
    int key[] = {1, 15, 16, 7, 4, 2};
    int size = sizeof(key) / sizeof(key[0]);

    HashingWithChaining testHashTableWithChaining(size);
    for (int i = 0; i < size; i++) testHashTableWithChaining.insertValue(key[i]);

    std::cout << "Initial Hash Table: " << std::endl;
    testHashTableWithChaining.printHashTable(); std::cout << std:: endl;

    int deletedKey = key[4];
    testHashTableWithChaining.deleteKey(deletedKey);

    std::cout << "Hash Table After Deleting key = " << deletedKey << std::endl;
    testHashTableWithChaining.printHashTable();

    return 0;
}
