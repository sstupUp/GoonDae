#include <stdio.h>

//From 300 degrees to 0 

main()
{
  float fahr, celsius, step;
  int lower, upper;

  lower = 0;
  upper = 300;
  step = 20.5;

  celsius = upper;

  printf("celsi\tfahr\n");
  
  while(fahr >= lower)
    {
      fahr = 9.0/5.0*celsius + 32;
      printf("%6.1f\t%6.1f\n", celsius, fahr);
      celsius -= step;
    }
}
  
