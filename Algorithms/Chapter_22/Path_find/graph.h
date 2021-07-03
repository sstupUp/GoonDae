typedef struct graph
{
  int nVertex;
  NODE** adjList;
  
}GRAPH;

GRAPH* Create_graph(int); //Create a graph which has array of pointers
void Init_graph(GRAPH*); //Initialize the graph
void Add_edge(GRAPH*, int ,int); //Add edge in the given graph
void Make_graph(GRAPH*); //Make graph using Add_edge function
void Print_graph(GRAPH*); //Print every adjList

GRAPH* Create_graph(int size)
{
  GRAPH* g = (GRAPH*)malloc(sizeof(GRAPH));

  g->nVertex = size;
  g->adjList = (NODE**)malloc(sizeof(NODE*)*size);

  Init_graph(g);

  return g;
}

void Init_graph(GRAPH* g)
{
  int i = 0;

  for(; i < g->nVertex; ++i)
    g->adjList[i] = NULL;
}

void Add_edge(GRAPH* g, int start, int end)
{
  int i = 0;
  NODE* dummy;

  //Add new node at the begining of the start node's adjList
  
  dummy = Create_node(end);
  dummy->next = g->adjList[start];
  g->adjList[start] = dummy;

}

void Make_graph(GRAPH* g)
{
  int start = 0, end = 0;

  printf("\nEnter '-1' to end making graph");

  while(1)
    {
      printf("\nEnter vertex: ");
      scanf("%d", &start);

      if(start == -1)
	break;
      
      while(1)
	{
	  printf("Enter adjacent vertex: ");
	  scanf("%d", &end);

	  if(end == -1)
	    break;
      
	  Add_edge(g, start, end);
	}
    }
  
  return;
}

void Print_graph(GRAPH* g)
{
  int i = 0;
  NODE* dummy;
  
  for(; i < g->nVertex; ++i)
    {
      printf("vertex %d is adjacent with: ", i);

      dummy = g->adjList[i];
      while(dummy != NULL)
	{
	  printf("%d ", dummy->vertex);
	  dummy = dummy->next;
	}

      printf("\n");
    }
}
      


  
  
