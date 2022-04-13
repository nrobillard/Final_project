#ifndef Splay_H
#define Splay_H

#include <iostream>
#include <ostream>

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


};













#endif