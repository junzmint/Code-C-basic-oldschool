typedef struct input
{
    char name[length_of_name];
    char mem_space[MemSpaceSize];
    char screen_size[ScreenMaxSize];
    char price[MaxPricedSize];
}elementess;

typedef elementess ElType;

typedef struct nodeType
{
    ElType element;
    struct nodeType *left;
    struct nodeType *right;
} node;

typedef node *treeType;

enum
{
    SUCCESS = 0,
    ERROR = 1,
    TXT = 2,
    DAT = 3
};


int checkFileType(char check)
{
    if (check == 'd')
    {
        return DAT;
    }
    if (check == 't')
    {
        return TXT;
    }
}