#include "sorting_and_searching.h"

void selection_sort(int A[], int length){
	int idx_smallest;
	int end = length - 1; /* index of last element */
	int temp;
	for(int i = 0; i < end; i++){
		idx_smallest = find_smallest(A, i, end);

		/* swap i and smallest */
		temp = A[i];
		A[i] = A[idx_smallest];
		A[idx_smallest] = temp;
	}
}

int find_smallest(int A[], int start, int end){
	int idx_smallest = start;
	int smallest = A[start];
	int cur;

	/* march forward with 'start' */
	while (++start <= end){
		if ((cur = A[start]) < smallest){
			idx_smallest = start;
			smallest = cur;
		}
	}
	return idx_smallest;
}
