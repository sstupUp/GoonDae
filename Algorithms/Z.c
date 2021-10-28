#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void z_trav(int, int, int, int, int); // (x, y), Length

int dx[4] = {0,1,0,1};
int dy[4] = {0,0,1,1};

int order = 0;	// Increase 1 after every traversal
void z_trav(int r, int c, int L, int r_t, int c_t)
{
	if(L == 2)
	{
		int i;
		int tmp_r, tmp_c;
		for(i = 0; i< 4; ++i)
			{	
				tmp_r = r + dx[i];
				tmp_c = c + dy[i];
				if(tmp_r == r_t && tmp_c == c_t)
					printf("%d\n",order);
			++order;	
			}

		return;
	}
	
	z_trav(r, c, L/2, r_t, c_t);
	z_trav(r, c + L/2, L/2, r_t, c_t);
	z_trav(r + L/2,c, L/2, r_t, c_t);
	z_trav(r+L/2, c+L/2, L/2, r_t, c_t);
	
	return;
}

void main(void)
{
	int N, r, c;

	scanf("%d", &N);
	scanf("%d", &r);
	scanf("%d", &c);
	int i, j;
	int tot = (int)pow(2, N);	
	
	printf("N = %d, r = %d, c = %d, tot = %d\n", N, r, c, tot);

	z_trav(0, 0, tot, r , c);

	return;	
}
