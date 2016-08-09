data_structures_tests.out: data_structures_tests.o | lib_data_structures.so wrappers.so
	cc -o $@ $< ./lib_data_structures.so ./wrappers.so

data_structures_tests.o: data_structures.h

lib_data_structures.so: queue.o
	cc -shared -o $@ $^

queue.o: queue.c data_structures.h
	cc -c -Wall -fPIC -o $@ $<

wrappers.so: wrappers.o
	cc -shared -o $@ $<

wrappers.o: wrappers.c wrappers.h
	cc -c -Wall -fPIC -o $@ $<
