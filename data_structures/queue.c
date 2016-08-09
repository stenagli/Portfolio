/* Placeholder for Queue library */

#include "wrappers.h"
#include "data_structures.h"
#include <stdio.h>

/* Linked List Queue */


struct Queue *init_queue(void){
	struct Queue *Q = Malloc(sizeof(*Q));
	Q->head = Q->tail = NULL;
	return Q;
}

static inline int is_empty(struct Queue *Q){
	return ((Q->head) == NULL ? 1 : 0);
}

void enqueue(struct Queue *Q, int n){
	/* enqueue to the tail */
	struct queue_element *current = Malloc(sizeof(*current));
	current->key = n;
	current->next = NULL;
	if (is_empty(Q))
		Q->head = Q->tail = current;
	else {
		(Q->tail)->next = current;
		Q->tail = current;
	}
	printf("Enqueued %d\n",n);
}

int dequeue(struct Queue *Q){
	/* dequeue from the head */
	if (is_empty(Q)){
		fprintf(stderr,"Attempted to dequeue empty queue\n");
		return -1;
	}
	else {
		struct queue_element *current = Q->head;
		int key = current->key;
		Q->head = current->next;
		free(current);
		printf("Dequeued %d\n",key);
		return key;
	}
}

void delete_queue(struct Queue *Q){
	while(!is_empty(Q))
		dequeue(Q);
	free(Q);
}
