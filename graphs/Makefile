graphs_test.out: graphs_test.o | ../lib/libgraphs.so ../lib/libBFS.so
	cc -Wl,-rpath=../lib -o $@ $< -L../lib -lgraphs -lBFS

graphs_test.o: ../lib/graphs/graphs.h ../lib/BFS/BFS.h

../lib/libgraphs.so:
	$(MAKE) -C ../lib/graphs

../lib/libBFS.so:
	$(MAKE) -C ../lib/BFS
