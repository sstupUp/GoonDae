#include <stdio.h>
#define MAX_BUFFER_SIZE 1000



int Getline(char [], int);
void Printline(char []);

int Getline(char s[], int lim)
{
  int c, i;

  Printline("Enter string:");
  
  for(i=0; i<lim-1 && (c= getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if(i == 0)
    return -1;

  if(c == '\n')
    s[i++] = '\n';

  s[i] = '\0';

  return i;
}

void Printline(char s[])
{
  int i;

  for(i=0; s[i] != '\0'; ++i)
    putchar(s[i]);
}
