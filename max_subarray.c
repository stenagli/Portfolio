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
struct subarray find_max_subarray_divideandconquer(int A[], int left, int right);
struct subarray find_max_crossing_subarray(int A[], int left, int right, int mid);
struct subarray find_max_subarray_linear(int A[], int left, int right);


int main(){
	int A[A_SIZE] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

	struct subarray crossing_subarray = find_max_crossing_subarray(A, 0, A_SIZE-1, 4);
	print_subarray(crossing_subarray);

	struct subarray subarray1 = {0, 1, A[0]+A[1]};
	print_subarray(subarray1);

	struct subarray subarray2 = return_subarray_sum(A, 0, 1);
	print_subarray(subarray2);

	struct subarray max_subarray = find_max_subarray_iterative(A, 0, A_SIZE-1);
	print_subarray(max_subarray);

	struct subarray max_divandconq_subarray = find_max_subarray_divideandconquer(A, 0, A_SIZE-1);
	print_subarray(max_divandconq_subarray);

	struct subarray subarray3 = find_max_subarray_linear(A, 0, A_SIZE-1);
	print_subarray(subarray3);

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

	/* record max_subarray elements in temporary variables to avoid memory references */
	int max_left = left;
	int max_right = left;
	int max_sum = A[left];


	for(int j = left; j <= right; j++){

		int i = j;
		int sum = A[i];
		while(++i <= right){
			/* debugging info */
			/* printf("%d: %d + %d = %d\n", i, sum, A[i], sum + A[i]); */

			if ((sum += A[i]) > max_sum){
				max_left = j;
				max_right = i;
				max_sum = sum;
			}
		}
	}
		
	struct subarray max_subarray = {max_left, max_right, max_sum};
	return max_subarray;
}


struct subarray find_max_subarray_divideandconquer(int A[], int left, int right){

	/* base case */
	if (left == right){
		struct subarray max_subarray = {left, right, A[left]};
		return max_subarray;
	}
	
	/* divide and conquer */
	int mid = left + (right-left)/2;
	struct subarray left_subarray = find_max_subarray_divideandconquer(A, left, mid);
	struct subarray right_subarray = find_max_subarray_divideandconquer(A, mid+1, right);
	struct subarray crossing_subarray = find_max_crossing_subarray(A, left, right, mid);

	if (left_subarray.sum > right_subarray.sum){
		if (left_subarray.sum > crossing_subarray.sum)
			return left_subarray;
		else
			return crossing_subarray;
	}
	else {
		if (right_subarray.sum > crossing_subarray.sum)
			return right_subarray;
		else
			return crossing_subarray;
	}

}


struct subarray find_max_crossing_subarray(int A[], int left, int right, int mid){

	/* find max subarray between i and mid */
	int left_sum = A[mid];
	int i = mid;
	int max_left = left_sum;
	int max_left_index = i;
	while (--i >= left){
		if ((left_sum += A[i]) > max_left){
			max_left = left_sum;
			max_left_index = i;
		}
	}

	/* find max subarray between mid and j */
	int right_sum = A[mid+1];
	int j = mid+1;
	int max_right = right_sum;
	int max_right_index = j;
	while (++j <= right){
		if ((right_sum += A[j]) > max_right){
			max_right = right_sum;
			max_right_index = j;
		}
	}

	struct subarray return_subarray = {max_left_index, max_right_index, max_left +  max_right};
	return return_subarray;
}


struct subarray find_max_subarray_linear(int A[], int left, int right){

	/* max subarray within A[1:j] */
	int max_right = left;
	int max_left = left;
	int max_sum = A[left];

	/* find max subarray ending at the current position */
	int i = left; /* left bound */
	int sum = A[i]; 
	int j = i; /* current position */
	while(++j <= right){
		if (sum <= 0){
			sum = A[j];
			i = j;
		}
		else
			sum += A[j];

		/* compare max A[i:j] with max A[1:j-1] */
		if (sum > max_sum){
			max_sum = sum;
			max_left = i;
			max_right = j;
		}
	}

	struct subarray return_array = {max_left, max_right, max_sum};
	return return_array;
}
