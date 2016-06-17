#include <stdio.h>
#include "sorting_and_searching.h"

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
