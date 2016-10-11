vpath %.h $(HEADERDIR) # Set search directory for header files for Make

$(join $(LIBDIR),/libwrappers.so): wrappers.o
	$(CC) $(CFLAGS) -shared -o $@ $^

wrappers.o: wrappers.c wrappers.h
	$(CC) $(CFLAGS) -c -fPIC -o $@ $<
