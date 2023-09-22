#include<stdio.h>
#define MAX 100

typedef struct 
{
    int Element[MAX];
    int front, rear;
}Queue;

void MakeNULL_Queue(Queue *q){
    q->front = -1;
    q->rear = -1;
}

int Empty_Queue(Queue *q){
    return q->front == -1;
}

int Full_Queue(Queue *q){
    return (q->rear - q->front + 1) % MAX == 0;
}

int Dequeue(Queue *q){
    int element;
    if(!Empty_Queue(*q)){
        element = q->Element[q->front];
        if(q->front == q->rear){
            MakeNULL_Queue(q);
        }
        else{
            q->front = (q->front + 1) % MAX;
        }
        return element;
    }
    else{
        printf("Queue empty\n");
    }
}

void Enqueue(int element, Queue *q){
    if(!Full_Queue(*q)){
        if(Empty_Queue(*q)) q->front = 0;
        q->rear = (q->rear + 1) % MAX;
        q->Element[q->rear] = element;
    }
    else{
        printf("Queue full");
    }
}