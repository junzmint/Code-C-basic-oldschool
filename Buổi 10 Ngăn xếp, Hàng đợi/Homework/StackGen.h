/*
typedef struct elementtype {
      char name[20];
      char tel[11];
      char email[25];
}elementtype;
*/
typedef struct Stacktype_t{
    int element;
    struct Stacktype_t *next;
}Stacktype;

void intialize(Stacktype **top){
    *top = NULL;
    return;
}

int isEmpty(Stacktype *top){
    return (top == NULL);
}

void Push(int element, Stacktype **top){
    Stacktype *new = (Stacktype*)malloc(sizeof(Stacktype));
    if(new == NULL){
        printf("Malloc Error\n");
    }
    else{
        new->element = element;
        new->next = *top;
        *top = new;
    }
}

int Pop(Stacktype **top){
    Stacktype *p;
    if(!isEmpty(*top)){
        int temp;
        temp = (*top)->element;
        p = *top;
        *top = (*top)->next;
        free(p);
        return temp;
    }
    else{
        printf("Stack empty\n");
    }
}

int Peek(Stacktype **top){
    if(*top == NULL){
        printf("Stack empty");
        return 0;
    }
    else{
        return (*top)->element;
    }
}

void FreeStack(Stacktype **top){
    if(*top == NULL){
        printf("Stack empty");
        return;
    }
    else{
        Stacktype *to_free = *top;
        while (to_free != NULL)
        {
            *top = (*top)->next;
            free(to_free);
            to_free = *top;
        }
        printf("The stack is free now\n");   
    }
}


