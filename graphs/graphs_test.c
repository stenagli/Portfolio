#include "../lib/graphs/graphs.h"

int main(void){
	struct vertex_list_element **Adj = create_graph();

	print_graph(Adj);

	return 0;
}
