objects = queue.o stack.o

../libdata_structures.so: $(objects) | ../libwrappers.so
	cc -shared -o $@ $(objects) -L../ -lwrappers
.PHONY: ../libwrappers.so

../libwrappers.so:
	$(MAKE) -C ../wrappers/

$(objects): %.o : %.c data_structures.h ../wrappers/wrappers.h
	cc -c -Wall -fPIC -o $@ $<
