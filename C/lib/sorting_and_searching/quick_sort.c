#include "sorting_and_searching.h"

static int quicksort_partition(int A[], int p, int r){

	int pivot_element = A[r];

	/* p marks the first element in the Greater Than partition */
	for(int j = p; j < r; j++){
		if(A[j] < pivot_element){
			/* swap A[p] and A[j], then increment p */
			int temp = A[p];
			A[p++] = A[j];
			A[j] = temp;
		}		

	}

	/* swap first element in Greater Than partition with pivot_element */
	A[r] = A[p];
	A[p] = pivot_element;

	return p;

}

void quick_sort(int A[], int p, int r){
	while (p < r){ /* tail recursion on the larger partition */
		int q = quicksort_partition(A, p, r);
		if ((q-p) < (r-q)) {  /* if left < right */
			quick_sort(A, p, q-1);
			p = q + 1;
		}
		else {
			quick_sort(A, q + 1, r);
			r = q - 1;
		}
	}
}


void quick_sort_truncated(int A[], int p, int r){
	/* Helper function -- runs quicksort until partition size is less than K, then lets another sorting algorithm such as insertion_sort complete the sorting */
	while (r - p + 1 >= K){
		int q = quicksort_partition(A, p, r);

		if ((q-p) < (r-q)){ /* if left < right */
			if ((q-p) >= K) quick_sort_truncated(A, p, q-1);
			p = q + 1;
		}
		else{
			if ((r - q) >= K) quick_sort_truncated(A, q+1, r);
			r = q - 1;
		}
	}
}
