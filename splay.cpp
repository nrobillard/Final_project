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

void Splay_Tree::printHelper(Node* root, std::string indent, bool last) {
		// print the tree structure on the screen
	   	if (root != nullptr) {
		   std::cout<<indent;
		   if (last) {
		      std::cout<<"└────";
		      indent += "     ";
		   } else {
		      std::cout<<"├────";
		      indent += "|    ";
		   }

		   std::cout<<root->data<<std::endl;

		   printHelper(root->left, indent, false);
		   printHelper(root->right, indent, true);
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

	void Splay_Tree::splay(Node* x) {
		while (x->parent) {
			if (!x->parent->parent) {
				if (x == x->parent->left) {
					// zig rotation
					rightRotate(x->parent);
				} else {
					// zag rotation
					leftRotate(x->parent);
				}
			} else if (x == x->parent->left && x->parent == x->parent->parent->left) {
				// zig-zig rotation
				rightRotate(x->parent->parent);
				rightRotate(x->parent);
			} else if (x == x->parent->right && x->parent == x->parent->parent->right) {
				// zag-zag rotation
				leftRotate(x->parent->parent);
				leftRotate(x->parent);
			} else if (x == x->parent->right && x->parent == x->parent->parent->left) {
				// zig-zag rotation
				leftRotate(x->parent);
				rightRotate(x->parent);
			} else {
				// zag-zig rotation
				rightRotate(x->parent);
				leftRotate(x->parent);
			}
		}
	}


	// splits the tree into s and t
void Splay_Tree::split(Node* &x, Node* &s, Node* &t) {
	splay(x);
	if (x->right) {
		t = x->right;
		t->parent = nullptr;
	} else {
		t = nullptr;
	}
	s = x;
	s->right = nullptr;
	x = nullptr;
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

void Splay_Tree::insert(int key) {
		// normal BST insert
		Node* node = new Node;
		node->parent = nullptr;
		node->left = nullptr;
		node->right = nullptr;
		node->data = key;
		Node* y = nullptr;
		Node* x = this->root;

		while (x != nullptr) {
			y = x;
			if (node->data < x->data) {
				x = x->left;
			} else {
				x = x->right;
			}
		}

		// y is parent of x
		node->parent = y;
		if (y == nullptr) {
			root = node;
		} else if (node->data < y->data) {
			y->left = node;
		} else {
			y->right = node;
		}

		// splay the node
		splay(node);
	}


	// print the tree structure on the screen
	void Splay_Tree::prettyPrint() {
		printHelper(this->root, "", true);
	}

int main(){
	Splay_Tree bst;
	bst.insert(33);
	bst.insert(44);
	bst.insert(67);
	bst.insert(5);
	bst.insert(89);
	bst.insert(41);
	bst.insert(98);
	bst.insert(1);
	bst.prettyPrint();
	return 0;
}
