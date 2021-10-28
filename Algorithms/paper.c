#include <stdio.h>
#include <stdlib.h>

void paper_color(int, int, int);

int blue = 0;
int white = 0;

int paper[128][128] = {{0}};


void paper_color(int x_s, int y_s, int N)
{
	int cur_value = paper[y_s][x_s];
	int i, j;
	int x_e, y_e;
	
	x_e = x_s + N;
	y_e = y_s + N;
	
	for(i = x_s; i< x_e; ++i)
		for(j = y_s; j < y_e; ++j)
			if(paper[j][i] != cur_value)
			{

				paper_color(x_s, y_s + N/2, N/2);
				paper_color(x_s + N/2, y_s, N/2);
				paper_color(x_s + N/2, y_s + N/2, N/2);
				paper_color(x_s, y_s, N/2);

				return;
			}


	if(cur_value == 1)
		++blue;
	else if(cur_value == 0)
		++white;
	else
		return;     
} 



int main()
{
	int N = 0;
	int i = 0, j = 0;

	scanf("%d", &N);

	for(i = 0; i < N; ++i)
		for(j = 0; j< N; ++j)
			scanf("%d", &paper[j][i]);
	
	paper_color(0, 0, N);
	printf("%d\n", white);
	printf("%d\n", blue);
	return 0;
}
