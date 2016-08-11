graphs_test.out: graphs_test.o | ../lib/libgraphs.so
	cc -Wl,-rpath=../lib -o $@ $< -L../lib -lgraphs

graphs_test.o: ../lib/graphs/graphs.h

../lib/libgraphs.so:
	$(MAKE) -C ../lib/graphs

