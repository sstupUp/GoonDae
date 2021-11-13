#include <stdio.h>
#include <stdlib.h>

int N, K;
int arr[11];
int tot = 0;

int main(void)
{
	int i =0;
	scanf("%d %d", &N, &K);

	for(i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	for(i = N; i > 0; i--)
	{
		tot += (K / arr[i]);
		K %= arr[i];
	}
	printf("%d\n", tot);
	return 0;
}
