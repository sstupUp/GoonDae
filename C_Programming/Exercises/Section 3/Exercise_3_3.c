#include <stdio.h>
#include <ctype.h>

#define MAX_LINE 200

//expand ex) a-z => abcd...xyz

int Getline(char [], int);
void Expand(char [], char []);
void Printline(char []);

main()
{
  char buffer[MAX_LINE];
  char buffer2[MAX_LINE];
  
  while(Getline(buffer, MAX_LINE) >= 0)
    {
      Expand(buffer, buffer2);
      Printline(buffer2);
    }
}

void Expand(char s[], char s2[])
{
  int i, j, Expand_positi, k;
  char temp[MAX_LINE];
  int a, b, c;
  
  j = 0;
  k = 0;
  Expand_positi = 0;
  a = b = c = 0;
  
  for(i=0; s[i] != '\0'; ++i)
    if(isalpha(s[i]) || isdigit(s[i]))
      temp[j++] = s[i];
    else if(s[i] == '-')
      Expand_positi = j;
    else
      continue;

  while(1)
    {
      for(k = 0; k < Expand_positi; ++k)
	if(isalpha(temp[k]))
	   break;
      
      i = k;
      
      for(; !isalpha(temp[++i]); ++i)
	;

      for(j = 0; (temp[k] + j) <= temp[i]; ++j)
	for(a = 0; a <= Expand_positi; ++a)
	  if(isalpha(temp[a]))
	    s2[b++] = temp[a] + j;
	  else
	    s2[b++] = temp[a];

      break;
    }
	  
  
  s2[b++] = '\n';
  s2[b] = '\0';
}

void Printline(char s[])
{
  int i;

  for(i=0; s[i] != '\0'; ++i)
    putchar(s[i]);
}

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
	  
