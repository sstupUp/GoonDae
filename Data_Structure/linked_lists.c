/* Single linked lists */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node* next;
}NODE;

NODE* head = NULL;    // head is fixed
NODE* tail = NULL;    // perform operations on tail

/////////////////////////////////////////////////

NODE* create_Node(void);
void init_Node(NODE*, int);
void init_List(NODE*);

void add_Node_front(NODE*);
void add_Node(NODE*, int);
void add_Node_end(NODE*);

int delete_Node_front(void);
int delete_Node(int);
int delete_Node_end(void);

void reverse_List(void);

void print_List(void);

//////////////////////////////////////////////////

NODE* create_Node(void)
{
  NODE* tmp = (NODE*)malloc(sizeof(NODE));

  return tmp;
}

void init_Node(NODE* n, int value)
{
  n->value = value;
  n->next = NULL;
}

void init_List(NODE* n)
{
  head = n;
  tail = n;
}

void add_Node_front(NODE* n)
{
  NODE* tmp = head;

  head = n;
  n->next = tmp;
}

// add node at the tail of the list
void add_Node_end(NODE* n)
{
  tail->next = n;
  tail = n;
}

// i == the number of jumps between nodes
void add_Node(NODE* n, int i)
{
  int cnt = 1;
  NODE* trav = head;
  NODE* tmp = NULL;

  if(i == 0)
    {
      add_Node_front(n);
      return;
    }
  
  while(trav->next != NULL && cnt != i)
    {
      trav = trav->next;
      ++cnt;
    }
  
  if(cnt == i)
    {
      tmp = trav->next;
      trav->next = n;
      n->next = tmp;
    }
  else
    {
      printf("The list is shorter than the location\n");
      add_Node_end(n);
    }
}

int delete_Node_front(void)
{
  NODE* tmp = head;
  int del_value;
  
  head = tmp->next;
  del_value = tmp->value;
  
  free(tmp);
  
  return del_value;
}

// delete the tail node, return the value and free the node
int delete_Node_end(void)
{
  int temp_val;
  NODE* trav = head;
  NODE* del_node;
  
  if(head == tail)
    {
      temp_val = trav->value;
      head = tail = NULL;
    }
  else
    {
      while(trav->next->next != NULL)
	trav = trav->next;

      del_node = trav->next;
      trav->next = NULL;
      temp_val = del_node->value;
    }
  free(del_node);
  return temp_val;
}

int delete_Node(int i)
{
  NODE* trav = head;
  NODE* del_node;
  int cnt = 1;
  int del_value;
  
  if(i == 0)
    return delete_Node_front();

  while(trav->next != NULL && cnt != i)
    {
      trav = trav->next;
      cnt++;
    }

  if(cnt == i)
    {
      del_node = trav->next;
      trav->next = del_node->next;
      del_value = del_node->value;
    }
  else
    {
      printf("The list is shorter than the location\n");
      del_value = delete_Node_end();
    }

  return del_value;
}

void reverse_List(void)
{
  NODE* prev = head;
  NODE* next = NULL;
  NODE* trav = head->next;

  prev->next = NULL;
  next = trav->next; 
  
  while(next != NULL)
    {
      trav->next = prev;

      prev = trav;
      trav = next;
      next = trav->next;
      
    }
  
  trav->next = prev;
  head = trav;
}

void print_List(void)
{
  NODE* trav = head;
 
  while(trav->next != NULL)
    {
      printf("%d ", trav->value);
      trav = trav->next;
    }
  printf("%d\n", trav->value);
}
/////////////////////////////////////////////////

int main(void)
{
  NODE* n1 = create_Node();
  NODE* n2 = create_Node();
  NODE* n3 = create_Node();
  NODE* n4 = create_Node();
  NODE* n5 = create_Node();
  
  init_List(n1);
  
  init_Node(n1, 10);
  init_Node(n2, 20);
  init_Node(n3, 30);
  init_Node(n4, 40);
  init_Node(n5, 50);

  printf("n1 added\n");
  print_List();
  
  add_Node_end(n2);
  add_Node_end(n3);
  printf("\nn2 n3 added\n");
  print_List();

  add_Node(n4, 1); 
  add_Node(n5, 2);
  printf("\nn4, n5 added\n");
  print_List();
  
  printf("\ndelete the end\n");
  delete_Node_end();
  print_List();

  printf("\ndelete 2nd node\n");
  delete_Node(2);
  print_List();
  

  reverse_List();
  print_List();
  
  return 0;
}
