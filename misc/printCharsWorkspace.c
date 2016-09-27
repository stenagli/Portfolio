#include <stdio.h>

main()
{
  printChar('n');
  printChar('\n');
  printChar('\t');
  printChar('	');
  printChar(' ');
}

void printChar(int c)
{
  printf("Character: %c Decimal: %d Hex:%x\n",c,c,c);
}
