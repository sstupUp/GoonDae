#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>

#define MAX_SIZE 1000 + 1

using namespace std;

struct coor
{
	int x;
	int y;
};

queue<coor> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, result = 0;
int graph[MAX_SIZE][MAX_SIZE];

bool IsInside(int x, int y)
{
	return (0 <= x && 0 <= y && x < m && y < n);
}

void bfs(void)
{
	int i, nx, ny;

	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;

		q.pop();

		for(i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if(IsInside(nx, ny) == 1 && graph[ny][nx] == 0)
			{
				graph[ny][nx] = graph[y][x] + 1;
				q.push({nx, ny});
			}
		}
	}
}

int main()
{	
	int i, j;

	scanf("%d %d", &m, &n);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			scanf("%d", &graph[i][j]);

			if(graph[i][j] == 1)
				q.push({j, i});
		}
	}

	bfs();

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(graph[i][j] == 0)
			{
				printf("-1\n");
				return 0;
			}

			if(result < graph[i][j])
				result = graph[i][j];

		}
	}

	printf("%d\n", result - 1);

	return 0;
}
