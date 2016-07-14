library_objects = binary_search.c insertion_sort.c linear_search.c merge_sort.c quick_sort.c selection_sort.c

sorting_and_searching_mains.out: sorting_and_searching_mains.o | sorting_and_searching.so
	cc -o sorting_and_searching_mains.out sorting_and_searching_mains.o ./sorting_and_searching.so

sorting_and_searching_mains.o: sorting_and_searching.h
sorting_and_searching.so: $(library_objects)
	cc -shared -fPIC -o sorting_and_searching.so $(library_objects)
