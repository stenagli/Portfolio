/* Header file containing function prototypes */

/* Include guard */
#ifndef SORTING_AND_SEARCHING_H_INCLUDED
#define SORTING_AND_SEARCHING_H_INCLUDED

int binary_search(int A[], int start, int end, int val);
void insertion_sort(int A[], int length);
void insertion_sort_recursive(int A[], int length);
int linear_search(int A[], int length, int value);
void merge_sort(int A[], int p, int r);
void merge(int A[], int p, int q, int r);
void selection_sort(int A[], int length);
int find_smallest(int A[], int start, int end);

#endif
