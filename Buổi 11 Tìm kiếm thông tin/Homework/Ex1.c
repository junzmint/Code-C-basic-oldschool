#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max 1000
#define offset 10000

enum
{
    PUSH = 1,
    POP = -1
};

#include "stackRec.h"

int option1(stackType *stack1, stackType *stack2, stackType *stack3)
{
    int number = 0;
    printf("Enter the number you want to add: ");
    scanf("%d", &number);
    push(stack1, number);
    push(stack2, PUSH);
    push(stack3, number);
    printf("Press Enter to continue...\n");
    getchar();
}

int option2(stackType stack1)
{
    if (peek(stack1) != 0)
    {
        printf("Top number of stack is: %d\n", peek(stack1));
    }
    printf("Press Enter to continue...\n");
    getchar();
}

int option3(stackType *stack1, stackType *stack2, stackType *stack3)
{
    int tmpNum = 0;
    tmpNum = peek(*stack1);
    pop(stack1);
    push(stack2, POP);
    push(stack3, tmpNum);
    printf("Press Enter to continue...\n");
    getchar();
}

int option4(stackType *stack1, stackType *stack2, stackType *stack3)
{
    int undoNum = 0;
    undoNum = peek(*stack2);
    if (undoNum == PUSH)
    {
        pop(stack2);
        pop(stack3);
        pop(stack1);
    }
    else if (undoNum == POP)
    {
        pop(stack2);
        undoNum = peek(*stack3);
        pop(stack3);
        push(stack1, undoNum);
    }
    printf("Press Enter to continue...\n");
    getchar();
}

void menu(stackType stack1, stackType stack2, stackType stack3)
{
    int choice;
    do
    {
        printf("=======================WELCOME TO MAIN MENU====================\n");
        printf("1. Add 1 integer to the stack\n");
        printf("2. View top\n");
        printf("3. Remove from the stack contains intergers 1\n");
        printf("4. Undo\n");
        printf("5. Exit\n");
        printf("===============================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            option1(&stack1, &stack2, &stack3);
            getchar();
        }
        if (choice == 2)
        {
            option2(stack1);
            getchar();
        }
        if (choice == 3)
        {
            option3(&stack1, &stack2, &stack3);
            getchar();
        }
        if (choice == 4)
        {
            option4(&stack1, &stack2, &stack3);
            getchar();
        }
    } while (choice != 5);
}

void main()
{
    stackType stack1, stack2, stack3;
    initialize(&stack1);
    initialize(&stack2);
    initialize(&stack3);
    menu(stack1, stack2, stack3);
}
