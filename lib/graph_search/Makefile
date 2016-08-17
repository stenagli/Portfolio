objects = BFS.o DFS.o

../libgraph_search.so: $(objects) | ../libdata_structures.so
	cc -shared -o $@ $(objects) -L../ -ldata_structures
.PHONY: ../libdata_structures.so

$(objects): %.o : %.c ../graphs/graphs.h ../data_structures/data_structures.h
	cc -c -Wall -fPIC -o $@ $<

../libdata_structures.so:
	$(MAKE) -C ../data_structures/
