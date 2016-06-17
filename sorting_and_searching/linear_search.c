#include "sorting_and_searching.h"

int linear_search(int A[], int length, int value){
	/* returns index of 'value', or -1 if not present */
	length --;
	while(length >= 0){
		if (A[length] == value)
			break;
		length--;
	}
	return length;
}
