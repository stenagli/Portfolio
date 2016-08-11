../libdata_structures.so: queue.o | ../libwrappers.so
	cc -shared -o $@ $< -L../ -lwrappers

../libwrappers.so:
	$(MAKE) -C ../wrappers/

queue.o: queue.c data_structures.h
	cc -c -Wall -fPIC -o $@ $<
