#include <stdio.h>

//Counts digitis, white space, others

main()
{
  int c, i, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;
  for(i=0; i<10; ++i)
    ndigit[i] = 0;

  while((c = getchar()) != EOF)
    if((c >= '0') && (c <= '9'))
      ++ndigit[c - '0'];
    else if((c == ' ') || (c == '\t') || (c == '\n'))
      ++nwhite;
    else
      ++nother;

  printf("\nndigits:\n");

  for(i=0; i<10; ++i)
    printf("'%d' =  %d\n",i, ndigit[i]);

  printf("\nnwhite = %d, nother = %d\n", nwhite, nother);
}
	
