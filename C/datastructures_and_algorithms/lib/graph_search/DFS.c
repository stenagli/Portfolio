#include "graphs.h"
#include "data_structures.h"
#include "graph_search.h"
#include <stdio.h>

void DFS(struct vertex_list_element **Adj, int source){

	char visited = 0; /* Bitmap denoting whether a vertex has been seen or not */

	int order_visited[NUM_VERTICES]; /* Order in which vertices were visited */

	struct Stack *S = init_stack();

	int num_visited = 0; /* Counter for number of vertices visited so far */

	push(S,source);
	while(!is_empty(S)){
		int current_vertex = pop(S);
		if(!is_visited(current_vertex)){
			/* If popped vertex has not been seen yet, process it */

			set_visited(current_vertex);
			order_visited[current_vertex] = ++num_visited;

			/* Push each unseen neighbor of current_vertex */
			for(struct vertex_list_element *neighbor = Adj[current_vertex]; neighbor != NULL; neighbor = neighbor->next){
				int neighbor_vertex = neighbor->vertex;
				if(!is_visited(neighbor_vertex))
					push(S,neighbor_vertex);
			}
		}
	}

	/* Print order_visited list */
	for(int i = 0; i < NUM_VERTICES; i++)
		printf("DFS: Visited vertex %d at time %d\n", i, order_visited[i]);
}
