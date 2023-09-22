#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int Eltype;

typedef struct StackType_t
{
    Eltype element;
    struct StackType_t *next;
} StackType;

int isEmpty(StackType **top)
{
    return (*top == NULL);
}

StackType *makeNewNode(int value)
{
    StackType *new;
    new = (StackType *)malloc(sizeof(StackType));
    if (new == NULL)
    {
        printf("No memory available\n");
        exit(0);
    }
    new->element = value;
    new->next = NULL;
    return new;
}

void push(StackType **top, int value)
{
    StackType *temp;
    temp = makeNewNode(value);
    if (*top == NULL)
    {
        *top = temp;
        return;
    }
    temp->next = *top;
    *top = temp;
}

Eltype pop(StackType **top)
{
    
    if (isEmpty(top))
    {
        // printf("Stack is empty!\n");
        return 0;
    }
    else
    {
        Eltype tmp_el;
        StackType *temp;
        temp = *top;
        tmp_el = temp->element;
        *top = (*top)->next;
        free(temp);
        return tmp_el;
    }
    
}

void displayStack(StackType *top)
{
    StackType *tmp = top;
    while (tmp != NULL)
    {
        printf("%d ", tmp->element);
        tmp = tmp->next;
    }
}

int countStack(StackType *top)
{
    int count = 0;
    StackType *tmp = top;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

Eltype peek(StackType *top)
{
    if (isEmpty(&top))
    {
        // printf("Stack Empty\n");
        return -9999999;
    }
    else
    {
        return top->element;
    }
}

void freeStack(StackType **top)
{
    if (*top == NULL)
    {
        // printf("Stack is clear\n");
        return;
    }
    else
    {
        StackType *to_free;
        to_free = *top;
        while (to_free != NULL)
        {
            *top = (*top)->next;
            free(to_free);
            to_free = *top;
        }
    }
}