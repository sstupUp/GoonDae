#include <stdio.h>

#define MAX_LINE 200

//Converts characters like newline and tab into visible escape sequences

int Getline(char [], int);
void Escape(char [], char []);
void Printline(char []);
void Escape2(char [], char []);

main ()
{
  char buffer[MAX_LINE];
  char buffer2[MAX_LINE];
  char buffer3[MAX_LINE];

  while(Getline(buffer, MAX_LINE) >= 0)
    {
      Escape(buffer, buffer2);
      Printline(buffer2);
      printf("\nEscape2 => ");
      Escape2(buffer, buffer3);
      Printline(buffer3);
      printf("\n");
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

void Printline(char s[])
{
  int i;

  for(i=0; s[i] != '\0'; ++i)
    putchar(s[i]);
}

void Escape(char s[], char s2[])
{
  int i, j;

  j = 0;
  
  for(i = 0; s[i] != '\0'; ++i)
    {
      switch(s[i])
	{
	case '\t':
	  s2[j++] = '\\';
	  s2[j++] = 't';
	  break;
	case '\n':
	  s2[j++] = '\\';
	  s2[j++] = 'n';
	  break;
	default:
	  s2[j++] = s[i];
	}
    }
}

void Escape2(char s[], char s2[])
{
  int i, j;

  j = 0;

  for(i = 0; s[i] != '\0'; ++i)
    {
      switch (s[i])
	{
	case '\\':
	  switch(s[++i])
	    {
	    case 't':
	      s2[j++] = '\t';
	      break;
	    case 'n':
	      s2[j++] = '\n';
	      break;
	    default:
	      s2[j++] = s[i];
	      break;
	    }
	  break;
	default:
	  s2[j++] = s[i];
	  break;
	}
    }
}
