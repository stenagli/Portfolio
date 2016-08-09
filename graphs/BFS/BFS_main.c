#include <stdio.h>
#include "wrappers.h"
#define NUM_VERTICES 5 /* Number of vertices in the graph */

struct vertex_list_element {
	int vertex;
	struct vertex_list_element *next;
};


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
