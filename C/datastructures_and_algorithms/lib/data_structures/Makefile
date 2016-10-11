#IMPORTANT: This makefile should not be called directly; it is instead a target in other Makefiles

vpath %.h $(HEADERDIR) # Set search directory for header files for Make

objects = queue.o stack.o

$(join $(LIBDIR),/libdata_structures.so): $(objects) | $(join $(LIBDIR),/libwrappers.so)
	$(CC) $(CFLAGS) -shared -o $@ $(objects) -lwrappers

$(objects): %.o : %.c data_structures.h wrappers.h
	$(CC) $(CFLAGS) -c -fPIC -o $@ $<

.PHONY: $(join $(LIBDIR),/libwrappers.so)
$(join $(LIBDIR),/libwrappers.so):
	$(MAKE) -C $(join $(LIBDIR),/wrappers/)
