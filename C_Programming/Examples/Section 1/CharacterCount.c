#include <stdio.h>

//count characters in input

main ()
{
  double nc;

  for(nc =0; getchar() != EOF; ++nc)
    ;

  printf("\n%.0f\n", nc);
}
  
