/* Copy the contents of one file to another */

#include <stdlib.h>
#include <stdio.h>

int readStdinToString(char **str){
	/* Sets '*str' pointer to point to a C-style string containing the input to stdin.
	 * Returns 0 on success, any other value represents an error.
	 * Uses realloc() to copy an input string of unknown length to memory in O(1) time wrt the length of the input string */

	*str = NULL;
	int ch;
	size_t len = 0; /* Number of characters in string 'str' */
        size_t array_size = 0, new_size; /* Number of bytes allocated at pointer 'str' */

	while((ch = getchar()) != EOF && ch != '\n'){
		if((len*sizeof(**str)) == array_size){
		/* enlarge string */
			new_size = (array_size == 0) ? sizeof(**str) : array_size*2;
				if(new_size < array_size){
					/* overflow */
					fprintf(stderr, "ERROR: overflow in array resizing");
					return 1;
				}
			*str = realloc(*str, new_size);

			if(*str == NULL){
				fprintf(stderr, "ERROR: Unable to allocate extra memory for string");
				return 2;
			}

			array_size = new_size;
		}
		
		/* Append new char to the string */
		(*str)[len++] = (char) ch;
	}

	/* Resize array to proper length and append null character */
	*str = realloc(*str, sizeof(**str)*(len+1));
	if(*str == NULL){
		fprintf(stderr, "ERROR: Unable to resize string after reading all characters");
		return 3;
	}
	(*str)[len] = '\0';
	return 0;
}

int main(void){
	char *inputFile, *outputFile;
	FILE *in_fp, *out_fp;

	/* Query and open input file */
	int reading = -1;
	while(reading != 0){
		printf("Enter file to read from: \n");
		reading = readStdinToString(&inputFile);
	}

	if((in_fp = fopen(inputFile, "r")) == NULL){
		fprintf(stderr, "Error opening file %s\n", inputFile );
		return EXIT_FAILURE;
	}

	/* Query and open output file */
	reading = -1;
	while(reading != 0){
		printf("Enter file to copy to: \n");
		reading = readStdinToString(&outputFile);
	}
	if((out_fp = fopen(outputFile, "w")) == NULL){
		fprintf(stderr, "Error opening file %s\n", outputFile);
		return EXIT_FAILURE;
	}

	/* Copy from inputFile to outputFile */
	#define NUM_CHARS 32
	char buf[NUM_CHARS];
	while(fgets(buf, NUM_CHARS, in_fp) != NULL)
		fputs(buf, out_fp);

	/* Close files */
	if(fclose(in_fp) != 0){
		fprintf(stderr, "Error closing input file\n");
		return(EXIT_FAILURE);
	}

	if(fclose(out_fp) != 0){
		fprintf(stderr, "Error closing output file\n");
		return(EXIT_FAILURE);
	}

	free(inputFile);
	free(outputFile);

	return EXIT_SUCCESS;
}
