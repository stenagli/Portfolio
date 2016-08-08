#include <stdio.h>
#define NUM_VERTICES 5 /* Number of vertices in the graph */

struct vertex_list_element {
	int vertex;
	vertex_list_element *next;
}

vertex_list_element **create_graph(void){
	/* Create Adj list and initialize to NULL */
	vertex_list_element *Adj[NUM_VERTICES]; /* Array of pointers to data of type vertex_list_element */
	for (int i = 0; i < NUM_VERTICES; i++)
		Adj[i] = NULL;

	add_edge(Adj, 0, 4);
	add_edge(Adj, 0, 1)

	return Adj;
}

void add_edge(vertex_list_element *Adj[], int from, int to){
	if (Adj[from] == NULL) {
		vertex_list_element *v = {to, NULL};
		Adj[from] = v;
	}
	else { /* Create new vertex and add to beginning of list */
		vertex_list_element *v = {to, Adj[from]};
		Adj[from] = v;
	}
}

void print_graph(vertex_list_element *Adj[]){
	for (int i = 0; i < NUM_VERTICES; i++){
		printf("Edges from vertex %d:", i);
		vertex_list_element *v = Adj[i];

		while(v != NULL){
			printf(" %d", v->vertex); 
			v = v->next;
		}
		printf("\n";
	}
}
int main(void){
	vertex_list_element **Adj = create_graph();

	print_graph(Adj);

	return;
}
