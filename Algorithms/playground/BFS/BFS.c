#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "graph.h"
#include "linked_list.h"
#include "queue.h"

void BFS(GRPAH*, QUEUE*, int);

int main(void)
{
  GRAPH* g = Create_graph();
  QUEUE* q = Create_queue();
  int start_node = 0;

  printf("\nEnter Starting node's name: \n");
  scanf("%d", &start_node);
  
  init_queue(q);
  
  Make_graph(g);
  
  BFS(g,q, start_node);

  return 0;
}

void BFS(GRAPH* g, QUEUE* q, int start)
{
  adjLIST_NODE* s = NULL;
  adjLIST_NODE* u = NULL, v = NULL;
  int offset = 0;
  
  while(g->LIST[offset]->current->vertex_name == start)
    ++offset;

  s = g->LIST[offset]->current;
  s->state = GRAY;
  s->parent = NULL;

  Enqueue(q, s);

  while(!is_empty(q))
    {
      u = Dequeue(q);
      v = dummy->next;

      while(v != NULL)
	{
	  if(v->current->state == BLACK)
	    {
	      v->current->state = GRAY;
	      v->current->parent = dummy;
	      Enqueue(q, v);
	    }
	}
      u->current->state = WHITE;
    }

  printf("\nBFS complete\n");
}


      
