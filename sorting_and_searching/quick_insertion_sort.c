#include "sorting_and_searching.h"

void quick_insertion_sort(int A[], int end){
	if ((end + 1) >= K)
		quick_sort_truncated(A, 0, end);
	insertion_sort(A, end); 
	return;
}
