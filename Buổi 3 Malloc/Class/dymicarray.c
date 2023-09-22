#include<stdio.h>
#include<stdlib.h>
int main(void){
    int n, *p;
    printf("How many numbers do you want to enter: ");
    scanf("%d",&n);
    p = (int *)malloc(n *sizeof(int));
    if(p == NULL){
        printf("Memory allocation failed");
        return 1;
    }
    for(int i = 0; i < n; i++){
        printf("Number %d will be: ",i+1);
        scanf("%d",&p[i]);
    }
    printf("All the numbers in reverse will be: ");
    for (int i = n-1; i >= 0; i--)
    {      
        
        printf("%d ",p[i]);
    }
    free(p);
    return 0;
}