#include <stdio.h>

#define MAX_LINE 200

//return the first position of any character in s1 that occurs in the string s2

int Getline(char [], int);
int Any(char [], char[]);

main ()
{
  char buffer1[MAX_LINE];
  char buffer2[MAX_LINE];

  while((Getline(buffer1, MAX_LINE) >= 0) && (Getline(buffer2, MAX_LINE)))
    {
      printf("%d\n",Any(buffer1, buffer2));
    }
}

int Getline(char s[], int lim)
{
  int c, i;

  printf("Enter string:");
  
  for(i=0; i<lim-1 && (c= getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if(i == 0)
    return -1;

  if(c == '\n')
    s[i++] = '\n';

  s[i] = '\0';

  return i;
}

int Any(char s1[], char s2[])
{
  int i, j;
  int found;

  for(i = 0; s1[i] != '\n'; ++i)
    for(j = 0; s2[j] != '\n'; ++j)
      if(s1[i] == s2[j])
	return i;

  return -1;
}
