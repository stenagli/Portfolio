#include <stdio.h>
#define A_SIZE 8
#define VALUE 1

/* function prototypes */
int linear_search(int A[], int length, int value);

int main(){
	int A[A_SIZE] = {8, 6, 4, 2, 7, 5, 3, 1};
	int index = linear_search(A, A_SIZE, VALUE);
	printf("Index of value %d: %d\n", VALUE, index);
	if (index >= 0)
		printf("Value at that index: %d\n", A[index]);
}


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
