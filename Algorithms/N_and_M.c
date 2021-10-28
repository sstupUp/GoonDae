#include <stdio.h>
#include <stdlib.h>

int N, M;
int visit[9] = {0};
int arr[9] = {0};

void dfs(int);

void dfs(int x)
{
	if(x == M){
		for(int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");

		return;
	}

	for(int i = 1; i <= N; i++){
		if(!visit[i]){
			visit[i] = 1;
			arr[x] = i;
			dfs(x + 1);
			visit[i] = 0;
		}
	}

	return ;
}

int main()
{
	scanf("%d %d", &N, &M);

	dfs(0);

	return 0;
}
