#include <stdio.h>
#define N 100
int tohop[N][N];
int C(int k, int n){
    if(k == 0|| k == n){
        tohop[k][n] = 1;
    }
    else{
        if(tohop[k][n]<0){
            tohop[k][n] = C(k,n-1) + C(k-1,n-1);
        }
    }
    return tohop[k][n];
}

void init(){
    for(int i = 0; i<N;i++){
        for(int j = 0; j<N;j++){
            tohop[i][j] = -1;
        }
    }
}

int main(){
    init();
    int n,k;
    printf("Nhap k: ");
    scanf("%d",&k);
    printf("Nhap n: ");
    scanf("%d",&n);
    printf("To hop chap k cua n phan tu: %d",C(k,n));
    return 0;
}