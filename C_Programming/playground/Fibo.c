#include <stdio.h>

int main()
{
  int a,b,c;
  int i,n;
  
  a = 0;
  b = 1;

  printf("To n fibonacci number: ");
  scanf("%d", &n);

  printf("\n");
  printf("%d %d ", a,b);
  for(i=2; i<=n; ++i)
    {
      c = a + b;
      a = b;
      b = c;

      printf("%d ",c);
    }

  return 0;
}

  
