#include <stdio.h>
#include "sorting_and_searching.h"
#define A_SIZE	8
#define VALUE 	7

int main(){

	/* Binary Search */
	int A[A_SIZE];
	for(int i = 0; i < A_SIZE; i++)
		A[i] = i;

	int idx = binary_search(A, 0, A_SIZE-1, VALUE);
	printf("Index of value %d: %d\n", VALUE, idx);
	printf("Value at index %d: %d\n", idx, A[idx]);


	/* Linear Search */
	int A[A_SIZE] = {8, 6, 4, 2, 7, 5, 3, 1};
	int index = linear_search(A, A_SIZE, VALUE);
	printf("Index of value %d: %d\n", VALUE, index);
	if (index >= 0)
		printf("Value at that index: %d\n", A[index]);


	/* Insertion Sort */
	int A[A_SIZE] = {8, 6, 4, 2, 7, 5, 3, 1};
	insertion_sort_recursive(A, A_SIZE);
	for(int i = 0; i < A_SIZE-1; i++)
		printf("%d, ", A[i]);
	printf("%d\n", A[A_SIZE-1]);

	
	/* Merge Sort */
	int A[A_SIZE] = {8, 6, 4, 2, 7, 5, 3, 1};

	merge_sort(A, 0, A_SIZE - 1);	

		/* test merge */
	for(int i = 0; i < A_SIZE; i++)
		printf("%d\n",A[i]);


	/* Selection Sort */
	int A[A_SIZE] = {8, 6, 4, 2, 7, 5, 3, 1};

	int idx_s = find_smallest(A, 0, A_SIZE-1);
	printf("Index of smallest: %d\nValue at smallest: %d\n", idx_s, A[idx_s]);

	selection_sort(A, A_SIZE);

	for(int i = 0; i < A_SIZE-1;i++)
		printf("%d, ",A[i]);
	printf("%d\n", A[A_SIZE-1]);





	return 0;
}
