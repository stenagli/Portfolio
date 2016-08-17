graphs_test.out: graphs_test.o | ../lib/libgraphs.so ../lib/libgraph_search.so
	cc -Wl,-rpath=../lib -o $@ $< -L../lib -lgraphs -lgraph_search
.PHONY: ../lib/libgraphs.so ../lib/libgraph_search.so

graphs_test.o: ../lib/graphs/graphs.h ../lib/graph_search/graph_search.h

../lib/libgraphs.so:
	$(MAKE) -C ../lib/graphs

../lib/libgraph_search.so:
	$(MAKE) -C ../lib/graph_search
