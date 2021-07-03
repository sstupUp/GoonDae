#include <stdio.h>

#define MAX_LINE 200
#define IN 1
#define OUT 0

//entap: replace multiple blanks with tap that has same length

int Getline(char [], int);
void Printline(char []);

main()
{
  char buffer[MAX_LINE];
  
  while(Getline(buffer, MAX_LINE) >= 0)
    Printline(buffer);
}

int Getline(char s[], int lim)
{
  int c, i, state, j;
  int blank_count, position;

  char temp_buffer[MAX_LINE];
  int position_buffer[MAX_LINE/4];

  state = OUT;
  j = 0;
  
  blank_count = 0;
  position = 0;
  
  for(i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
      temp_buffer[i] = c;

      if(c == ' ')
	state = IN;
      else
	state = OUT;

      if(state == IN)
	++blank_count;

      if(blank_count == 4)
	{
	  position_buffer[j++] = i - 3;
	  

  if(i == 0)
    return -1;

  if(c == '\n')
    s[i++] = c;

  s[i] = '\0';

  return i;
}

void Printline(char s[])
{
  int i=0;
  
  while(s[i] != '\0')
    putchar(s[i++]);
}
