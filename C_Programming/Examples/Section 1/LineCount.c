#include <stdio.h>

//Counting Lines

main ()
{
  int c, nl;

  while((c = getchar()) != EOF)
    if(c == '\n')
      ++nl;

  printf("\nnl = %d\n", nl);
}
