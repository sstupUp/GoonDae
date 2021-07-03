#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Count_sort(int [], int [], int [], int, int);
void Print_array(int [], int);

int main()
{
  int data[11], sorted_data[11] = {0};
  int max_val = 9;
  int *count_array = malloc(sizeof(int)*max_val);
  int i;

  srand(time(NULL));

  for(i = 0; i<11; ++i)
    data[i] = rand()%(max_val-1);

  printf("Data :");
  Print_array(data, 10);

  Count_sort(data, sorted_data, count_array, max_val, 10);
  printf("Sorted data :");
  Print_array(sorted_data, 10);
  
  return 0;
  
}

void Count_sort(int data[], int sorted_data[], int count_array[], int max_val, int length)
{
  int i = 0;

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
