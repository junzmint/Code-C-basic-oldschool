#include<stdio.h>

int C(int k, int n){
    if(k==0||k==n){
        return 1;
    }
    int C1 = C(k-1,n-1);
    int C2 = C(k,n-1);
    return (C1+C2);
}

int main(){
    int n,k;
    printf("Tinh to hop chap k cua n phan tu.\n");
    printf("Nhap k: ");
    scanf("%d",&k);
    printf("Nhap n: ");
    scanf("%d",&n);
    while (k>n)
    {
        printf("Khong hop le");
        printf("Nhap k: ");
        scanf("%d",&k);
        printf("Nhap n: ");
        scanf("%d",&n);
    }
    printf("To hop chap %d cua %d phan tu la %d",k,n,C(k,n));
    return 0;
}