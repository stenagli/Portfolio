#IMPORTANT: This makefile should not be called directly; it is instead a target in other Makefiles

vpath %.h $(HEADERDIR) # Set search directory for header files for Make

$(join $(LIBDIR),/libwrappers.so): wrappers.o
	$(CC) $(CFLAGS) -shared -o $@ $^

wrappers.o: wrappers.c wrappers.h
	$(CC) $(CFLAGS) -c -fPIC -o $@ $<
