/* To compile, run 'cc -Wall -Wl,-rpath='../' -o darray.out darray.c -L'../' -lwrappers' */

#include "../wrappers/wrappers.h"
#include "darray.h"
#include <stdio.h>



struct darray *init_darray(){
	struct darray *darray = Malloc(sizeof(*darray));
	darray->size = 0;
	darray->num_elements = 0;
	darray->array = NULL;
	return darray;
}

void push(struct darray *darray, int key){
	if(darray->size == darray->num_elements){
		/* Array is full; expand it before adding */
		if(is_empty(darray)){
			darray->array = malloc(sizeof((darray->array)[0]));
			if(darray->array == NULL){
				/* If malloc fails, darray is unchanged */
				fprintf(stderr,"Unable to push element %d: expanding empty array failed\n", key);
				return;
			}
			(darray->size)++;
		}
		else { /* nonempty */
			int *new_array = realloc(darray->array, 2*(darray->size)*sizeof((darray->array)[0]));
			if (new_array == NULL){
				/* Use the old pointer, and indicate that pushing failed */
				fprintf(stderr,"Unable to push element %d: expanding nonempty array failed\n", key);
				return;
			}
			darray->array = new_array;
			(darray->size) *= 2;
		}
	}

	/* Add the new element and incr the number of elements */
	(darray->array)[(darray->num_elements)++] = key;
}

int pop(struct darray *darray){
	if (darray->num_elements == 0){
		fprintf(stderr,"Attempted to pop empty array\n");
		return -1;
	}

	int key = (darray->array)[--(darray->num_elements)];

	/* Shrink array if necessary */
	if (darray->num_elements <= (darray->size)/4){
		darray->array = realloc(darray->array, (darray->size)/2);
	}

	if (darray->array == NULL && darray->num_elements != 0){
		/* An error occurred, and should be reported */
		fprintf(stderr,"Array contraction error: null pointer returned but array is not empty\n");
		return -1;
	}

	return key;
}


void delete_darray(struct darray *darray){
	free(darray->array);
	free(darray);
}


int main(void){
	struct darray *darray = init_darray();
	printf("Popped %d\n", pop(darray));
	push(darray,1);
	push(darray,2);
	push(darray,3);
	for (int i = 0; i < 4; i++)
		printf("Popped %d\n", pop(darray));
	delete_darray(darray);
	return 0;
}
