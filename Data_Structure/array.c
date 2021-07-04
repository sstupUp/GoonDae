/* Static Array */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 50

typedef int DATA;

typedef struct
{
  DATA ARR[MAX_ARRAY_SIZE];
  int num_empty;             // number of empty slots
}ARRAY;

//////////////////////////////////////////////////////////

void init_Array(ARRAY*);

int is_Empty(ARRAY*);
int is_Full(ARRAY*);

void insert_Data(ARRAY*, DATA);
DATA get_Data(ARRAY*, int);

void clear_Array(ARRAY*);
void print_Array(ARRAY*);

//////////////////////////////////////////////////////////

void init_Array(ARRAY* arr)
{
  int i = 0;

  for(; i< MAX_ARRAY_SIZE; ++i)
    arr->ARR[i] = 0;  // change 0 to +INF
  
  arr->num_empty = MAX_ARRAY_SIZE;
}

int is_Empty(ARRAY* arr)
{
  // the number of empty slot == MAX_ARRAY_SIZE
  
  if(arr->num_empty == MAX_ARRAY_SIZE)
    return 1;
  else
    return 0;
}

int is_Full(ARRAY* arr)
{
  // the number of empty slot == MAX_ARRAY_SIZE
  
  if(arr->num_empty == 0)
    return 1;
  else
    return 0;
}


// insert the data at the back of the array
void insert_Data(ARRAY* arr, DATA d)
{
  if(is_Full(arr))
    printf("Array is Full\n");
  else
    {
      arr->ARR[MAX_ARRAY_SIZE - arr->num_empty] = d;
      arr->num_empty--;
    }
}

// get the data which is stored at idx in the array 
DATA get_Data(ARRAY* arr, int idx)
{
  if(is_Empty(arr))
    {
      printf("Array is Empty\n");
      return -1; // change -1 to -INF
    }
  else
    {
      arr->num_empty++;
      return arr->ARR[idx];
    }
}

// clear the array with -INF value
void clear_Array(ARRAY* arr)
{
  int i = 0;

  for(; i< MAX_ARRAY_SIZE; ++i)
    arr->ARR[i] = 0; // change 0 to +INF
}

void print_Array(ARRAY* arr)
{
  int i = 0;

  for(; i< MAX_ARRAY_SIZE - arr->num_empty; ++i)
    printf("%d ", arr->ARR[i]);

  printf("\n");
}

/////////////////////////////////////////////////////////

int main(void)
{
  ARRAY arr;

  init_Array(&arr);
  int i;
  for(i = 0; i < 11; i += 3)
    insert_Data(&arr, i);
  
  print_Array(&arr);

  printf("%d\n", get_Data(&arr, 0));
  return 0;
}
