#include<stdio.h>
#include<string.h>
#include<conio.h>
int main(){
    char a[1000];
    int i;
    printf("Nhap chuoi: ");
    fgets(a, sizeof(a),stdin);
    printf("Chuoi nhap la: %s",a);
    int b[1000] = {0};
    for (i = 0; i < strlen(a); i++)
    {
        b[a[i]] += 1; 
    }
    for (i = 90; i <= 122;i++){
        if(b[i]!=0) printf("Chu cai "%c" xuat hien %d \n",i, b[i]);
    }
    getch();
    return 0;
}