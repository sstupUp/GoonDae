#include <stdio.h>

int D = 1000;
int pay;
int result;
int type[6] = {500, 100, 50, 10, 5, 1};

int main(void)
{
	int i =0;

	scanf("%d", &pay);
	D -= pay;

	for(i = 0; i <6; ++i)
	{
		result += (D / type[i]);
		D %= type[i];
	}

	printf("%d\n", result);

	return 0;
}	
