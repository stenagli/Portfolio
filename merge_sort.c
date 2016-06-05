#include <stdio.h>
#define A_SIZE 8

/* function prototype */
void merge(int A[], int p, int q, int r);


int main(){
	int A[A_SIZE] = {2, 4, 5, 7, 1, 2, 3, 6};

	merge(A, 0, 3, 7);

	/* test merge */
	for(int i = 0; i < A_SIZE; i++)
		printf("%d\n",A[i]);

	return 0;
}


void merge(int A[], int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1], R[n2];

	int *Ap = A;
	int *Lp = L;
	int *Rp = R;

	/* populate left and right arrays */
	for(int i = 0; i < n1; i++)
		L[i] = A[p+i];
	for(int i = 0; i < n2; i++)
		R[i] = A[q+i+1];

	/* start merge */
	int i = 0;
        int j = 0;
	int k = 0;
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

