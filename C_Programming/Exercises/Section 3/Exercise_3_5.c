#include <stdio.h>

#define MAX_LINE 200

//ItoB(n,s,b) changes integer n to a base b string and stores it in char string s 

int Getline(char [], int);
int CtoI(char []);
void ItoB(int, char [], int);
void Printline(char []);

main()
{
  char Changed_data[MAX_LINE];
  char buffer[MAX_LINE];
  int n, base, Original_Data_length;

  Original_Data_length = 0;
  
  while((Original_Data_length = Getline(buffer, MAX_LINE)) > 0)
    {
      n = CtoI(buffer);
      printf("base: ");
      scanf("%d", &base);
      
      ItoB(n, Changed_data, base);

      Printline(Changed_data);
      Printline("\n\n");
    }
}

void ItoB(int n, char s[], int base)
{
  char temp[MAX_LINE];
  int ans, i, j;

  i = 0;
  
  for(ans = n; ans > 0; ans = ans/base)
      temp[i++] = ans%base + '0';

  i--;
  
  for(j = 0; i >= 0; --i)
    s[j++] = temp[i];

  s[j] = '\0';
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

  i = 0;
  
  printf("Enter n:");

  if((c = getchar()) == '\n')
    ;
  else if(c == '\0')
    return -1;
  else
    s[i++] = c;
  
  for(; i<lim-1 && (c= getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if(i == 0)
    return -1;

  if(c == '\n')
    s[i++] = '\n';

  s[i] = '\0';

  return i;
}

int CtoI(char s[])
{
  int ans, i;

  ans = 0;

  for(i=0; s[i] != '\n'; ++i)
    ans = ans*10 + (s[i] - '0');

  return ans;
}
  
