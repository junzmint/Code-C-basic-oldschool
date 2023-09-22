#include<stdio.h>
#include<string.h>
#include<conio.h>

char HamDoiSo(char *a,char b, char c){
    int i;
    for(i=0; i< 1000;i++){
        if(a[i] == b){
            a[i] = c;
        }
    }
}

int main(){
    char a[1000];
    char b;
    char c;
    printf("Nhap chuoi a: ");
    gets(a);
    printf("Nhap ki tu thu nhat :");
    scanf("%c",&b);
    fflush(stdin);
    printf("Nhap ki tu thu hai :");
    scanf("%c",&c);
    fflush(stdin);
    HamDoiSo(a,b,c);
    printf("%s",a);
    return 0;
}