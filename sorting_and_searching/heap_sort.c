#include "sorting_and_searching.h"

static inline int parent(int i){
	return (((i+1)/2) - 1);
}


static inline int left(int i){
	return (2*(i + 1) - 1);
}


static inline int right(int i){
	return (2*(i + 1));
}


static void max_heapify(int A[], int index, int heap_size){
	for(;;){ /* Continue looping until heap property is satisfied and function returns */
		int l = left(index);
		int r = right(index);

		/* Save larger of A[l] and A[index] into l */
		l = (l < heap_size && A[l] > A[index]) ? l : index;

		/* Save larger of A[r] and A[l] into l */	
		l = (r < heap_size && A[r] > A[l]) ? r : l;

		if (l == index) return; /* Heap property satisfied, exit */

		/* Swap A[index] and A[l] */
		int temp = A[index];
		A[index] = A[l];
		A[l] = temp;
		/* Keep pushing the node down if necessary */
		/* max_heapify(A, l, heap_size); */
		index = l;
	}
}


static inline void build_max_heap(int A[], int heap_size){
	for(int index = (heap_size/2) - 1; index >= 0; index--){
		max_heapify(A, index, heap_size);
	}	

}

void heap_sort(int A[], int heap_size){
	build_max_heap(A, heap_size);

	int temp;
	for(int end = heap_size-1; end > 0; end--){
		/* Swap A[0] and A[end] */
		temp = A[end];
		A[end] = A[0];
		A[0] = temp;

		max_heapify(A, 0, --heap_size);
	}
}
