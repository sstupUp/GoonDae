#include <stdio.h>

//replacing one or more blanks by a single blank

main ()
{
  int c;

  while((c = getchar()) != EOF)
    if(c == '\t')
      {
	putchar('\\');
	putchar('t');
      }
    else if(c == '\\')
	putchar(c);
    else if(c == '\b')
      {
	putchar('\\');
	putchar('b');
      }
    else
      putchar(c);
	
}
