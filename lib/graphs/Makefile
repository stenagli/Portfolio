../libgraphs.so: adj_list.o | ../libwrappers.so
	cc -Wl,-rpath=../ -shared -o $@ $< -L../ -lwrappers

adj_list.o: adj_list.c graphs.h
	cc -c -fPIC -o $@ $<
