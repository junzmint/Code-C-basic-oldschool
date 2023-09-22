#define MAX 50
typedef int Eltype;
typedef Eltype StackType[MAX];
int top;

void initialize(StackType stack){
    top = 0;
}

int isEmpty(StackType stack){
    return top == 0;
}

int isFull(StackType stack){
    return top == MAX;
}

void push(Eltype el,StackType stack){
    if(isFull(stack)){
        printf("Stack overflow\n");
    }
    else
    {
        stack[top] = el;
        top ++;
    }
}

Eltype pop(StackType stack){
    if(isEmpty(stack)){
        printf("Stack underflow\n");
    }
    else{
        top --;
        return stack[top];
    }
}

Eltype peek(StackType stack){
    if(isEmpty(stack)){
        printf("Stack underflow\n");
        return -10;
    }
    else{
        return stack[top -1];
    }
}