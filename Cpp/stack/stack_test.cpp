#include <iostream>
#include "stack.h"

using namespace my_stack_implementation;

inline void run_tests(Stack<int>* s){
	if(s->is_empty() == false) std::cout << "is_empty error" << std::endl;
	for(int i = 0; i < 100; i++)
		s->push(i);
	if(s->is_empty() == true) std::cout << "is_empty error" << std::endl;
	if(s->pop() != 99) std::cout << "Pop error" << std::endl;
	for(int i = 0; i < 98; i++)
		s->pop();
	if(s->pop() != 0) std::cout << "Pop error 2" << std::endl;
	if(s->pop() != -1) std::cout << "empty Pop error" << std::endl;
}

int main(){
	/* Force the abstraction; make sure to delete later */
	Stack<int>* s = new LinkedList_Stack<int>();
	run_tests(s);
	delete s;

	s = new DynamicArray_Stack<int>();
	run_tests(s);
	delete s;

	return 0;
}
