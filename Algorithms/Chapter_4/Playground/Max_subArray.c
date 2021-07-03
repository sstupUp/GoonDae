#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

#define LOW 0
#define HIGH 1
#define SUM 2

int Stat[3] = {0, 0, 0};

void Max_subArray(int [], int, int);
void Max_crossingArray(int [], int, int, int);

void main (void)
{
  int length = 20;
  int data[20] = {0};
  int i = 0;
  
  Stat[LOW] = 0;
  Stat[HIGH] = length-1;
  Stat[SUM] = 0;
  
  srand(time(NULL));

  printf("\ndata = ");
  
  for(; i<length; ++i)
    {
      data[i] = rand()%30 - rand()%40 + rand()%15 - rand()%11;
      printf(" %d", data[i]);
    }

  printf("\n");

  Max_subArray(data, Stat[LOW], Stat[HIGH]);
  
  printf("\nMax sub array : \n");
  printf("from = %d, to = %d, sum = %d\n", Stat[LOW], Stat[HIGH], Stat[SUM]);

  for(i = Stat[LOW]; i <= Stat[HIGH]; ++i)
    printf(" %d", data[i]);

  printf("\n");

}

void Max_subArray(int A[], int low, int high)
{
  int mid;
  int left_sum, right_sum, cross_sum;
  int left_low, right_low, cross_low;
  int left_high, right_high, cross_high;
  
  if(high == low)
    {
      Stat[LOW] = low;
      Stat[HIGH] = high;
      Stat[SUM] = A[low];

      return;
    }
  else
    {
      mid = (low +high)/2;
      
      Max_subArray(A, low, mid);
      left_low = Stat[LOW];
      left_high = Stat[HIGH];
      left_sum = Stat[SUM];

      Max_subArray(A, mid+1, high);
      right_low = Stat[LOW];
      right_high = Stat[HIGH];
      right_sum = Stat[SUM];

      Max_crossingArray(A, low, mid, high);
      cross_low = Stat[LOW];
      cross_high = Stat[HIGH];
      cross_sum = Stat[SUM];

      if ((left_sum >= right_sum) && (left_sum >= cross_sum))
	{
	  Stat[LOW] = left_low;
	  Stat[HIGH] = left_high;
	  Stat[SUM] = left_sum;

	  return;
	}
      else if ((right_sum >= left_sum) && (right_sum >= cross_sum))
	{
	  Stat[LOW] = right_low;
	  Stat[HIGH] = right_high;
	  Stat[SUM] = right_sum;

	  return;
	}
      else
	{
	  Stat[LOW] = cross_low;
	  Stat[HIGH] = cross_high;
	  Stat[SUM] = cross_sum;

	  return;
	}
    }
}

void Max_crossingArray(int A[], int low, int mid, int high)
{
  int left_sum = INT_MIN, right_sum = INT_MIN;
  int sum = 0;
  int i = 0, j = 0;
  int max_left, max_right;
  

  for(i = mid; i>=low; --i)
    {
      sum = sum + A[i];

      if(sum>left_sum)
	{
	  left_sum = sum;
	  max_left = i;
	}
    }

  sum = 0;

  for(j = mid+1; j<=high; ++j)
    {
      sum = sum + A[j];

      if(sum > right_sum)
	{
	  right_sum = sum;
	  max_right = j;
	}
    }


  Stat[LOW] = max_left;
  Stat[HIGH] = max_right;
  Stat[SUM] = left_sum + right_sum;

  return;
}
