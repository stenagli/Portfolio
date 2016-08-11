#ifndef BFS_H
#define BFS_H

#define NUM_VERTICES 5 /* Number of vertices in the graph */

struct vertex_list_element {
	int vertex;
	struct vertex_list_element *next;
};

#endif
