#IMPORTANT: This makefile should not be called directly; it is instead a target in other Makefiles

vpath %.h $(HEADERDIR) # Set search directory for header files for Make

objects = BFS.o DFS.o

$(join $(LIBDIR),libgraph_search.so): $(objects) | $(join $(LIBDIR),/libdata_structures.so)
	$(CC) $(CFLAGS) -shared -o $@ $(objects) -ldata_structures

$(objects): %.o : %.c graphs.h data_structures.h graph_search.h
	$(CC) $(CFLAGS) -c -fPIC -o $@ $<

.PHONY: $(join $(LIBDIR),/libdata_structures.so)
$(join $(LIBDIR),/libdata_structures.so):
	$(MAKE) -C $(join $(LIBDIR),/data_structures/)
