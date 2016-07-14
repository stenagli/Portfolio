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
	if (p < r){
		int q = quicksort_partition(A, p, r);
		quick_sort(A, p, q-1);
		quick_sort(A, q+1, r);
	}
}
