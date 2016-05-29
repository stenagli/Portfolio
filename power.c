#include <stdio.h>

/* function prototype */
int power(int base, int n);

main()
{
  for (int i = 0; i < 10; ++i)
    printf("%d %d %d\n", i, power(2,i), power(-3,i));
  return 0;
}

/* power: raise 'base' to 'n'-th power; n >= 0 */
int power(int base, int n)
{
  if (n == 0)
    return 1; 
  else if (n == 1)
    return base;

  /* compute power(b,n) as power(b,n/2) * power(b,n/2) * power(b,n%2) */
  int t = power(base,n/2);
  return t * t * power(base,n%2);
}
