#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>

#define inf 0x7fffffff
#define MAX_V 20001
#define MAX_E 300001

using namespace std;

int start, V, E;

typedef struct Node
{
	int end;
	int val;
};

vector<Node> Edge[MAX_E];

int dist[MAX_V] = {0};

void dijk(void)
{
	int i, n_d, prev_d;
	priority_queue< pair<int, int>> pq;
	pq.push({0, start});

	while(!pq.empty())
	{
		int n = pq.top().second;
		int cost = -1* pq.top().first;
		pq.pop();

		for(i = 0; i< Edge[n].size(); i++)
		{
			n_d = dist[n] + Edge[n][i].val;
			prev_d = dist[Edge[n][i].end];

			if(n_d < prev_d)
			{
				dist[Edge[n][i].end] = n_d;
				pq.push({-1*n_d, Edge[n][i].end});
			}
		}
	}
}

int main(void)
{	
	int i = 0;
	int from, to, d;

	scanf("%d %d", &V, &E);
	scanf("%d", &start);
	
	for(i = 0; i< E; i++)
	{
		scanf("%d %d %d", &from, &to, &d);
		Edge[from].push_back(Node{ to, d });
	}

	for(i = 1; i <=V; i++)
	{
		dist[i] = inf;
	}
	dist[start] = 0;

	dijk();

	for(i = 1; i<=V; i++)
	{
		if(dist[i] != inf)
			printf("%d\n", dist[i]);
		else
			printf("INF\n");
	}

	return 0;
}
 
	
