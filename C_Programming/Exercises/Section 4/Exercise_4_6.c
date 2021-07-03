#include <stdio.h>
#include <stdlib.h>
#include "Lines.h"
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
double AtoF(char []);

int getch(void);
void ungetch(int);
void ungets(char s[]);

void Peak(void);
void Duplicate(void);
void Swap(void);

int sp = 0;
double val[MAXVAL];

char buf[BUFSIZE];
int bufp = 0;

main()
{
  int type, c;
  double op2;
  char s[MAXOP];
  double var;

  var = 0;

  while((type = getop(s)) != EOF)
    {
      switch(type)
	{
	case NUMBER:
	  push(AtoF(s));
	  break;
	case '+':
	  push(pop() + pop());
	  break;
	case '*':
	  push(pop() * pop());
	  break;
	case '-':
	  op2 = pop();
	  push(pop() - op2);
	  break;
	case '/':
	  op2 = pop();
	  if(op2 != 0.0)
	    push(pop() / op2);
	  else
	    printf("\nerror: zero divisor\n");
	  break;
	case '%':
	  op2 = pop();
	  if(op2 != 0.0)
	    push((int)pop() % (int)op2);
	  else
	    printf("\nerror: zero divisor\n");
	  break;
	case '\n':
	  printf("\t%.8g\n",var = pop());
	  break;
	case 'P':
	  Peak();
	  break;
	case 'D':
	  Duplicate();
	  break;
	case 'S':
	  Swap();
	  break;
	case 's':
	  push(sin(pop()));
      	  break;
	case 'c':
	  push(cos(pop()));
       	  break;
	case 't':
	  push(tan(pop()));
       	  break;
	case 'e':
	  push(exp(pop()));
       	  break;
	case 'p':
	  push(pow(pop(), pop()));
      	  break;
	case 'x':
	  push(var);
	  break;
	default:
	  printf("\nerror: unkown command %s\n", s);
	  break;
	} 
    }
  return 0;
}

double AtoF(char s[])
{
  double val, power;
  int i, sign;

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

  return sign * val / power;
}

void push(double f)
{
  if(sp < MAXVAL)
    val[sp++] = f;
  else
    printf("\nerror: stack overflow. can't push %g\n", f);
}

double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else
    {
      printf("\nerror: stack empty\n");
      return 0.0;
    }
}

int getop(char s[])
{
  int i, c;

  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if(!isdigit(c) && c != '.')
    return c;
  
  i = 0;
  
  if(isdigit(c))
    while(isdigit(s[++i] = c = getch()))
	  ;

  if(c == '.')
    while(isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';

  if(c != EOF)
    ungetch(c);

  return NUMBER;
}

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if(bufp >= BUFSIZE)
    printf("\nungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

void Peak(void)
{
  if(sp > 0)
    printf("\n\t%g\n",val[sp]);
  else
    printf("\n\tstack is empty\n");
}
 
void Swap(void)
{
  double dum1, dum2;

  dum1 = 0;
  dum2 = 0;
  
  if(sp > 1)
    {
      dum1 = pop();
      dum2 = pop();
      push(dum1);
      push(dum2);

      printf("\n\tSwap complete\n");
    }
  else
    printf("\n\tNot enough data\n");
}

void Duplicate(void)
{
  double dum;

  dum = 0;

  if(sp > 0)
    {
      dum = pop();
      push(dum);
      push(dum);

      printf("\n\tDuplicate complete\n");
    }
  else
    printf("\n\tStack is empty\n");
}
