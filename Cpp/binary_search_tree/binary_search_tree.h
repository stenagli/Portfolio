/* Include Guard */
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream> /* For inorder_tree_walk() */

template<typename T>
class binary_search_tree {
public:
	binary_search_tree();
	binary_search_tree<T>& print();
	binary_search_tree<T>& insert(T key);
	// binary_search_tree& remove(T key);
	binary_search_tree<T>& find(T key);
private:
	class tree_node {
	public:
		/*
		tree_node* get_parent();
		tree_node* get_left();
		tree_node* get_right();	
		T get_key();
		*/
		tree_node* parent;
		tree_node* left;
		tree_node* right;
		T key;

		tree_node(tree_node* p, tree_node* l, tree_node* r, T k);
		tree_node& inorder_tree_walk();
	private:
		/*
		tree_node* parent;
		tree_node* left;
		tree_node* right;
		T key;
		*/
	};

	int size;
	tree_node* root;
};



/* Function definitions */

/* Binary Search Tree */
template<typename T>
binary_search_tree<T>::binary_search_tree()
	:size{0}, root{nullptr} {}

template<typename T>
binary_search_tree<T>& binary_search_tree<T>::insert(T key){
	/* Determine where the new node should be */
	tree_node* y {nullptr};
	tree_node* x {root};

	while(x != nullptr){
		y = x;
		x = key < x->key ? x->left : x->right;
	}

	/* Create the new node and insert it */
	tree_node* z = new tree_node{y, nullptr, nullptr, key};
	if (y == nullptr)
		root = z;
	else if (key < y->key)
		y->left = z;
	else
		y->right = z;

	return *this;
}

template<typename T>
binary_search_tree<T>& binary_search_tree<T>::print(){
	/* Prints the tree in sorted order */
	if (root != nullptr)	
		root->inorder_tree_walk();

	return *this;
}


/* Tree Node */
template<typename T>
binary_search_tree<T>::tree_node::tree_node(tree_node* p, tree_node* l, tree_node* r, T k)
	:parent{p}, left{l}, right{r}, key{k} {}


template<typename T>
typename binary_search_tree<T>::tree_node& binary_search_tree<T>::tree_node::inorder_tree_walk(){
	if (left != nullptr)
		left->inorder_tree_walk();

	std::cout << key << std::endl;

	if (right != nullptr)
		right->inorder_tree_walk();

	return *this;
}

#endif
