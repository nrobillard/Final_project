#include <iostream>
#include "splay.h"
#include <string>

Node::Node(){
    
}


Splay::Splay(){
    root = nullptr;
}

void Splay::preOrder(Node* node){    //preorder traversal
    if (node != nullptr){
        std::cout<<node->data<<" ";       //visit root node
        preOrder(node->left);             //visit left node
        preOrder(node->right);            //visit right node
    }
    
}

void Splay::inOrder(Node* node){     //inorder traversal
    if (node != nullptr) {
        inOrder(node->left);              //visit left node
        std::cout << node->data << " ";   //visit root node
        inOrder(node->right);             //visit right node
    }
}

void Splay::postOrder(Node* node){   //postorder traversal
    if (node != nullptr){
        postOrder(node->left);            //visit left node
        postOrder(node->right);           //visit right node
        std::cout << node->data << " ";   //visit root node
    }
    
}

void Splay::printHelper(Node* root, std::string indent, bool last) {
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

//rotate tree left at given node a
void Splay::leftRotate(Node* a) {
	Node* b = a->right;
	a->right = b->left;
	if (b->left != nullptr) {
		b->left->parent = a;
	}
	b->parent = a->parent;
	if (a->parent == nullptr) {
		this->root = b;
	} else if (a == a->parent->left) {
		a->parent->left = b;
	} else {
		a->parent->right = b;
	}
	b->left = a;
	a->parent = b;
}

//rotate tree right at given node a
void Splay::rightRotate(Node* a) {
	Node* b = a->left;
	a->left = b->right;
	if (b->right != nullptr) {
		b->right->parent = a;
	}
	b->parent = a->parent;
	if (a->parent == nullptr) {
		this->root = b;
	} else if (a == a->parent->right) {
		a->parent->right = b;
	} else {
		a->parent->left = b;
	}
	b->right = a;
	a->parent = b;
}

//moves node to the root using rotations
void Splay::splay(Node* x) {
    //while the node still has a parent (not the root)
	while (x->parent) {
        //a single zig or zag rotations requires only one parent node above current node
		if (!x->parent->parent) {
			//zig rotation
			if (x == x->parent->left) {
				rightRotate(x->parent);
			
            //zag rotation
			} else {
				leftRotate(x->parent);
			}
       
		//zig-zig rotation
		} else if (x == x->parent->left && x->parent == x->parent->parent->left) {
			rightRotate(x->parent->parent);
			rightRotate(x->parent);
		//zag-zag rotation
		} else if (x == x->parent->right && x->parent == x->parent->parent->right) {
			leftRotate(x->parent->parent);
			leftRotate(x->parent);
		//zig-zag rotation
		} else if (x == x->parent->right && x->parent == x->parent->parent->left) {
			leftRotate(x->parent);
			rightRotate(x->parent);
		//zag-zig rotation
		} else {
			rightRotate(x->parent);
			leftRotate(x->parent);
		}
	}
}


// splits the tree into s and t
void Splay::split(Node* &x, Node* &s, Node* &t) {
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


void Splay::preorder() {
		preOrder(this->root);
	}


void Splay::inorder() {
		inOrder(this->root);
	}

void Splay::postorder() {
		postOrder(this->root);
	}

void Splay::insert(std::string node_data) {
		//insert new node, the process is the same as a normal BST insert
		Node* node = new Node;
        //set location to nullptr
		node->right = nullptr;
		node->left = nullptr;
		node->parent = nullptr;
        //set data to given data
		node->data = node_data;

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

		node->parent = y;
		if (y == nullptr) {
			root = node;
		} else if (node->data < y->data) {
			y->left = node;
		} else {
			y->right = node;
		}

		//Now splay the node
		splay(node);
	}


	// print the tree structure on the screen
	void Splay::prettyPrint() {
		printHelper(this->root, "", true);
	}

int main(){
	Splay obj;
	obj.insert("Tree");
	obj.insert("first");
	
	obj.prettyPrint();
	return 0;
}
