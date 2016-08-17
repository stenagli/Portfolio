#ifndef DARRAY_H
#define DARRAY_H

struct darray{
	int size;
	int num_elements;
	int *array;
};

#define is_empty(x)	(((x)->size) == 0)
struct darray *init_darray();
void push(struct darray *darray, int key);
int pop(struct darray *darray);
void delete_darray(struct darray *darray);

#endif
