#IMPORTANT: This makefile should not be called directly; it is instead a target in other Makefiles

vpath %.h $(HEADERDIR) # Set search directory for header files for Make

library_objects = binary_search.o insertion_sort.o linear_search.o merge_sort.o quick_sort.o selection_sort.o quick_insertion_sort.o heap_sort.o

$(join $(LIBDIR),/libsorting_and_searching.so): $(library_objects)
	$(CC) $(CFLAGS) -shared -o $@ $(library_objects)

$(library_objects): %.o: %.c sorting_and_searching.h
	$(CC) $(CFLAGS) -c -fPIC -o $@ $<

# sorting_and_searching_mains.out: sorting_and_searching_mains.o | ../lib/libsorting_and_searching.so
#	cc -Wl,-rpath=../lib -pthread -o $@ sorting_and_searching_mains.o -L'../lib' -lsorting_and_searching

#sorting_and_searching_mains.o: sorting_and_searching.h
