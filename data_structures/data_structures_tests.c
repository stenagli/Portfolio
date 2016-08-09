#include "data_structures.h"

int main(){
	struct Queue *Q = init_queue();
	enqueue(Q,4);
	enqueue(Q, 3);
	dequeue(Q);
	enqueue(Q, 8);
	for (int i = 0; i < 3; i++)
		dequeue(Q);	
	delete_queue(Q);
	return 0;
}
