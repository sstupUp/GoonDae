#include <stdio.h>

int main()
{
  int i = 0, j = 0;
  int n = 2, flag = 0;

  for(; n< 100; ++n)
    {
      for(i = 2;i<n;++i)
	{
	  if((n%i)==0)
	    {
	      flag = 1;
	      break;
	    }
	  else
	    flag = 0;
	}

      if(flag == 0)
	printf("%d ", n);
    }

  return 0;
}
	    
