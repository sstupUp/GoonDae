#include <stdio.h>

#define MAX_LINE 200

// converting hexadecimal to decimal

int HtoI (char []);
int Getline(char [], int);

main()
{
  char buffer[MAX_LINE];
  int ans;
  
  while((Getline(buffer, MAX_LINE) >= 0))
    if((ans = HtoI(buffer)) == -1)
      printf("\nError\n");
    else
      printf(" => %d\n", ans);
}

int HtoI(char s[])
{
  int answer, i, offset;

  answer = 0;
  offset = 0;

  if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    for(i=2; s[i] != '\n'; ++i)
      {
	if(s[i] >= 'a'&& s[i] <= 'f')
	  offset = s[i] - 87;
	else if(s[i] >= 'A' && s[i] <= 'F')
	  offset = s[i] - 55;
	else if(s[i] >= '0' && s[i] <= '9')
	  offset = s[i] - '0';
	else
	  return -1;

	answer = answer*16 + offset;
      }
  else
    return -1;

  return answer;
}

int Getline(char s[], int lim)
{
  int c, i;

  for(i=0; i<lim-1 && (c= getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if(i == 0)
    return -1;

  if(c == '\n')
    s[i++] = '\n';

  s[i] = '\0';

  return i;
}
	
  
