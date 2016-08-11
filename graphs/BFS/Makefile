BFS_main.out: BFS_main.o | ../../lib/libwrappers.so
	cc -o $@ $< -L../../lib -lwrappers

BFS_main.o: ../../lib/wrappers/wrappers.h

../../lib/libwrapper.so:
	$(MAKE) -C ../../lib/wrappers
