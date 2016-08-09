/* Placeholder for Queue library */

#include "wrapper.h"

/* Linked List Queue */

struct queue_element {
	int key;
	queue_element *next;
};

struct Queue {
	queue_element *head;
	queue_element *tail;
};


struct Queue *init_queue(void){
	struct Queue *Q = Malloc(sizeof(*Q));
	Q->head = Q->tail = NULL;
	return Q;
}


void enqueue(Queue *Q, int n){
	/* enqueue to the tail */
	queue_element *current = Malloc(sizeof(*current));
	current->key = n;
	current->next = NULL;
	if (is_empty(Q))
		Q->head = Q->tail = current;
	else
		(Q->tail)->next = current;
}

int dequeue(Queue *Q){
	/* dequeue from the head */
	if (is_empty(Q))
		fprintf(stderr,"Attempted to dequeue empty queue");
	else {
		struct queue_element *current = Q->head;
		int key = current->key;
		Q->head = current->next;
		free(current);
		return key;
	}
}

inline int is_empty(Queue *Q){
	return ((Q->head) == NULL ? 1 : 0);
}

void delete_queue(Queue *Q){
	while(!is_empty(Q))
		dequeue(Q);
	free(Q);
}
