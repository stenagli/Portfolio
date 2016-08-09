#include "BFS.h"

#define setVisited(x)	(visited |= (1 << x)) /* Set bit x in 'visited' bitfield to 1 */


void BFS(vertex_list_element **Adj, int source){
	char visited = 0; /* Bitfield to determine whether a vertex has been visited or not */

	int distance[NUM_VERTICES]; /* Distance of each vertex from the source */


	setVisited(source);
	distance[source] = 0;

}
