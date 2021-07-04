/* binary search tree */
/* left: smaller , right: bigger */
/* disregard the already existing input */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node* left;
  struct node* right;
}NODE;

NODE* root;

NODE* create_Node(void);
void init_Node(NODE*, int);

int is_there(int);

void add_Node(NODE*);
void delete_Node(int);

void print_Node(NODE*);

/////////////////////////////////////////////////

NODE* create_Node(void)
{
  NODE* tmp = (NODE*)malloc(sizeof(NODE));

  return tmp;
}

void init_Node(NODE* n, int data)
{
  n->value = data;
  n->left = NULL;
  n->right = NULL;
}

int is_there(int target)
{
  NODE* trav = root;

  while(trav != NULL)
   if(target == trav->value)
     return 1;
   else if(target < trav->value)
     trav = trav->left;
   else
     trav = trav->right;
  
  return 0;
}

// add a node to the global root
void add_Node(NODE* n)
{
  NODE* trav = root;

  while(trav->left != NULL && trav->right != NULL)
    if(is_there(n->value))
      {
	printf("the taget(%d) is already in the tree\n", n->value);
	return;
      }
    else if(n->value < trav->value)
      trav = trav->left;
    else
      trav = trav->right;

  if(n->value < trav->value)
    trav->left = n;
  else
    trav->right = n;

}

// find the node that holds the parameter and delete it
void delete_Node(int target)
{
  
}

// ascending order
void print_Tree(NODE* n)
{

  if(n == NULL)
    return;
  else
    {
      print_Tree(n->left);
      printf("%d ", n->value);
      print_Tree(n->right);
    }
}

//////////////////////////////////////////////////////////

int main(void)
{
  NODE* n1 = create_Node();
  NODE* n2 = create_Node();
  NODE* n3 = create_Node();
  NODE* n4 = create_Node();
  NODE* n5 = create_Node();
  NODE* n6 = create_Node();
  
  root = n1;
  
  init_Node(n1, 10);
  init_Node(n2, 5);
  init_Node(n3, 15);
  init_Node(n4, 2);
  init_Node(n5, 7);
  init_Node(n6, 5);
  
  add_Node(n2);
  add_Node(n3);
  add_Node(n4);
  add_Node(n5);
  
  print_Tree(root);
  printf("\n");

  add_Node(n6);
  
  return 0;
}
