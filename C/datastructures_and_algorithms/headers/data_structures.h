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

struct Stack {
	struct list_element *head;
};

#define is_empty(Q)	((Q->head) == NULL ? 1 : 0)

struct Queue *init_queue(void);
void enqueue(struct Queue *Q, int n);
int dequeue(struct Queue *Q);
void delete_queue(struct Queue *Q);


struct Stack *init_stack(void);
void push(struct Stack *S, int n);
int pop(struct Stack *S);
void delete_stack(struct Stack *S);

#endif
