//
// Created by Aleksey Leshchankin on 05.12.2022.
//

#pragma once

#include <iostream>

class AVL_Tree{

private:
   struct node {
       int key;
       node* left;
       node* right;
       int height;
   };

   node* root;

   // ---------------------------------------
   node* newNode (int value) {
       node* rootNode = new node ();
       rootNode->key = value;
       rootNode->left = NULL;
       rootNode->right = NULL;
       rootNode->height = 1;

       return (rootNode);
   }

   // ---------------------------------------
   int height (node *rootNode) {
       if (rootNode == NULL)
           return 0;
       return rootNode->height;
   }

   // ---------------------------------------
   int max (int a, int b) {
       return (a > b) ? a : b;
   }

   // ---------------------------------------
   int getBalance (node *rootNode) {
       if (rootNode == NULL)
           return 0;
       return height(rootNode->left) - height(rootNode->right);
   }

   // ---------------------------------------
   node* rightRotate (node *y){
       node* x = y->left;
       node *T2 = x->right;

       x->right = y;
       y->left = T2;

       y->height = max (height(y->left), height(y->right)) + 1;
       x->height = max (height(x->left), height(x->right)) + 1;

       return x;
   }

   // ---------------------------------------
   node* leftRotate (node *x){
       node* y = x->right;
       node *T2 = y->left;

       y->left = x;
       x->right = T2;

       x->height = max (height(x->left), height(x->right)) + 1;
       x->height = max (height(y->left), height(y->right)) + 1;

       return y;
   }

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
        return (newNode(value));
       }
       else if (value < rootNode->key)
           rootNode->left = insert(value, rootNode->left);
       else if (value > rootNode->key)
           rootNode->right = insert(value, rootNode->right);

       rootNode->height = 1 + max (height(rootNode->left), height(rootNode->right));

       int balance = getBalance(rootNode);

       // left left
       if (balance > 1 && value < rootNode->left->key)
           return rightRotate(rootNode);
       // left right
       if (balance > 1 && value > rootNode->left->key) {
           rootNode->left = leftRotate(rootNode->left);
           return rightRotate(rootNode);
       }
       // right right
       if (balance < -1 && value > rootNode->right->key)
           return leftRotate(rootNode);
       // right left
       if (balance < -1 && value < rootNode->right->key) {
           rootNode->right = rightRotate(rootNode->right);
           return rightRotate(rootNode);
       }

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
   void preOrder(node* rootNode)
    {
        if(rootNode != NULL)
        {
            std::cout << rootNode->key << " ";
            preOrder(rootNode->left);
            preOrder(rootNode->right);
        }
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

       int balance = getBalance(rootNode);
       // left left
       if (balance > 1 && getBalance(rootNode->left) >= 0)
           return rightRotate(rootNode);
       // left right
       if (balance > 1 && getBalance(rootNode->left) < 0){
           rootNode->left = leftRotate(root->left);
           return rightRotate(rootNode);
       }
       // right right
       if (balance < -1 && getBalance(root->right) <= 0 )
           return leftRotate(rootNode);
       //right left
       if (balance < -1 && getBalance(rootNode->right) > 0) {
           rootNode->right = rightRotate(rootNode->right);
           return leftRotate(rootNode);
       }
       return rootNode;
   }

public:

    AVL_Tree();
    ~AVL_Tree();

    void insert (int value);
    void print ();
    void search (int value);
    void remove (int value);

};

// ---------------------------------------
// -- Constructor ------------------------
AVL_Tree::AVL_Tree() {
   root = NULL;
}

// -- Destructor -------------------------
AVL_Tree::~AVL_Tree(){
    root = clear(root);
}

// ---------------------------------------
void AVL_Tree::insert(int value) {
    root = insert (value, root);
}

// ---------------------------------------
void AVL_Tree::print() {
    inOrder(root);
    std::cout << std::endl;
}

// ---------------------------------------
void AVL_Tree::search(int value) {
    root = findKey(root, value);

    if (root) std::cout << value <<  " founded" << std::endl;
    else std::cout << value <<  " not founded" << std::endl;
}

// ---------------------------------------
void AVL_Tree::remove(int value) {
    root = remove(value, root);
}