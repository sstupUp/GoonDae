#include <stdio.h>

#define ALLOCSIZE 100000

static char allocbuf[ALLOCSIZE];
static char* allocp = allocbuf;

char* Alloc(int);
void Afree(char *);
void Strcpy_Array(char *, char *);
void Strcpy_Pointer_1(char *, char *);
void Strcpy_Pointer_2(char *, char *);
void Strcpy_Pointer_3(char *, char *);
void Strcmp(char *, char *); //Compare two strings to see which string shows up faster in a dictonary

char* Alloc(int n)
{
  if((allocbuf + ALLOCSIZE - allocp) >= n)
    {
      allocp += n;
      return allocp;
    }
  else
    return 0;
}

void Afree(char* p)
{
  if((p>= allocbuf) && (p < (allocbuf + ALLOCSIZE)))
    allocp = p;
}

void Strcpy_Array(char* dest, char* source)
{
  int i = 0;

  while((dest[i] = source[i]) != '\0')
    i++;

}

void Strcpy_Pointer_1(char* d, char* s)
{
  while((*s = *t) != '\0')
    {
      s++;
      t++;
    }
}

void Strcpy_Pointer_2(char* d, char* s)
{
  while((*s++ = *t++) != '\0')
    ;
}

void Strcpy_Pointer_3(char* d, char* s)
{
  while(*s++ = *t++)
    ;
}

void Strcmp(char* s, char* t)
{
  for(;*s==*t; s++, t++)
    if (*s == '\0')
      return 0;

  return *s - *t;   //if *s - *t >0 => t comes first, else s comes first
}
