#include <stdio.h>

//Counting Blanks, tabs and newlines

main ()
{
  int c, nB=0, nT=0, nL=0;

  while((c = getchar()) != EOF)
    switch (c)
      {
      case '\n':
	++nL;
	break;
      case ' ':
	++nB;
	break;
      case '\t':
	++nT;
	break;
      default:
	break;
      }

  printf("\nBlanks = %d, Tabs = %d, New lines = %d\n",nB, nT, nL);
}
