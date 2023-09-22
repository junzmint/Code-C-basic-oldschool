#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int x[MAX];
int count = 0;

void solution(int k){
    for(int i = 1; i <= k ;i++){
        printf("%d ",x[i]);
    }
    printf("\n");
}

int check(int v,int h){
    for(int i = 1; i < h; i++){
        if (x[i] >= v)
        {
            return 0;
        }
    }
}

int check2(int v, int h){
    for(int i = 1; i<h;i++){
        if (abs(x[i] - v) == 1){
            return 0;
        }
    }
}


int Try(int k,int n, int i){
    for (int v = 1; v <=n; v++){
        if(i == 1){
            x[i] = v;
            Try(k,n,i+1);
        }
        else if(check(v,i) == 0){
            continue;
        }
        else if(check2(v,i) == 0){
            continue;
        }
        else{
            x[i] = v;
            if(i == k){
                solution(k);
                count ++;
            }
            else{
                Try(k,n,i+1);
            }
        }
    }
}

int main(){
    x[0] = 0;
    int k,n;
    printf("Nhap so k: ");
    scanf("%d",&k);
    printf("Nhap do dai day n: ");
    scanf("%d",&n);
    printf("Cac to hop chap k cua n phan tu ma 2 phan tu dung canh nhau khong duoc chon la:\n");
    Try(k,n,1);
    if(count == 0){
        printf("Khong co to hop phu hop yeu cau de bai");
    }
    return 0;
}