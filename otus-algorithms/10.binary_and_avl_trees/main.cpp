#include <iostream>

#include "include/Binary_Search_Tree.h"
#include "include/AVL_Tree.h"

void BinaryTreeTesting (int tree_size) {
    // Создать два дерева
    Binary_Search_Tree BST1;
    Binary_Search_Tree BST2;
    std::cout <<"BST1 validation " << std::endl;
    // Добавить N чисел в случайном порядке
    for (int i = 0; i < tree_size; i++){
       int randomNumber = (rand() % 1000);
       BST1.insert (randomNumber);
    }

    // Искать N/10 случайных чисел
    for (int i = 0; i < tree_size/10; i++){
        int randomNumber = (rand() % 1000);
        BST1.search(randomNumber);
    }

    // Удалить N/10 случайных элементов
    for (int i = 0; i < tree_size/10; i++){
        int randomNumber = (rand() % 1000);
        std::cout << randomNumber << " deletion" << "\n" ;
        BST1.remove(randomNumber);
    }

    std::cout <<"\nBST2 validation " << std::endl;
    // Добавить N чисел в возрастающем порядке
    for (int i = 0; i < tree_size; i++){
        BST2.insert (i);
    }

    // Искать N/10 случайных чисел
    for (int i = 0; i < tree_size/10; i++){
        int randomNumber = (rand() % 10000);
        BST2.search(randomNumber);
    }

    // Удалить N/10 случайных элементов
    for (int i = 0; i < tree_size/10; i++){
        int randomNumber = (rand() % 10000);
        std::cout << randomNumber << " deletion" << "\n" ;
        BST2.remove(randomNumber);
    }
}
// ---------------------------------------
int main() {
   BinaryTreeTesting(100);
   return 0;
}
