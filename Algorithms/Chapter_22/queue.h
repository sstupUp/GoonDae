#define MAX_QUEUE_SIZE 20

typedef struct queue
{
  int Queue[MAX_QUEUE_SIZE];
  int front;
  int rear;
  
}QUEUE;

QUEUE* Create_queue(void);
void Init_queue(QUEUE*);
int is_FULL(QUEUE*);
int is_EMPTY(QUEUE*);
int Enqueue(QUEUE*, int);
int Dequeue(QUEUE*);

QUEUE* Create_queue(void)
{
  QUEUE* dummy = (QUEUE*)malloc(sizeof(QUEUE));

  Init_queue(dummy);

  return dummy;
}

void Init_queue(QUEUE* q)
{
  int i = 0;

  for(;i<MAX_QUEUE_SIZE; ++i)
    q->Queue[i] = 0;

  q->front = q->rear = 0;
}

int is_FULL(QUEUE* q)
{
  if(q->front == (q->rear+1)%MAX_QUEUE_SIZE)
    return 1;
  else
    return 0;
}

int is_EMPTY(QUEUE* q)
{
  if(q->front == q->rear)
    return 1;
  else
    return 0;
}

int Enqueue(QUEUE* q, int s)
{
  if(is_FULL(q))
    return 0;
  else
    {
      q->rear = (q->rear + 1)%MAX_QUEUE_SIZE;
      q->Queue[q->rear] = s;

      return 1;
    }
}

int Dequeue(QUEUE* q)
{
  if(is_EMPTY(q))
    return 0;
  else
    {
      q->front = (q->front+1)%MAX_QUEUE_SIZE;

      return q->Queue[q->front];
    }
}
