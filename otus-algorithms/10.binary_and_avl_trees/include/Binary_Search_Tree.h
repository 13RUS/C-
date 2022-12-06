//
// Created by Aleksey Leshchankin on 01.12.2022.
//

#pragma once

#include <iostream>

class Binary_Search_Tree{

private:
   struct node {
       int key;
       node* left;
       node* right;
   };

   node* root;

   // ---------------------------------------
   node* clear (node* rootNode) {
       if (rootNode == NULL) return NULL;
       {
           clear(rootNode->left);
           clear(rootNode->right);
           delete rootNode;
       }
       return NULL;
   }

   // ---------------------------------------
   node* insert (int value, node* rootNode){
       if (rootNode == NULL)
       {
           rootNode = new node;
           rootNode->key = value;
           rootNode->left = rootNode->right = NULL;
       }
       else if (value < rootNode->key)
           rootNode->left = insert(value, rootNode->left);
       else if (value > rootNode->key)
           rootNode->right = insert(value, rootNode->right);
       return rootNode;
   }

   // ---------------------------------------
   void inOrder (node* rootNode) {
       if (rootNode == NULL) return;
       inOrder(rootNode->left);
       std::cout << rootNode->key << " ";
       inOrder(rootNode->right);
   }

   // ---------------------------------------
   node* findKey (node* rootNode, int value){
       if (rootNode == NULL)
           return NULL;
       else if (value < rootNode->key)
           return findKey (rootNode->left, value);
       else if (value > rootNode->key)
           return findKey (rootNode->right, value);
       else
           return rootNode;
   }

    // ---------------------------------------
    bool findKey2 (node* rootNode, int value){
        if (rootNode == NULL)
            return false;

        if (rootNode->key == value) return true;

        bool res1 = findKey2 (rootNode->left, value);
        if (res1) return true;

        bool res2 = findKey2 (rootNode->right, value);
        return res2;
    }

   // ---------------------------------------
   node* findMin (node* rootNode){
       if (root == NULL)
           return NULL;
       else if (rootNode->left == NULL)
           return rootNode;
       else
           return findMin(rootNode->left);
   }

   // ---------------------------------------
   node* findMax (node* rootNode) {
       if (root == NULL)
           return NULL;
       else if (rootNode->right == NULL)
           return rootNode;
       else
           return findMax(rootNode->right);
   }

   // ---------------------------------------
   node* remove (int value, node* rootNode) {
       node* temp;

       if (rootNode == NULL)
           return NULL;
       else if (value < rootNode->key)
           rootNode->left = remove(value, rootNode->left);
       else if (value > rootNode->key)
           rootNode->right = remove(value, rootNode->right);
      // if two children
       else if (rootNode->left && rootNode->right) {
           temp = findMin(rootNode->right);
           rootNode->key = temp->key;
           rootNode->right = remove (rootNode->key,  rootNode->right);
       }
       // if only one child or no child
       else {
           temp = rootNode;
           if (rootNode->left == NULL)
               rootNode = rootNode->right;
           else if (rootNode->right == NULL)
               rootNode = rootNode->left;
           delete (temp);
       }
       return rootNode;
   }

public:

    Binary_Search_Tree();
    ~Binary_Search_Tree();

    void insert (int value);
    void print ();
    void search (int value);
    void remove (int value);

};

// ---------------------------------------
// -- Constructor ------------------------
Binary_Search_Tree::Binary_Search_Tree() {
   root = NULL;
}

// -- Destructor -------------------------
Binary_Search_Tree::~Binary_Search_Tree(){
    root = clear(root);
}

// ---------------------------------------
void Binary_Search_Tree::insert(int value) {
    root = insert (value, root);
}

// ---------------------------------------
void Binary_Search_Tree::print() {
    inOrder(root);
    std::cout << std::endl;
}

// ---------------------------------------
void Binary_Search_Tree::search(int value) {
    bool isFounded = findKey2(root, value);

    if (isFounded) std::cout << value <<  " founded" << std::endl;
    else std::cout << value <<  " not founded" << std::endl;
}

// ---------------------------------------
void Binary_Search_Tree::remove(int value) {
    root = remove(value, root);
}