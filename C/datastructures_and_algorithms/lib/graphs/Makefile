#IMPORTANT: This makefile should not be called directly; it is instead a target in other Makefiles

vpath %.h $(HEADERDIR) # Set search directory for header files for Make

$(join $(LIBDIR),/libgraphs.so): adj_list.o | $(join $(LIBDIR),/libwrappers.so)
	$(CC) $(CFLAGS) -shared -o $@ $< -lwrappers

adj_list.o: adj_list.c graphs.h
	$(CC) $(CFLAGS) -c -fPIC -o $@ $<

.PHONY: $(join $(LIBDIR),/libwrappers.so)
$(join $(LIBDIR),/libwrappers.so):
	$(MAKE) -C $(join $(LIBDIR),/wrappers/)
