$(LIBDIR)/libwrappers.so: wrappers.o
	cc -shared -o $@ $^

wrappers.o: wrappers.c wrappers.h
	cc -c -fPIC -o $@ $<
