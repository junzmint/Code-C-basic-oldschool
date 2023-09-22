#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max 50

typedef int Eltype;
typedef struct StackRec{
    Eltype storage[Max];
    int top;
}stackType;


void initialize(stackType *stack){
    stack->top = 0;
}

int isEmpty(stackType stack)
{
    return stack.top == 0;
}

int isFull(stackType stack)
{
    return stack.top == Max;
}

void push(stackType *stack, int value)
{
    if (isFull(*stack))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack->storage[stack->top] = value;
        stack->top++;
    }
}

void pop(stackType *stack)
{
    if (isEmpty(*stack))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        stack->top--;
    }
}

Eltype peek(stackType stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Empty\n");
    }
    else
    {
        return stack.storage[stack.top];
    }
}