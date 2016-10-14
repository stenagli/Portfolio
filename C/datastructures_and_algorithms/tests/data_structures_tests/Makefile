vpath %.h $(HEADERDIR) # Set search directory for header files for Make

data_structures_tests.out: data_structures_tests.o | $(join $(LIBDIR),/libdata_structures.so)
	$(CC) $(CFLAGS) -o $@ $< -ldata_structures

data_structures_tests.o: data_structures_tests.c data_structures.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: $(join $(LIBDIR),/libdata_structures.so)
$(join $(LIBDIR),/libdata_structures.so):
	$(MAKE) -C $(join $(LIBDIR),/data_structures/)
