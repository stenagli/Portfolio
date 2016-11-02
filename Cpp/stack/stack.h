/* Include guard */
#ifndef STACK_H
#define STACK_H

#include <vector> /* for DynamicArray_Stack implementation */

namespace my_stack_implementation {
template<typename T>
class Stack {
	public:
		virtual bool is_empty() = 0;
		virtual Stack<T>& push(T key) = 0;
		virtual T pop() = 0;
		virtual ~Stack() {}
};

template<typename T>
class LinkedList_Stack : public Stack<T> {
	public:
		bool is_empty();
		Stack<T>& push(T key);
		T pop();
		LinkedList_Stack();
		~LinkedList_Stack();
	private:
		class LinkedListNode {
		public:
			T key;
			LinkedListNode* next;

			LinkedListNode(T k, LinkedListNode* n);
		};
		LinkedListNode* head;
		int size;
};


template<typename T>
bool LinkedList_Stack<T>::is_empty(){
	return (size > 0) ? false : true;	
}

template<typename T>
Stack<T>& LinkedList_Stack<T>::push(T key){
	LinkedListNode* new_node = new LinkedListNode(key, head);
	head = new_node;
	size++;
	return *this;	
}

template<typename T>
T LinkedList_Stack<T>::pop(){
	if(is_empty()){
		std::cout << "Error: Stack is empty, cannot pop" << std::endl;
		return -1;
	}
	else {
		T key = head->key;
		LinkedListNode* next = head->next;
		delete head;
		head = next;
		size--;
		return key;
	}
}

template<typename T>
LinkedList_Stack<T>::LinkedList_Stack()
	:head{nullptr}, size{0} {}

template<typename T>
LinkedList_Stack<T>::~LinkedList_Stack(){
	while(!is_empty())
		pop();
}


template<typename T>
LinkedList_Stack<T>::LinkedListNode::LinkedListNode(T k, LinkedListNode* n)
			:key{k}, next{n} {};


/* DynamicArray_Stack */
template<typename T>
class DynamicArray_Stack : public Stack<T> {
	public:
		bool is_empty();
		Stack<T>& push(T key);
		T pop();
		DynamicArray_Stack();
		~DynamicArray_Stack();
	private:
	/* Use a std::vector to implement the dynamic array */
		std::vector<T> arr;
};

template<typename T>
bool DynamicArray_Stack<T>::is_empty(){
	return arr.empty();
}

template<typename T>
Stack<T>& DynamicArray_Stack<T>::push(T key){
	arr.push_back(key);
	return *this;
}

template<typename T>
T DynamicArray_Stack<T>::pop(){
	if(is_empty()){
		std::cout << "Error: Stack is empty, cannot pop" << std::endl;
		return -1;
	}
	else {
		T k = arr.back();
		arr.pop_back();
		return k;
	}
}

template<typename T>
DynamicArray_Stack<T>::DynamicArray_Stack(){}

template<typename T>
DynamicArray_Stack<T>::~DynamicArray_Stack(){}

}

#endif
