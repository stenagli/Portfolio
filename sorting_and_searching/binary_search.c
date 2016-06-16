#include <stdio.h>
#define A_SIZE 8
#define VALUE 7

/* function prototypes */
int binary_search(int A[], int start, int end, int val);

int main(){
	int A[A_SIZE];
	for(int i = 0; i < A_SIZE; i++)
		A[i] = i;

	int idx = binary_search(A, 0, A_SIZE-1, VALUE);
	printf("Index of value %d: %d\n", VALUE, idx);
	printf("Value at index %d: %d\n", idx, A[idx]);
	return 0;
}

int binary_search(int A[], int start, int end, int val){
	printf("start: %d, end: %d, val: %d\n", start, end, val);

	if (start == end)
		return (A[start] == val ? start : -1);

	int mid = (start+end)/2;
	int cur = A[mid];
	if (cur == val)
		return mid;
	else
		return ((cur > val) ? binary_search(A, start, mid-1, val) : binary_search(A, mid+1, end, val));
}
