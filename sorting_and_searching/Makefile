library_objects = binary_search.o insertion_sort.o linear_search.o merge_sort.o quick_sort.o selection_sort.o

sorting_and_searching_mains.out: sorting_and_searching_mains.o | sorting_and_searching.so
	cc -o $@ sorting_and_searching_mains.o ./sorting_and_searching.so

sorting_and_searching_mains.o: sorting_and_searching.h
sorting_and_searching.so: $(library_objects)
	cc -shared -o $@ $(library_objects)
$(library_objects): %.o: %.c sorting_and_searching.h
	cc -c -fPIC -o $@ $<
