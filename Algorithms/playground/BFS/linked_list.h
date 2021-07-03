typedef struct adj_list_node
{
  NODE* current;
  struct adj_list_node* next;
  
}adjLIST_NODE;

adjLIST_NODE* Create_adjLIST_NODE(void);
void Init_adjLIST_NODE(adjLIST_NODE*);
void Add_adjLIST_NODE(adjLIST_NODE* ,NODE*);

adjLIST_NODE* Create_adjLIST_NODE(void)
{
  adjLIST_NODE* dummy = (adjLIST_NODE*)malloc(sizeof(adjLIST));

  Init_adjLIST(dummy);

  return dummy;
}

void Init_adjLIST_NODE(adjLIST_NODE* dummy)
{
  dummy->current = NULL;
  dummy->next = NULL;
}

void Add_adjLIST(adjLIST_NODE* current_node, NODE* next)
{
  adjLIST_NODE* dummy = Create_adjLIST_NODE();

  dummy->current = next;
{

