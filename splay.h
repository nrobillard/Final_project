#ifndef Splay_H
#define Splay_H

#include <iostream>
#include <ostream>
#include <string>

class Node
{
    private:
        std::string data; // holds the key
	    Node *parent; // pointer to the parent
	    Node *left; // pointer to left child
	    Node *right; // pointer to right child

    public:
        Node();
    friend class Splay;
};

class Splay
{
    private:
        Node* root;

    
    public:
        //contructor
        Splay();
        void preOrder(Node* node);
        void inOrder(Node* node);
        void postOrder(Node* node);

        void printHelper(Node* root, std::string indent, bool last);
        void leftRotate(Node* a);
        void rightRotate(Node* a);

        void splay(Node* x);
        void split(Node* &x, Node* &a, Node* &b);

        void preorder();
        void inorder();
        void postorder();

        void insert(std::string node_data);
        void prettyPrint();

};


#endif
