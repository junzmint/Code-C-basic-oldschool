#include<stdio.h>

int multi(int n, int k){
    if(n == 0 || k == 0){
        return 0;
    }
    if(n == 1){
        return k;
    }
    if(n > 1){
        return k + multi(n-1,k);
    }
}
int main(){
    int n,k;
    printf("Nhap n: ");
    scanf("%d",&n);
    printf("Nhap k: ");
    scanf("%d",&k);
    printf("%d x %d = %d",n,k,multi(n,k));
    return 0;
}