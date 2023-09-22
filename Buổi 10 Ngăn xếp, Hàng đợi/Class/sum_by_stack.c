#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int elementtype;
#include"StackGen.h"
#define MAX 10000
    /*
int main(){
    Stacktype *top;
    int a;
    int p;
    for(int i = 0; i < 5; i ++){
        printf("Insert a[%d]: ",i+1);
        scanf("%d",&a);
        Push(a,&top);
    }
    printf("The peek of stack is: %d\n",Peek(&top));
    for(int i = 0; i < 5; i ++){
        p = Pop(&top);
        printf("The element is pop out of the stack is %d\n",p);
    }
    return 0;
}
    */
int main(){
    Stacktype *top1, *top2, *top3;
    int c1, c2, carry;
    c1 = c2 = carry = 0;
    char num1[MAX], num2[MAX];
    intialize(&top1);intialize(&top2); intialize(&top3);
    int sum;
    printf("Input the first number: ");
    gets(num1);
    printf("Input the second number: ");
    gets(num2);
    for(int i = 0; i < strlen(num1); i++){
        Push(num1[i] - '0', &top1);
    }
    for(int i = 0; i < strlen(num2); i++){
        Push(num2[i] - '0', &top2);
    }
    while (!isEmpty(top1) || !isEmpty(top2))
    {
        if(!isEmpty(top1)) c1 = Pop(&top1);
        else c1 = 0;
        if(!isEmpty(top2)) c2 = Pop(&top2);
        else c2 = 0;
        sum = c1 + c2 + carry;
        carry = 0;
        if(sum >= 10){
            Push(sum - 10,&top3);
            carry = 1;
        }
        else{
            Push(sum,&top3);
            carry = 0;
        }
    }
    if(carry > 0) Push(carry,&top3);
    while (!isEmpty(top3))
    {
        printf("%d",Pop(&top3));
    }
    return 0;
}
