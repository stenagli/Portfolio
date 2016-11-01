template<typename T>
class Stack {
	public:
		virtual bool is_empty() = 0;
		virtual Stack& push(T key) = 0;
		virtual T pop() = 0;
		virtual ~Stack();
};

template<typename T>
class LinkedList_Stack : public Stack {
	public:
		bool is_empty();
		Stack& push(T key);
		T pop();
		LinkedList_Stack();
		~LinkedList_Stack();
	private:
		class LinkedListNode {
		public:
			LinkedListNode* next;
			T key;

			LinkedListNode(T k, LinkedListNode* n)
				:key{k}, next{n} {};
		};
		LinkedListNode* head;
		int size;
};


template<typename T>
LinkedList_Stack<T>::bool is_empty(){
	return (size > 0) ? false : true;	
}

template<typename T>
LinkedList_Stack<T>::Stack& push(T key){
	LinkedListNode* new_node = new LinkedListNode(key, head);
	head = new_node;
	return *this;	
}

LinkedList_Stack<T>::T pop();
LinkedList_Stack<T>::LinkedList_Stack();
LinkedList_Stack<T>::~LinkedList_Stack();
