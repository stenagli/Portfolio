#include <stdio.h>
#define A_SIZE 8

/* function prototypes */
void insertion_sort(int A[], int length);

int main(){
	int A[A_SIZE] = {8, 6, 4, 2, 7, 5, 3, 1};

	insertion_sort(A, A_SIZE);

	for(int i = 0; i < A_SIZE-1; i++)
		printf("%d, ", A[i]);
	printf("%d\n", A[A_SIZE-1]);

	return 0;
}


void insertion_sort(int A[], int length){
	for(int j = 1; j < length; j++){
		int key = A[j];
		int i = j - 1;
		while (i >= 0 && A[i] > key){
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
	}
}
