#include "../lib/graphs/graphs.h"
#include "../lib/BFS/BFS.h"

int main(void){
	struct vertex_list_element **Adj = create_graph();

	print_graph(Adj);

	BFS(Adj,0);

	return 0;
}
