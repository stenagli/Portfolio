../libBFS.so: BFS.o | ../libdata_structures.so
	cc -shared -o $@ $< -L../ -ldata_structures

BFS.o: BFS.c ../graphs/graphs.h ../data_structures/data_structures.h
	cc -c -Wall -fPIC -o $@ $<

../libdata)structures.so:
	$(MAKE) -C ../data_structures/
