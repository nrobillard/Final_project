#include <iostream>
#include "splay.h"
#include <string>

Node::Node(){
    
}

Node::~Node(){
    
}


Splay_Tree::Splay_Tree(){
    root = nullptr;
}

Splay_Tree::~Splay_Tree(){
    
}

void Splay_Tree::preOrder(Node* node){    //preorder traversal
    if (node != nullptr){
        std::cout<<node->data<<" ";       //visit root node
        preOrder(node->left);             //visit left node
        preOrder(node->right);            //visit right node
    }
    
}

void Splay_Tree::inOrder(Node* node){     //inorder traversal
    if (node != nullptr) {
        inOrder(node->left);              //visit left node
        std::cout << node->data << " ";   //visit root node
        inOrder(node->right);             //visit right node
    }
}

void Splay_Tree::postOrder(Node* node){   //postorder traversal
    if (node != nullptr){
        postOrder(node->left);            //visit left node
        postOrder(node->right);           //visit right node
        std::cout << node->data << " ";   //visit root node
    }
    
}

void Splay_Tree::print(Node* root, std::string indent, bool lastNode){
    
}

void Splay_Tree::leftRotate(Node* a){    //roate tree left
    Node* b = a->left;
    a->left = b->right;
    if(b->right != nullptr){
        b->right->parent = a;
    }
    b->parent = a->parent;
    if(a->parent == nullptr){
        this->root = b;
    }
    else if (a == a ->parent->left){
        a->parent->left = b;
    }
    else {
        a->parent->right = b;
    }
    b->left = a;
    a->parent = b;
}

void Splay_Tree::rightRotate(Node* a){
    Node* b = a->left;
    a->left = b-> right;
    if(b->right != nullptr){
        b ->right->parent = a;
    }
    b->parent = a->parent;
    else if(a == a->parent->right){
        a->parent->right = b;
    }
    else{
        a->parent->left = b;
    }
    b->right = a;
    a->parent = b;
}

void Splay_Tree::splay(Node* x){
    
}

 
