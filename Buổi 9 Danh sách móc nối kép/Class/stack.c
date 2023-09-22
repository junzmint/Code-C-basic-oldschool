#include<stdio.h>
#include"stackarr.h"


int main(){
    StackType stack;
    initialize(stack);
    int n;
    int a[MAX];
    printf("Choose the number of the stack: ");
    scanf("%d",&n);
    for(int i = 0; i<n; i++){
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
    for(int i = 0; i<n; i++){
        push(a[i],stack);
        printf("The element is push in the stack is %d\n",a[i]);
    }
    printf("The stack is: ");
    for(int i = 0; i<top; i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
    printf("The peek of the stack is: %d\n",peek(stack));
    int popva;
    while(!isEmpty(stack)){
        popva = pop(stack);
        printf("The element is pop out of the stack is %d\n",popva);
    }
    if(isEmpty(stack)){
        printf("The stack is empty\n");
    }
    return 0;
}