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

Node* Splay::searchTreeHelper(Node* node, std::string key) {
		if (node == nullptr || key == node->data) {
			return node;
		}

		if (key < node->data) {
			return searchTreeHelper(node->left, key);
		} 
		return searchTreeHelper(node->right, key);
	}


	// rotate left at node x
void Splay::leftRotate(Node* x) {
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
void Splay::rightRotate(Node* x) {
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

	void Splay::splay(Node* x) {
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

void Splay::insert(std::string key) {
		// normal BST insert
		int count = 0;
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

		//count increments
		count++;
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


	Node* Splay::searchTree(std::string k) {
		Node* x = searchTreeHelper(this->root, k);
		if (x) {
			splay(x);
		}
		return x;
	}



	// print the tree structure on the screen
	void Splay::prettyPrint() {
		printHelper(this->root, "", true);
	}

int main(){
	Splay obj;
	obj.insert("Tree");
	obj.insert("firs");
	obj.insert("nut");
	obj.insert("glue");
	obj.searchTree("nut");
	obj.prettyPrint();
	return 0;
}
