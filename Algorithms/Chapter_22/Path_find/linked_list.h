#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct node
{
  int vertex;
  struct node* next;
  struct node* parent;
  
}NODE;

NODE* Create_node(int); //Create node and return it's pointer
void Init_node(NODE*, int); //Initialize node with zeros and NULL 

NODE* Create_node(int vertex)
{
  NODE* dummy = (NODE*)malloc(sizeof(NODE));
  Init_node(dummy, vertex);

  return dummy;
}

void Init_node(NODE* n, int vertex)
{
  n->vertex = vertex;
  n->next = NULL;
  n->parent = NULL;
}
