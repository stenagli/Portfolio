#include <stdio.h>
#include "sorting_and_searching.h"
#define A_SIZE	8
#define VALUE 	7

/* function prototypes */
void reinitialize_a(int A[]);
void print_array(int A[], int size);


int main(){

	/* Binary Search */
	int A[A_SIZE];
	for(int i = 0; i < A_SIZE; i++)
		A[i] = i;

	int idx = binary_search(A, 0, A_SIZE-1, VALUE);
	printf("Index of value %d: %d\n", VALUE, idx);
	printf("Value at index %d: %d\n", idx, A[idx]);


	/* Linear Search */
	reinitialize_a(A);
	int index = linear_search(A, A_SIZE, VALUE);
	printf("Index of value %d: %d\n", VALUE, index);
	if (index >= 0)
		printf("Value at that index: %d\n", A[index]);


	/* Insertion Sort */
	reinitialize_a(A);
	insertion_sort_recursive(A, A_SIZE);
	print_array(A, A_SIZE);

	
	/* Merge Sort */
	reinitialize_a(A);

	merge_sort(A, 0, A_SIZE - 1);	

		/* test merge */
	print_array(A, A_SIZE);


	/* Selection Sort */
	reinitialize_a(A);

	int idx_s = find_smallest(A, 0, A_SIZE-1);
	printf("Index of smallest: %d\nValue at smallest: %d\n", idx_s, A[idx_s]);

	selection_sort(A, A_SIZE);

	print_array(A, A_SIZE);


	/* Quicksort */
	printf("Quicksort\n");
	reinitialize_a(A);

	quick_sort(A, 0, A_SIZE-1);
	print_array(A, A_SIZE);



	return 0;
}


void reinitialize_a(int A[]){
	A[0] = 8;
	A[1] = 6;
	A[2] = 4;
	A[3] = 2;
	A[4] = 7;
	A[5] = 5;
	A[6] = 3;
	A[7] = 1;
}


void print_array(int A[], int size){
	for(int i = 0; i < size-1;i++)
		printf("%d, ",A[i]);
	printf("%d\n", A[size-1]);
}
