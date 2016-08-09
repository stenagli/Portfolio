#define NUM_VERTICES 5 /* Number of vertices in the graph */

struct vertex_list_element {
	int vertex;
	struct vertex_list_element *next;
};
