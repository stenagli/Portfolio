#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <stdlib.h> /* for NULL definition */

struct list_element {
	int key;
	struct list_element *next;
};

struct Queue {
 	struct list_element *head;
	struct list_element *tail;
};

#define is_empty(Q)	((Q->head) == NULL ? 1 : 0)

struct Queue *init_queue(void);
void enqueue(struct Queue *Q, int n);
int dequeue(struct Queue *Q);
void delete_queue(struct Queue *Q);

#endif
