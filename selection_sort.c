#include <stdio.h>
#define A_SIZE 8

/* function prototypes */

void selection_sort(int A[], int length);
int find_smallest(int A[], int start, int end);

int main(){
	int A[A_SIZE] = {8, 6, 4, 2, 7, 5, 3, 1};

	int idx_s = find_smallest(A, 0, A_SIZE-1);
	printf("Index of smallest: %d\nValue at smallest: %d\n", idx_s, A[idx_s]);

	selection_sort(A, A_SIZE);

	for(int i = 0; i < A_SIZE-1;i++)
		printf("%d, ",A[i]);
	printf("%d\n", A[A_SIZE-1]);
	return 0;

}

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
