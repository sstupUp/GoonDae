#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int start, N, M;

int visit[1001] = {0};

vector<int> edge[10001];
int dist[10001];

void dfs(int);

void InitDist(void);
void bfs(int);

void dfs(int s)
{	
	if(visit[s] == 1)
		return;

	printf("%d ", s);
	visit[s] = 1;
	for(int i = 0; i < edge[s].size(); i++)
		dfs(edge[s][i]);
}	

void InitDist(void)
{
	for(int i = 0; i < 10001; i++)
		dist[i] =(int)pow(2, 32) -1;
}

void bfs(int s)
{
	queue<int> q;
	int now, k, next;

	q.push(s);
	dist[s] = 0;

	while(!q.empty())
	{
		now = q.front();
		q.pop();

		printf("%d ", now);

		for(k = 0; k < edge[now].size(); k++)
		{
			next = edge[now][k];
			if(dist[next] == ((int)pow(2,32) -1))
			{
				dist[next] = dist[now] + 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &start);
	int x, y, i;
	for(i = 0; i < M; ++i)
	{
		scanf("%d %d",&x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	for(i = 1; i <=N; ++i)
		sort(edge[i].begin(), edge[i].end());
	/*
	for(i = 1; i <=N ; i++)
		if(visit[i] == 0)
			dfs(i);
		*/
	dfs(start);
	printf("\n");

	InitDist();
	/*
	for(i = 1; i <= N; i++)
		if(dist[i] == inf)
			bfs(i);
	*/
	bfs(start);
	printf("\n");
	return 0;
}

