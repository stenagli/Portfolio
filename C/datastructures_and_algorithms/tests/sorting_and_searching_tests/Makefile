vpath %.h $(HEADERDIR) # Set search directory for header files for Make

sorting_and_searching_tests.out: sorting_and_searching_tests.o | $(join $(LIBDIR),/libsorting_and_searching.so)
	$(CC) $(CFLAGS) -pthread -o $@ $< -lsorting_and_searching

sorting_and_searching_tests.o: sorting_and_searching_tests.c sorting_and_searching.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: $(join $(LIBDIR),/libsorting_and_searching.so)
$(join $(LIBDIR),/libsorting_and_searching.so):
	$(MAKE) -C $(join $(LIBDIR),/sorting_and_searching/)
