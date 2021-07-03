#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "queue.h"
#include "graph.h"

#define TRUE 1

void Where_2_begin(int*);
void BFS(GRAPH*, QUEUE*, int, int, int);

int main()
{
  GRAPH* g;
  QUEUE* q;
  int size, start = 0, dest;

  printf("\nEnter total number of vertices: ");
  scanf("%d", &size);
  
  g = Create_graph(size);
  q = Create_queue();
    
  Make_graph(g);

  printf("\n");

  Where_2_begin(&start);
  Where_2_begin(&dest);
  
  BFS(g, q, start, dest, size);

  return 0;
}

void Where_2_begin(int* start)
{
  printf("\nEnter starting vertex number: ");
  scanf("%d", start);

  printf("\n");

  return;
}
  
void BFS(GRAPH* g, QUEUE* q, int s, int d, int size)
{
  int u;
  NODE* dummy, *parent;
  int visited[size], flag = 0;

  printf("Shortest path from %d to %d\n", s, d);
  
  Enqueue(q, s);
  visited[s] = TRUE;
  printf("%d ", s);
  
  while(!is_EMPTY(q))
    {
      u = Dequeue(q);
      dummy = g->adjList[u];
      parent = dummy;
      parent->parent = NULL;
      
      while(dummy != NULL)
	{
	  if(dummy->vertex == d)
	    {
	      flag = 1;
	      break;
	    }
	  
	  if(visited[dummy->vertex] != TRUE)
	    {
	      Enqueue(q, dummy->vertex);
	      visited[dummy->vertex] = TRUE;
	      
	    }
	  
	  dummy = dummy->next;
	  dummy->parent = parent;
	}

      if(flag == 1)
	{
	  while(parent != NULL)
	    {
	      printf("%d ", parent->vertex);
	      parent = parent->parent;
	    }
	}
      
    }
}
