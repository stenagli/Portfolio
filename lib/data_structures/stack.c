#include "data_structures.h"
#include "../wrappers/wrappers.h"
#include <stdio.h>

struct Stack *init_stack(void){
	struct Stack *S = Malloc(sizeof(*S));
	S->head = NULL;
	return S;
}

void push(struct Stack *S, int n){
	struct list_element *new = Malloc(sizeof(*new));
	new->key = n;
	new->next = S->head;
	S->head = new;
}

int pop(struct Stack *S){
	if (is_empty(S)){
		fprintf(stderr, "Attempted to pop empty stack\n");
		return -1;
	}
	else {
		int key = (S->head)->key;
		struct list_element *popped_element = S->head;
		S->head = popped_element->next;
		free(popped_element);
		return key;
	}
}

void delete_stack(struct Stack *S){
	while(!is_empty(S))
		pop(S);
	free(S);
}
