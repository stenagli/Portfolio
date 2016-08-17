#ifndef GRAPH_SEARCH_H
#define GRAPH_SEARCH_H


#define set_visited(x)	(visited |= (1 << x)) /* Set bit x in 'visited' bitfield to 1 */
#define is_visited(x)	(visited & (1 << x)) /* Has vertex x been visited yet? */


void BFS(struct vertex_list_element **Adj, int source);
void DSF(struct vertex_list_element **Adj, int source);

#endif
