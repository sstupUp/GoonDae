#include <stdio.h>
#include "Lines.h"

#define MAX_LINE 1000

//Pattern matching code with returning the rightmost position 

char pattern[] = "ould";

int strindex(char source[], char searchfor[]);

main()
{
  char line[MAX_LINE];
  int found = 0;
  int position = 0;
  
  while(Getline(line, MAX_LINE) > 0)
    if((position = strindex(line, pattern)) >= 0){
	printf("%s", line);
	found++;
	printf("\nposition = %d\n\n", position);
      }

  
  return found;
}

int strindex(char s[], char t[])
{
  int i, j, k;
  int position = -1;

  for(i = 0; s[i] != '\0'; i++) {
    for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;

    if(k > 0 && t[k] == '\0')
      position = i;
  }
 
  return position;
}
