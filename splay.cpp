#include <iostream>
#include "splay.h"
#include <string>

Node::Node(){
    
}

Node::~Node(){
    
}


Splay_Tree::Splay_Tree(Node* node){
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

	// rotate left at node x
	void Splay_Tree::leftRotate(Node* x) {
		Node* y = x->right;
		x->right = y->left;
		if (y->left != nullptr) {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		} else if (x == x->parent->left) {
			x->parent->left = y;
		} else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}

	// rotate right at node x
	void Splay_Tree::rightRotate(Node* x) {
		Node* y = x->left;
		x->left = y->right;
		if (y->right != nullptr) {
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		} else if (x == x->parent->right) {
			x->parent->right = y;
		} else {
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}


void Splay_Tree::preorder() {
		preOrder(this->root);
	}


void Splay_Tree::inorder() {
		inOrder(this->root);
	}

void Splay_Tree::postorder() {
		postOrder(this->root);
	}

