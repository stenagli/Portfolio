#include <stdio.h>
#define A_SIZE 16

/* structure definitions */

struct subarray {
	int left_index;
	int right_index;
	int sum;
};

/* function prototypes */


int main(){
	int A[A_SIZE] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

	struct subarray subarray1 = {0, 1, A[0]+A[1]};
	printf("left_index: %d, right_index: %d, sum: %d\n", subarray1.left_index, subarray1.right_index, subarray1.sum);
	return 0;

}


