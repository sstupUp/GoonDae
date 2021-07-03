#include <stdio.h>

int Getline(void);
void Putline(int);
void Copying(void);

int Getline(void)
{
  int c;

  return c = getchar();
}

void Putline(int c)
{
  putchar(c);
}

void Copying(void)
{
  int i;

  while((i = Getline()) != EOF)
    {
      printf("\n.");
      Putline(i);
    }

  printf("\n");
}

main ()
{

  printf("\ntesting\n");
  Copying();

  printf("Copying Complete\n");
}
