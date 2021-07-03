#define MAX_QUEUE_SIZE 20

typedef struct queue
{
  int front;
  int rear;
  adjLIST_NODE* Queue[MAX_QUEUE_SIZE];
}QUEUE;

QUEUE* Create_queue(void);
void Init_queue(QUEUE*);
int is_full(QUEUE*);
int is_enmpy(QUEUE*);
int Enqueue(QUEUE*, adjLIST_NODE*);
adjLIST_NODE* Dequeue(QUEUE*);

QUEUE Create_queue(void)
{
  QUEUE* dummy = (QUEUE*)malloc(sizeof(QUEUE));

  Init_queue(dummy);

  return dummy;
}

void Init_queue(QUEUE* dummy)
{
  int a = 0;
  
  dummy->front = 0;
  dummy->rear = 0;

  for(; a<MAX_QUEUE_SIZE; ++a)
    dummy->Queue[a] = 0;
}

int is_full(QUEUE* dummy)
{
  if(dummy->front == (dummy->rear+1)%MAX_QUEUE_SIZE)
    return 1;
  else
    return 0;
}

int is_empty(QUEUE* dummy)
{
  if(dummy->front == dummy->rear)
    return 1;
  else
    return 0;
}

int Enqueue(QUEUE* dummy, adjLIST_NODE* date)
{
  if(is_full(dummy))
    return 0;
  else
    {
      dummy->rear = (dummy->rear + 1)%MAX_QUEUE_SIZE;
      dummy->Queue[dummy->rear] = data;

      return 1;
    }
}

adjLIST_NODE* Dequeue(QUEUE* dummy)
{
  if(is_empty(dummy))
    return NULL;
  else
    {
      dummy->front = (dummy->front+1)%max_QUEUE_SIZE;

      return dummy->Queueu[dummy->front];
    }
}
