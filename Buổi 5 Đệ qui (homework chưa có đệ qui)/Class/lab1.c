#include<stdio.h>

int triangle(int n){
    if(n == 1){
        return 1;
    }
    else{
        return (n + triangle(n-1));
    }
}

int main(){
    int n;
    printf("Nhap so luong so cua day triange: ");
    scanf("%d",&n);
    for (int i = 1; i <=n; i++)
    {
        printf("%d ",triangle(i));
    }
    return 0;
}