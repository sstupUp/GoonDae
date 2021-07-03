#include <stdio.h>

//replacing one or more blanks by a single blank

main ()
{
  int c, succ_blank = 0;

  while((c = getchar()) != EOF)
    if(c == '\t')
      putchar(' ');
    else if(c == ' ' && succ_blank == 0)
      {
	putchar(' ');
	succ_blank = 1;
      }
    else if(c == ' ' && succ_blank == 1)
      continue;
    else
      {
	putchar(c);
	succ_blank = 0;
      }
}
