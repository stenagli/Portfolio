#include "binary_search_tree.h"
#include <iostream>

int main(void){
	binary_search_tree<int> tree;
	tree.insert(15);
	tree.insert(4);
	tree.print();
	if(tree.find(4) != true) std::cout << "Find error" << std::endl;
	return 0;	
}
