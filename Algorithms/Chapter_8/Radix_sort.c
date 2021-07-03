////////////////////Incomplete//////////////////

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void Count_sort(int [], int [], int, int);
void Radix_sort(int [], int [], int, int);

void Print_array(int [], int);

int main()
{
  int a,b;
  char data[10][4] = {"cow", "dog", "cat", "mom", "pop", "lil", "dig", "big", "tab", "fox"};
  int sorted_data[4][10] = {0};

  for(a = 0; a<10; ++a)
    {
      for(b = 0;b<3; ++b)
	printf("%c", data[a][b]);

      printf(" ");
    }

  printf("\n");
  
  return 0;
}

void Radix_sort(int data[], int sorted_data[], int base, int length)
{
  int i = 0;
  
  /* for(; i< length;++i)
     Count_sort(data[i][], sorted_data, 'Z', length);*/
}

void Count_sort(int data[], int sorted_data[], int max_val, int length)
{
  int i = 0;
  int *count_array = malloc(sizeof(int) *(max_val-'0'));
    
  for(i = 0; i<max_val; ++i)
    count_array[i] = 0;
  
  for(i = 1; i<=length; ++i)
    ++count_array[data[i]];

  for(i = 0; i<max_val; ++i)
    count_array[i] = count_array[i] + count_array[i-1];

  for(i = length; i>0; --i)
    {
      sorted_data[count_array[data[i]]] = data[i];
      --count_array[data[i]];
    }
}

void Print_array(int data[], int length)
{
  int i = 0;

  for(; i<length; ++i)
    printf("%d ", data[i+1]);

  printf("\n\n");
}
