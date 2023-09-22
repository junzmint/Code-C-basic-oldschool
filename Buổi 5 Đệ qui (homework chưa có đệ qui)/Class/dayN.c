#include<stdio.h>

int Sotunhien(int n){
    if(n<=50){
        printf("%d ",n);
        Sotunhien(n+1);
    }
}

int main(){
    int n = 1;
    printf("Day 50 so tu nhien dau la:\n");
    Sotunhien(n);
    return 0;
}