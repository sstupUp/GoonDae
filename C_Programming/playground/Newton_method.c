#include <stdio.h>
#include <math.h>

double Newton(int, int);

int main ()
{
  int square = 0, n = 0;

  printf("Square root of what?: ");
  scanf("%d", &square);
  printf("\nCalculating n times: ");
  scanf("%d", &n);

  printf("\nAnswer: %.10f\n", Newton(square, n));

  return 0;
}

double Newton(int square, int n)
{
  int i = 0;
  double value = 1;

  for(i = 0; i<n; ++i)
    value = (value + square/value)/2;

  return value;
}
  
