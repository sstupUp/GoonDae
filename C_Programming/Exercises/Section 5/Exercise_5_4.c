#include <stdio.h>

int Strend(char [], char []);

int main ()
{
  char str1[] = "Hello, World!!";
  char str2[] = "!!";

  printf("\nis %s at the end of %s?", str2, str1);

  printf("\n%d\n",Strend(str2, str1));

  return 0;
}

int Strend(char s[], char t[])
{
  int s_len=0, t_len=0;

  while(s[s_len++])
    ;

  while(t[t_len++])
    ;

  --s_len;
  --t_len;
  
  while(s_len)
    if(s[s_len--] != t[t_len--])
      return 0;
    else if(t_len == 0)
      return 0;

  return 1;
}
  
