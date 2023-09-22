#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define sizeName 100

#include "queueList.h"
int parallel_process_num = 0;
int memory_capacity = 0;
int CountProcess = 0;
int MemoryUsage = 0;

void option1(Queue *queue1, Queue *queue2)
{
    Eltype new;
    printf("Creating new program (memory capacity must <= %d):\n", memory_capacity);
    printf("Enter program ID: ");
    scanf("%d", &new.ID);
    do
    {
        printf("Enter memory capacity: ");
        scanf("%d", &new.capacity);
        if (new.capacity > memory_capacity)
        {
            printf("Invalid memory capacity, you should update your potato computer before add this new program!\n");
        }
    } while (new.capacity > memory_capacity);
    if (CountProcess >= parallel_process_num || MemoryUsage > memory_capacity || MemoryUsage + new.capacity > memory_capacity)
    {
        printf("Running processes full slot or not enough memory, transfer to queue!\n");
        EnQueue(new, queue2);
    }
    else
    {
        printf("Program running!\n");
        EnQueue(new, queue1);
        CountProcess++;
        MemoryUsage += new.capacity;
    }
    printf("Memory Usage: %d\n", MemoryUsage);
    getchar();
}

void option2(Queue *queue1, Queue *queue2)
{
    Eltype tmp;
    if (emptyQueue(queue1))
    {
        printf("There is no running process to kill!\n");
        return;
    }
    tmp = queue1->front->element;
    DeQueue(queue1);
    CountProcess--;
    MemoryUsage = MemoryUsage - tmp.capacity;
    if (!emptyQueue(queue2))
    {
        if (queue2->front->element.capacity + MemoryUsage <= memory_capacity)
        {
            tmp = queue2->front->element;
            DeQueue(queue2);
            EnQueue(tmp, queue1);
        }
    }
    printf("The first running process has been killed!\n");
    getchar();
}

void option3(Queue *queue1, Queue *queue2)
{
    if (emptyQueue(queue1))
    {
        printf("There is no running process!\n");
        return;
    }
    printf("ID\t\t\tMemory\t\t\tQueue\n");
    QueueEl *tmp = queue1->front;
    while (tmp != NULL)
    {
        printf("%d\t\t\t%d\t\t\t\n", tmp->element.ID, tmp->element.capacity);
        tmp = tmp->next;
    }
    tmp = queue2->front;
    while (tmp != NULL)
    {
        printf("%d\t\t\t\t\t\t%d\n", tmp->element.ID, tmp->element.capacity);
        tmp = tmp->next;
    }
    getchar();
}

void menu(Queue *queue1, Queue *queue2)
{
    int choice = 0;
    printf("=======================WELCOME TO MAIN MENU====================\n");
    printf("Please enter number of parallel processes can run: ");
    scanf("%d", &parallel_process_num);
    printf("Please enter memory capacity: ");
    scanf("%d", &memory_capacity);
    printf("Parallel processes: %d\n", parallel_process_num);
    printf("Memory capacity: %d\n", memory_capacity);
    do
    {
        printf("=======================WELCOME TO MAIN MENU====================\n");
        printf("1. Create new program\n");
        printf("2. Kill a program\n");
        printf("3. Show the status of running and waiting processes.\n");
        printf("4. Exit\n");
        printf("===============================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            option1(queue1, queue2);
            printf("Press Enter to continue!");
            getchar();
        }
        if (choice == 2)
        {
            option2(queue1, queue2);
            printf("Press Enter to continue!");
            getchar();
        }
        if (choice == 3)
        {
            option3(queue1, queue2);
            printf("Press Enter to continue!");
            getchar();
        }
    } while (choice != 4);
}

void main()
{
    Queue *queue1, *queue2;
    queue1 = createQueue();
    queue2 = createQueue();
    menu(queue1, queue2);
    makeQueueEmpty(queue1);
    makeQueueEmpty(queue2);
}