#include<stdio.h>
int fib(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else return fib(n-1)+fib(n-2);
}
int main (){
    int k ,n;
    printf("enter n=");scanf("%d",&n);
//    printf("enter k=");scanf("%d",&k);
    for(int i=0;i<n;i++){
        printf("%d ",fib(i));   
    }
}