#include "../lib/graphs/graphs.h"
#include "../lib/graph_search/graph_search.h"

int main(void){
	struct vertex_list_element **Adj = create_graph();

	print_graph(Adj);

	BFS(Adj,0);

	DFS(Adj,0);

	return 0;
}
