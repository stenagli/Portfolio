vpath %.h $(HEADERDIR) # Set search directory for header files for Make

graphs_tests.out: graphs_tests.o | $(join $(LIBDIR),/libgraphs.so) $(join $(LIBDIR),/libgraph_search.so)
	$(CC) $(CFLAGS) -o $@ $< -lgraphs -lgraph_search

graphs_tests.o: graphs_tests.c graphs.h graph_search.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: $(join $(LIBDIR),/libgraphs.so) $(join $(LIBDIR),/libgraph_search.so)
$(join $(LIBDIR),/libgraphs.so):
	$(MAKE) -C $(join $(LIBDIR),/graphs/)

$(join $(LIBDIR),/libgraph_search.so):
	$(MAKE) -C $(join $(LIBDIR),/graph_search/)
