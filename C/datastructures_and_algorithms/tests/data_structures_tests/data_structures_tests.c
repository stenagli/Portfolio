#include "../lib/data_structures/data_structures.h"
#include <stdio.h>

int main(){
	struct Queue *Q = init_queue();
	enqueue(Q,4);
	enqueue(Q, 3);
	dequeue(Q);
	enqueue(Q, 8);
	for (int i = 0; i < 3; i++)
		dequeue(Q);	
	delete_queue(Q);
	
	printf("Queue testing complete\n");

	
	struct Stack *S = init_stack();
	push(S,4);
	push(S, 3);
	if(pop(S) != 3)
		fprintf(stderr,"Stack error: first pop\n");

	push(S, 8);
	if(pop(S) != 8)
		fprintf(stderr,"Stack error: second pop\n");


	if(pop(S) != 4)
		fprintf(stderr,"Stack error: third pop\n");
	if(pop(S) != -1)
		fprintf(stderr,"Stack error: fourth pop\n");

	delete_stack(S);

	printf("Stack testing complete\n");


	return 0;




}
