/* Wrapper functions from CSAPP */

#include <stdlib.h> /* For malloc definition */
#include <stdio.h> /* For fprintf */
#include "wrappers.h"

void *Malloc(size_t n){
	void *p;

	if ((p = malloc(n)) == NULL){
		fprintf(stderr,"Malloc error");
		exit(EXIT_FAILURE);
	}

	return p;
}
