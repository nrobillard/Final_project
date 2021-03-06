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
	int count = 0;

    public:
        //contructor
        Splay();
        void preOrder(Node* node);
        void inOrder(Node* node);
        void postOrder(Node* node);
        Node* searchTreeHelper(Node* node, std::string key);

        void printHelper(Node* root, std::string indent, bool set, std::string output, std::ofstream &out);
        void leftRotate(Node* x);
        void rightRotate(Node* x);

        void splay(Node* x);
        void split(Node* &x, Node* &a, Node* &b);

        void preorder();
        void inorder();
        void postorder();

        void insert(std::string key);
        void prettyPrint(std::string output, std::ofstream &out);

        Node* searchTree(std::string k);

};


#endif
