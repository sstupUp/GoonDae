#include <stdio.h>
#include <ctype.h>
#include "Lines.h"

#define MAX_LINE 100

//convert string s to double

double AtoF(char []);

int main()
{
  double sum;

  char buffer[MAX_LINE];

  sum = 0;

  while(Getline(buffer, MAX_LINE) >= 0)
    printf("\t%g\n", sum += AtoF(buffer));

  return 0;

}

double AtoF(char s[])
{
  double val, power;
  int i, sign;
  int power_count, power_val;

  power_count = 0;
  
  for(i = 0; isspace(s[i]); i++)    //skip white space
    ;

  sign = (s[i] == '-') ? -1 : 1;

  if(s[i] == '+' || s[i] == '-')
    i++;

  for(val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  if(s[i] == '.')
    i++;

  for(power = 1.0; isdigit(s[i]); i++){
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  if(s[i] == 'e' || s[i] == 'E')
    i++;

  if(s[i] == '-')
    {
      ++i;
      
      for(power_val = 0.0; isdigit(s[i]); ++i)
	power_val = 10.0*power_val + (s[i] - '0');
      
      for(power_count = 0; power_count < power_val; ++power_count)
	power *= 10.0;
    }
  else
    {
      for(power_val = 0.0; isdigit(s[i]); ++i)
	power_val = 10.0*power_val + (s[i] - '0');
      
      for(power_count = 0; power_count < power_val; ++power_count)
	power /= 10.0;
    }
	  
  return sign * val / power;
}
