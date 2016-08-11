#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <stdlib.h> /* for NULL definition */

struct queue_element {
	int key;
	struct queue_element *next;
};

struct Queue {
 	struct queue_element *head;
	struct queue_element *tail;
};

struct Queue *init_queue(void);
void enqueue(struct Queue *Q, int n);
int dequeue(struct Queue *Q);
void delete_queue(struct Queue *Q);

#endif
