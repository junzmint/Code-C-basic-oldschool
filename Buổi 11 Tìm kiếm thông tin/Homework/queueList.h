typedef struct elements
{
    int ID;
    int capacity;
} Eltype;

struct QueueEl_t
{
    Eltype element;
    struct QueueEl_t *next;
    struct QueueEl_t *prev;
};

typedef struct QueueEl_t QueueEl;

typedef struct Queue_t
{
    QueueEl *front, *rear;
} Queue;

QueueEl *makeNewNode(Eltype X)
{
    QueueEl *new = (QueueEl *)malloc(sizeof(QueueEl));
    if (new == NULL)
    {
        printf("Memory node allocation failed.\n");
        return NULL;
    }
    new->element = X;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

Queue *createQueue()
{
    Queue *new = (Queue *)malloc(sizeof(Queue));
    new->front = new->rear = NULL;
    return new;
}

int emptyQueue(Queue *Q)
{
    return (Q->front == NULL);
}

void EnQueue(Eltype X, Queue *Q)
{
    QueueEl *tmp = makeNewNode(X);
    if (Q->rear == NULL)
    {
        Q->front = Q->rear = tmp;
        return;
    }
    Q->rear->next = tmp;
    tmp->prev = Q->rear;
    Q->rear = tmp;
}

void DeQueue(Queue *Q)
{
    if (Q->front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    QueueEl *temp = Q->front;
    Q->front = Q->front->next;
    if (Q->front == NULL)
    {
        Q->rear = NULL;
    }
    free(temp);
}



void makeQueueEmpty(Queue *Q)
{
    if (Q->front == NULL)
    {
        return;
    }
    void *tmp = Q->front;
    while (Q->front != NULL)
    {
        Q->front = Q->front->next;
        free(tmp);
        tmp = Q->front;
    }
}