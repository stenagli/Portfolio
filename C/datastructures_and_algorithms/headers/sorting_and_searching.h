/* Header file containing function prototypes */

/* Include guard */
#ifndef SORTING_AND_SEARCHING_H_INCLUDED
#define SORTING_AND_SEARCHING_H_INCLUDED

#define K 8 /* Only continue quicksorting subarrays with >= K elements */

/* struct containing parameters normally passed to merge_sort. For use in multithreaded_merge_sort function */
struct mtms_args {
	int *A;
	int p;
	int r;
};

/* Function Prototypes */
int binary_search(int A[], int start, int end, int val);
void insertion_sort(int A[], int length);
void insertion_sort_recursive(int A[], int length);
int linear_search(int A[], int length, int value);
void merge_sort(int A[], int p, int r);
void *multithreaded_merge_sort(void *args);
void selection_sort(int A[], int length);
int find_smallest(int A[], int start, int end);
void quick_sort(int A[], int p, int r);
void quick_sort_truncated(int A[], int p, int r);
void quick_insertion_sort(int A[], int end);
void heap_sort(int A[], int heap_size);


#endif
