#include <stdio.h>
#include "wrappers.h"
#include "BFS.h"


void add_edge(struct vertex_list_element *Adj[], int from, int to){
	struct vertex_list_element *v = Malloc(sizeof(*v));
	v->vertex = to;

	if (Adj[from] == NULL) {
		v->next = NULL;
		Adj[from] = v;
	}
	else { /* Create new vertex and add to beginning of list */
		v->next = Adj[from];
		Adj[from] = v;
	}
}


struct vertex_list_element **create_graph(void){
	/* Create Adj list and initialize to NULL */
	struct vertex_list_element **Adj = Malloc(sizeof(*Adj) * NUM_VERTICES); /* Array of pointers to data of type vertex_list_element */
	for (int i = 0; i < NUM_VERTICES; i++)
		Adj[i] = NULL;

	add_edge(Adj, 0, 4);
	add_edge(Adj, 0, 1);
	add_edge(Adj, 1, 3);
	add_edge(Adj, 1, 2);
	add_edge(Adj, 1, 4);
	add_edge(Adj, 1, 0);
	add_edge(Adj, 2, 3);
	add_edge(Adj, 2, 1);
	add_edge(Adj, 3, 2);
	add_edge(Adj, 3, 4);
	add_edge(Adj, 3, 1);
	add_edge(Adj, 4, 1);
	add_edge(Adj, 4, 0);
	add_edge(Adj, 4, 3);

	return Adj;
}


void print_graph(struct vertex_list_element *Adj[]){
	struct vertex_list_element *v;
	for (int i = 0; i < NUM_VERTICES; i++){
		printf("Edges from vertex %d:", i);
		v = Adj[i];

		while(v != NULL){
			printf(" %d", v->vertex); 
			v = v->next;
		}
		printf("\n");
	}
}


int main(void){
	struct vertex_list_element **Adj = create_graph();

	print_graph(Adj);

	return 0;
}
