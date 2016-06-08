#include <stdio.h>
#define A_SIZE 16

/* structure definitions */

struct subarray {
	int left_index;
	int right_index;
	int sum;
};

/* function prototypes */
void print_subarray(struct subarray sub);
struct subarray return_subarray_sum(int A[], int left, int right);
struct subarray find_max_subarray_iterative(int A[], int left, int right);


int main(){
	int A[A_SIZE] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

	struct subarray subarray1 = {0, 1, A[0]+A[1]};
	print_subarray(subarray1);

	struct subarray subarray2 = return_subarray_sum(A, 0, 1);
	print_subarray(subarray2);

	struct subarray max_subarray = find_max_subarray_iterative(A, 1, A_SIZE-1);
	print_subarray(max_subarray);

	return 0;
}


void print_subarray(struct subarray sub){
	printf("left_index: %d, right_index: %d, sum: %d\n", sub.left_index, sub.right_index, sub.sum);
	}


struct subarray return_subarray_sum(int A[], int left, int right){

	struct subarray sub;
	sub.left_index = left;
	sub.right_index = right;


	/* compute sum of subarray */
	int sum = 0;
	for(; left <= right; left++){
		sum += A[left];
	}
	sub.sum = sum;

	return sub;
}


struct subarray find_max_subarray_iterative(int A[], int left, int right){
	/* half-done: just scans from left to right. */

	struct subarray max_subarray = {left, left, A[left]};

	int i = left;
	int sum = A[i];
	while(++i <= right){
		/* debugging info */
		printf("%d: %d + %d = %d\n", i, sum, A[i], sum + A[i]);

		if ((sum += A[i] )> max_subarray.sum){
			max_subarray.right_index = i;
			max_subarray.sum = sum;
		}

	}
		
	return max_subarray;
}
