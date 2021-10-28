#include <stdio.h>
#include <stdlib.h>

int graph[101][101];
int path[101][101];
int visit[101];
int N;

void dfs(int, int);

void dfs(int x, int y)
{
	visit[y] = 1;
	path[x][y] = 1;

	for(int i = 0; i <N; i++)
		if(graph[y][i] == 1 && visit[i] == 0)
			dfs(x, i);
}

int main()
{
	int i, j;
	scanf("%d", &N);
	for(i = 0; i< N; ++i)
		for(j = 0; j < N; ++j)
			scanf("%d", &graph[i][j]);
	
	for(i = 0; i<N; ++i){
		for(j = 0; j <N; j++)
			visit[j] = 0;

		for(j = 0; j < N; j++)
			if(graph[i][j] == 1 && visit[j] == 0)
				dfs(i, j);
	}
	
	for(i = 0; i< N; ++i){
		for(j = 0; j < N; ++j)
			printf("%d ", path[i][j]);
		printf("\n");
	}
		return 0;
}

	
