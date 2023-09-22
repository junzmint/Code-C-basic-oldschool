#include<stdio.h>

int sum(int n){
    if(n==1){
        return 1;
    }
    else{
        return n + sum(n-1);
    }
}

int main(){
    int n;
    printf("Nhap so n: ");
    scanf("%d",&n);
    printf("Tong day so tu 1 den n la: %d",sum(n));
    return 0;
}