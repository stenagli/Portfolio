#include <stdio.h>

/* copy input to output; 2nd version */
main()
{
  long nc = 0; 

  while (getchar() != EOF)
    ++nc;
  printf("Number of characters: %ld\n", nc);
}
