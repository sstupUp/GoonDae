#include <stdio.h>
#include <stdlib.h>

int main()
{
  char dummy = 0;
  char *str = (char*)malloc(sizeof(char));
  int i = 2, j = 0;

  for(;(dummy = getchar()) != '\n'; ++i)
    {
      str = (char*)realloc(str, sizeof(char)*i);
      str[i] = dummy;
     
      ++j;
    }

  str[j] = '\0';

  for(i = 0; str[i] == '\0'; ++i)
    printf("%c+1", str[i]);

  printf("\n");

  return 0;
}
