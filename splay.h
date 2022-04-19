#ifndef Splay_H
#define Splay_H

#include <iostream>
#include <ostream>
#include <string>

class Node
{
    private:
        int data; // holds the key
	    Node *parent; // pointer to the parent
	    Node *left; // pointer to left child
	    Node *right; // pointer to right child

    public:
        Node();
        ~Node();
    friend class Splay_Tree;
};

class Splay_Tree
{
    private:
        Node* root;

        Node* searchTree(Node* node, int key);
        void print(Node* root, std::string indent, bool lastNode);
        void leftRotate(Node* x);
        void rightRotate(Node* x);
        void splay(Node* x);
        void split(Node* &x, Node* &a, Node* &b);
    public:
        //contructor
        Splay_Tree(Node* node);
        void preOrder(Node* node);
        void inOrder(Node* node);
        void postOrder(Node* node);
        void leftRotate(Node* x);
        void rightRotate(Node* x);

        void preorder();
        void inorder();
        void postorder();

        /*
        Node* serachTree(int k);
        Node* minimum(Node* node);
        Node* maximum(Node* node);
        Node* successor(Node* x);
        Node* predecessor(Node* x);
        Node* insert(int key);
        Node* getRoot();
        void delete_node(int data);
        void print();
        */
};


#endif
