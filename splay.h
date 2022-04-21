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

    
    public:
        //contructor
        Splay_Tree(Node* node);
        void preOrder(Node* node);
        void inOrder(Node* node);
        void postOrder(Node* node);

        void printHelper(Node* root, std::string indent, bool last);
        void leftRotate(Node* x);
        void rightRotate(Node* x);

        void splay(Node* x);
        void split(Node* &x, Node* &a, Node* &b);

        void preorder();
        void inorder();
        void postorder();

        void insert(int key);
        void prettyPrint();

};


#endif
