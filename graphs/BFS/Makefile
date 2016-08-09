BFS_main.out: BFS_main.o | wrappers.so
	cc -o $@ $< ./wrappers.so

BFS_main.o: wrappers.h

wrappers.so: wrappers.o
	cc -shared -o $@ $^

wrappers.o: wrappers.c wrappers.h
	cc -c -Wall -fPIC -o $@ $<
