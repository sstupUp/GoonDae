#include <stdio.h>
#include <stdlib.h>

#define BIAS 127             /* Since it's a 32-bit */
#define MAX_BUFFER_SIZE 1024

char BUFFER[MAX_BUFFER_SIZE];
unsigned char FRAC_BUFFER[MAX_BUFFER_SIZE];
unsigned char FRAC_RESULT[MAX_BUFFER_SIZE];
int SIGN_FLAG;

typedef struct
{
  unsigned int s:1;
  unsigned int e:8;
  unsigned int m:23;
  
}IEEEsingle;

typedef struct
{
  int integer;
  int fraction;
  int int_length;
  int frac_length;
  
}Original_Data;

IEEEsingle* Create_float(void);
Original_Data* Create_data(void);

////////////////////////////////////////////////////////////////////////////////////////////

int Getline(void);
int Char2int(int, int);
int Str2data(Original_Data*);    /* Convert a string data to a struct data */

////////////////////////////////////////////////////////////////////////////////////////////

void Normalize(IEEEsingle*);    /* ex) 101010.111 ==> 1.01010111 * 10^5 */
int Data2IEEE(Original_Data*, IEEEsingle*);
int frac2binary(Original_Data*); /* Convert fraction which is described in char to binary */

////////////////////////////////////////////////////////////////////////////////////////////

/*
 * Get two IEEEsingle data
 * as operands and return 
 * pointer of the result 
 */

IEEEsingle* Add(IEEEsingle*, IEEEsingle*);
IEEEsingle* Subtract(IEEEsingle*, IEEEsingle*);
IEEEsingle* Multiply(IEEEsingle*, IEEEsingle*);
IEEEsingle* Divide(IEEEsingle*, IEEEsingle*);

////////////////////////////////////////////////////////////////////////////////////////////

                            /* Initialization Functions */

IEEEsingle* Create_float(void)
{
  IEEEsingle* dummy = (IEEEsingle*)malloc(sizeof(IEEEsingle));

  if(dummy == NULL)
    return NULL;

  dummy->s = 0;
  dummy->e = 0;
  dummy->m = 0;

  return dummy;
}

Original_Data* Create_data(void)
{
  Original_Data* dummy = (Original_Data*)malloc(sizeof(Original_Data));

  if(dummy == NULL)
    return NULL;

  dummy->integer = 0;
  dummy->fraction = 0;
  dummy->int_length = 0;
  dummy->frac_length = 0;

  return dummy;
}

////////////////////////////////////////////////////////////////////////////////////////////

                                /* String Functions */

int Getline(void)
{
  int c, i = 0;

  while((c = getchar()) != '\n')
    if(((c >= '0') && (c <= '9')) || (c == '.') || (c == '-'))  
      BUFFER[i++] = c;
    else
      {
	printf("Input error: Enter input data as float");
	
	return -1;
      }
  
  
  BUFFER[i] = EOF;

  return 0;
}

int Char2int(int start, int end)
{
  int str = start, dec = 0;
  int result = 0, tmp = 0;

  SIGN_FLAG = 0;
  
  if(str == 0 && BUFFER[str] == '-')
    {
      SIGN_FLAG = 1;
      ++str;
    }
  
  while(str != end)
    {
      tmp = BUFFER[str] - '0';
      
      result = result*dec + tmp;

      if(dec == 0)
	dec = 10;
      
      ++str;
    }

  return SIGN_FLAG ? -result : result;
}

int Str2data(Original_Data* result)
{
  int i = 0;
  int radix = 0;

  if(Getline() == -1)
    return -1;

  while(BUFFER[i] != '.')
    ++i;

  radix = i;
  
  result->integer = Char2int(0, radix);

  if(SIGN_FLAG)
    result->int_length = radix - 1;
  else
    result->int_length = radix;

  i++;
  
  while(BUFFER[i] != EOF)
    ++i;

  result->fraction = Char2int(radix + 1, i);
  result->frac_length = (i - 1)- radix;

  return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////

void Normalize(IEEEsingle* data)
{
  /* ... */
}

int Data2IEEE(Original_Data* data, IEEEsingle* result);
{
  /* ... */
}

int Frac2binary(Original_Data* data)
{
  int cnt = 0, index = data->int_length + 1;
  int loop_cnt, infi_cnt = 0;
  int tmp;
  
  FRAC_BUFFER[cnt++] = 0;
  
  while(BUFFER[index] != NULL)
    {
      FRAC_BUFFER[cnt++] = BUFFER[index++];
    }

  FRAC_BUFFER[cnt] = BUFFER[index];  /* Adding NULL at the end of FRAC_BUFFER */

  loop_cnt = cnt;
  --loop_cnt;
  
  while((infi_cnt != MAX_INFI) && !FRAC_FINISH_FLAG)
    {
      while(loop_cnt != 0)
	{
	  tmp = FRAC_BUFFER[loop_cnt] - '0';
	  tmp *= 2;

	  if(
	  
      
}

////////////////////////////////////////////////////////////////////////////////////////////

                          /* Floating point Arithmetics */

IEEEsingle* Add(IEEEsingle* oper1, IEEEsingle* oper2)
{
  /* ... */
}

IEEEsingle* Subtract(IEEEsingle* oper1, IEEEsingle* oper2)
{
  /* ... */
}

IEEEsingle* Multiply(IEEEsingle* oper1, IEEEsingle* oper2)
{
  /* ... */
}

IEEEsingle* Divide(IEEEsingle* oper1, IEEEsingle* oper2)
{
  /* ... */
}

////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
  
  IEEEsingle* dummy = Create_float();
  Original_Data* data = Create_data();
  
  if(dummy == NULL && data != NULL)
    {
      printf("error: Can't create IEEEsingle format data\n");
      
      free(data);
      return -1;
    }
  if(dummy != NULL && data == NULL)
    {
      printf("error: Can't create Original_Data structure \n");
      
      free(dummy);
      return -1;
    }
  
  
  printf("size in bit = %ld\n", sizeof(IEEEsingle)*8);
  
  printf("sign = %d, exponent = %d, mantissa = %d\n", dummy->s, dummy->e, dummy->m);
  
  
  if(Str2data(data) == -1)
    return -1;
  
  printf("%d.%d\n", data->integer, data->fraction);
  printf("int length = %d, frac length = %d\n", data->int_length, data->frac_length);
  
  return 0;
  
}
  

  
