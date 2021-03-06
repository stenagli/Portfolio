#include "sorting_and_searching.h"

void insertion_sort(int A[], int length){
	for(int j = 1; j < length; j++){
		int key = A[j];
		int i = j - 1;
		int A_cur;
		while (i >= 0 && (A_cur = A[i]) > key){
			A[i+1] = A_cur;
			i--;
		}
		A[i+1] = key;
	}
}

void insertion_sort_recursive(int A[], int length){
	if (length <= 1) return;

	insertion_sort_recursive(A, length-1);

	/* insert last element */
	int key = A[--length];
	int A_cur;
	while (--length >= 0 && (A_cur = A[length]) > key){
		A[length+1] = A_cur;
	}
	A[length+1] = key;
}
