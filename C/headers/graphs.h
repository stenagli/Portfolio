#ifndef GRAPHS_H
#define GRAPHS_H

#define NUM_VERTICES 5 /* Number of vertices in the graph */

struct vertex_list_element {
	int vertex;
	struct vertex_list_element *next;
};

void add_edge(struct vertex_list_element *Adj[], int from, int to);
struct vertex_list_element **create_graph(void);
void print_graph(struct vertex_list_element *Adj[]);

#endif
