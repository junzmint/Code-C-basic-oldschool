#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000
#define length_of_name 100
#define MemSpaceSize 8
#define ScreenMaxSize 5
#define MaxPricedSize 10

enum
{
    SUCCESS = 0,
    ERROR = 1,
    DAT = 2
};

typedef struct input
{
    char name[length_of_name];
    char mem_space[MemSpaceSize];
    char screen_size[ScreenMaxSize];
    char price[MaxPricedSize];
}elementess;

// typedef ... element_type;
typedef elementess element_type;

struct node_t
{
    element_type element;
    struct node_t *next;
    struct node_t *prev;
};

typedef struct node_t node;
typedef node *doublelist;

element_type *phoneDB;

int checkFileType(char check)
{
    if (check == 'd')
    {
        return DAT;
    }
}

