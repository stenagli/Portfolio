#include <stdio.h>

/* Exercise 1-10, p. 20 K&R */ 
main()
{
  int c;

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      putchar('\\');
      putchar('t');
    }
    else if (c == '\b')
    {
      putchar('\\');
      putchar('b');
    }
    else if (c == '\\')
    {
      putchar('\\');
      putchar('\\');
    }
    else 
      putchar(c);
  }
}
