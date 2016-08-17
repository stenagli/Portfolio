#include "../graphs/graphs.h"
#include "../data_structures/data_structures.h"
#include "graph_search.h"
#include <stdio.h>


void BFS(struct vertex_list_element **Adj, int source){
	char visited = 0; /* Bitfield to determine whether a vertex has been visited or not */

	int distance[NUM_VERTICES]; /* Distance of each vertex from the source */


	set_visited(source);
	distance[source] = 0;

	struct Queue *Q = init_queue();
	enqueue(Q,source);

	int current;
	int vte_key;
	while (!is_empty(Q)){
		current = dequeue(Q);
		
		/* For each edge from current */
		struct vertex_list_element *vle = Adj[current];
		while (vle != NULL){
			vte_key = vle->vertex;
			if (!is_visited(vte_key)){
				set_visited(vte_key);
				distance[vte_key] = distance[current] + 1;
				enqueue(Q,vte_key);
			}
			vle = vle->next;
		}
	}
	/* Print the distance array for testing purposes */
	for (int i = 0; i < NUM_VERTICES; i++){
		printf("Distance of vertex %d from source: %d\n", i, distance[i]);
	}
}
