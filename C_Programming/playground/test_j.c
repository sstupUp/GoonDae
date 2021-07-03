#include <stdio.h>

int main ()
{
  int* ptr1 = 0x00008;
  double* ptr2 = 0x00008;

  printf("\n%p %p \n", ptr1+1, ptr2+1);

  return 0;
}
