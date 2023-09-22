#include "Stack_add_subtract.h"
#include <math.h>
#define lower 0
#define upper 9
#define range 4
#define adjustRange1 0 // adjust range < range
#define adjustRange2 0
#include <time.h>

void option1(StackType *top, StackType *top1)
{
    StackType *topTmp = NULL;
    int memory_num_1 = 0;
    int memory_num_2 = 0;
    int memory_num = 0;
    int tmpRanNum = 0;
    printf("First number:  ");
    for (int i = 0; i < range - adjustRange1; i++)
    {
        tmpRanNum = (rand() % (upper - lower)) + lower;
        while (i == 0 && tmpRanNum == 0)
        {
            tmpRanNum = (rand() % (upper - lower)) + lower;
        }
        printf("%d", tmpRanNum);
        push(&top, tmpRanNum);
    }
    printf("\n");
    printf("Second number: ");
    for (int i = 0; i < range - adjustRange2; i++)
    {
        tmpRanNum = (rand() % (upper - lower)) + lower;
        while (i == 0 && tmpRanNum == 0)
        {
            tmpRanNum = (rand() % (upper - lower)) + lower;
        }
        printf("%d", tmpRanNum);
        push(&top1, tmpRanNum);
    }
    printf("\n");
    printf("Result: ");
    while (!isEmpty(&top) || !isEmpty(&top1) || memory_num == 1)
    {
        memory_num_1 = pop(&top);
        memory_num_2 = pop(&top1);
        if (memory_num_1 + memory_num_2 + memory_num >= 10)
        {
            push(&topTmp, memory_num_1 + memory_num_2 + memory_num - 10);
            // printf("%d",memory_num_1 + memory_num_2 + memory_num - 10);
            memory_num = 1;
        }
        else
        {
            push(&topTmp, memory_num_1 + memory_num_2 + memory_num);
            // printf("%d",memory_num_1 + memory_num_2 + memory_num);
            memory_num = 0;
        }
    }
    displayStack(topTmp);
    printf("\n");
    freeStack(&topTmp);
    freeStack(&top);
    freeStack(&top1);
    getchar();
    printf("Press Enter to continue...\n");
    getchar();
}

int checkPriority(StackType *top, StackType *top1)
{
    int priority = 0;
    StackType *temp = top;
    StackType *temp1 = top1;
    while (temp != NULL)
    {
        if (temp->element > temp1->element)
        {
            priority = 1;
        }
        else if (temp->element < temp1->element)
        {
            priority = 2;
        }
        temp = temp->next;
        temp1 = temp1->next;
    }
    return priority;
}

void option2(StackType *top, StackType *top1)
{
    StackType *topTmp = NULL;
    int memory_num_1 = 0;
    int memory_num_2 = 0;
    int memory_num = 0;
    int tmpRanNum = 0;
    int count1 = 0, count2 = 0;
    printf("First number:  ");
    for (int i = 0; i < range - adjustRange1; i++)
    {
        tmpRanNum = (rand() % (upper - lower)) + lower;
        while (i == 0 && tmpRanNum == 0)
        {
            tmpRanNum = (rand() % (upper - lower)) + lower;
        }
        printf("%d", tmpRanNum);
        push(&top, tmpRanNum);
    }
    printf("\n");
    printf("Second number: ");
    for (int i = 0; i < range - adjustRange2; i++)
    {
        tmpRanNum = (rand() % (upper - lower)) + lower;
        while (i == 0 && tmpRanNum == 0)
        {
            tmpRanNum = (rand() % (upper - lower)) + lower;
        }
        printf("%d", tmpRanNum);
        push(&top1, tmpRanNum);
    }
    printf("\n");

    if (range - adjustRange1 > range - adjustRange2)
    {
        printf("Result: ");
        while (!isEmpty(&top) || !isEmpty(&top1))
        {
            memory_num_1 = pop(&top);
            memory_num_2 = pop(&top1);
            if (memory_num_1 - memory_num_2 - memory_num < 0)
            {
                push(&topTmp, 10 + memory_num_1 - memory_num_2 - memory_num);
                // printf("%d",10 + memory_num_1 - memory_num_2 - memory_num);
                memory_num = 1;
            }
            else
            {
                push(&topTmp, memory_num_1 - memory_num_2 - memory_num);
                // printf("%d",memory_num_1 - memory_num_2 - memory_num);
                memory_num = 0;
            }
        }
    }
    else if (range - adjustRange1 < range - adjustRange2)
    {
        printf("Result: -");
        while (!isEmpty(&top) || !isEmpty(&top1))
        {
            memory_num_1 = pop(&top);
            memory_num_2 = pop(&top1);
            if (memory_num_2 - memory_num_1 - memory_num < 0)
            {
                push(&topTmp, 10 + memory_num_2 - memory_num_1 - memory_num);
                // printf("%d",10 + memory_num_1 - memory_num_2 - memory_num);
                memory_num = 1;
            }
            else
            {
                push(&topTmp, memory_num_2 - memory_num_1 - memory_num);
                // printf("%d",memory_num_1 - memory_num_2 - memory_num);
                memory_num = 0;
            }
        }
    }
    else
    {
        if (checkPriority(top, top1) == 1)
        {
            printf("Result: ");
            while (!isEmpty(&top) || !isEmpty(&top1))
            {
                memory_num_1 = pop(&top);
                memory_num_2 = pop(&top1);
                if (memory_num_1 - memory_num_2 - memory_num < 0)
                {
                    push(&topTmp, 10 + memory_num_1 - memory_num_2 - memory_num);
                    // printf("%d",10 + memory_num_1 - memory_num_2 - memory_num);
                    memory_num = 1;
                }
                else
                {
                    push(&topTmp, memory_num_1 - memory_num_2 - memory_num);
                    // printf("%d",memory_num_1 - memory_num_2 - memory_num);
                    memory_num = 0;
                }
            }
        }
        else
        {
            printf("Result: -");
            while (!isEmpty(&top) || !isEmpty(&top1))
            {
                memory_num_1 = pop(&top);
                memory_num_2 = pop(&top1);
                if (memory_num_2 - memory_num_1 - memory_num < 0)
                {
                    push(&topTmp, 10 + memory_num_2 - memory_num_1 - memory_num);
                    // printf("%d",10 + memory_num_1 - memory_num_2 - memory_num);
                    memory_num = 1;
                }
                else
                {
                    push(&topTmp, memory_num_2 - memory_num_1 - memory_num);
                    // printf("%d",memory_num_1 - memory_num_2 - memory_num);
                    memory_num = 0;
                }
            }
        }
    }
    while (1 == 1)
    {
        if(peek(topTmp) == 0){
            pop(&topTmp);
        }
        else
        {
            break;
        }
    }
    
    displayStack(topTmp);
    printf("\n");
    freeStack(&topTmp);
    freeStack(&top);
    freeStack(&top1);
    getchar();
    printf("Press Enter to continue...\n");
    getchar();
}

int main()
{
    StackType *top, *top1;
    top = NULL;
    top1 = NULL;
    int choice;
    do
    {
        printf("=======================WELCOME TO MAIN MENU====================\n");
        printf("1. Add very large interger numbers\n");
        printf("2. Subtract very large interger numbers\n");
        printf("3. Quit\n");
        printf("===============================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            option1(top, top1);
        }
        if (choice == 2)
        {
            option2(top, top1);
        }

    } while (choice != 3);
}