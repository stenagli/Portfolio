#include "binary_search_tree.h"

int main(void){
	binary_search_tree<int> tree;
	tree.insert(15);
	tree.insert(4);
	tree.print();
	return 0;	
}
