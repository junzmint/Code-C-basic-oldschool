/*
typedef struct float {
      char name[20];
      char tel[11];
      char email[25];
}float;
*/
typedef struct StackType_t{
    float element;
    struct StackType_t *next;
}StackType;

void Intialize(StackType **top){
    *top = NULL;
    return;
}

int IsEmpty(StackType *top){
    return (top == NULL);
}

void push(float element, StackType **top){
    StackType *data;
    data = (StackType*)malloc(sizeof(StackType));
    if(data == NULL){
        printf("Malloc Error\n");
    }
    else{
        data->element = element;
        data->next = *top;
        *top = data ;
    }
}

float pop(StackType **top){
    StackType *p;
    if(!IsEmpty(*top)){
        float temp;
        temp = (*top)->element;
        p = *top;
        *top = (*top)->next;
        free(p);
        return temp;
    }
    /*
    else{
        printf("Stack empty\n");
    }
    */
}

float peek(StackType **top){
    if(*top == NULL){
        printf("Stack empty");
        return 0;
    }
    else{
        return (*top)->element;
    }
}

void freeStack(StackType **top){
    if(*top == NULL){
        //printf("Stack empty\n");
        return;
    }
    else{
        StackType *to_free = *top;
        while (to_free != NULL)
        {
            *top = (*top)->next;
            free(to_free);
            to_free = *top;
        }
        printf("The stack is free now\n");   
    }
}


