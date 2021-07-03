#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "queue.h"
#include "graph.h"

#define TRUE 1

void Where_2_begin(int*);
void DFS(GRAPH*, int);

int visited[5];

int main()
{
  GRAPH* g;
  QUEUE* q;
  int size, start;

  printf("\nEnter total number of vertices: ");
  scanf("%d", &size);
  
  g = Create_graph(size);
  q = Create_queue();
    
  Make_graph(g);

  printf("\n");

  Where_2_begin(&start);
  
  DFS(g, start);

  return 0;
}

void Where_2_begin(int* start)
{
  printf("\nEnter starting vertex number: ");
  scanf("%d", start);

  printf("\n");

  return;
}
void DFS(GRAPH* g, int s)
{
  int u;
  NODE* dummy;

  printf("visited: %d\n", s);

  dummy = g->adjList[s];
  visited[s] = 1;

  while(dummy != NULL)
    {
      s = dummy->vertex;
      if(!visited[s])
	DFS(g,s);

      dummy = dummy->next;
    }

  return;
}
  
