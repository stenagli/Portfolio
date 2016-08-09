/* Wrapper functions from CSAPP */

#include "wrappers.h"

void *Malloc(size_t n){
	void *p;

	if ((p = malloc(n)) == NULL)
		unix_error("Malloc error");
	return p;
}
