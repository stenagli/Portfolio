#include <stdio.h>
#define A_SIZE 8

/* function prototypse */
void merge_sort(int A[], int p, int r);
void merge(int A[], int p, int q, int r);


int main(){
	int A[A_SIZE] = {8, 6, 4, 2, 7, 5, 3, 1};

	merge_sort(A, 0, A_SIZE - 1);	

	/* test merge */
	for(int i = 0; i < A_SIZE; i++)
		printf("%d\n",A[i]);

	return 0;
}


void merge_sort(int A[], int p, int r){
	if (p < r){
		int q = (r+p)/2;
		merge_sort(A, p, q);
		merge_sort(A, q+1, r);
		merge(A, p, q, r);
	}
}


void merge(int A[], int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1], R[n2];

	/* populate left and right arrays */
	for(int i = 0; i < n1; i++)
		L[i] = A[p+i];
	for(int i = 0; i < n2; i++)
		R[i] = A[q+i+1];

	/* start merge */
	int i = 0;
        int j = 0;
	int k = p;
	while(i < n1 && j < n2){
		if (L[i] < R[j])
			A[k++] = L[i++];
		else
			A[k++] = R[j++];
	}

	/* finish the non-empty array */
	while (i < n1)
		A[k++] = L[i++];
	while (j < n2)
		A[k++] = R[j++];
}
