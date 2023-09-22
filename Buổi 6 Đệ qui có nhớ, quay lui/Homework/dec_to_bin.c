#include<stdio.h>
#include<string.h>
#define MAX 100
int c[MAX];
void change(int n,int i){
    if(n == 0){
        c[i] = 0;
        c[i+1] = 2;
    }
    if(n == 1){
        c[i] = 1;
        c[i+1] = 2;
    }
    else{
        int m, sodu;
        m = n / 2;
        sodu = n - 2*m;
        c[i] = sodu;
        c[i+1] = 2;
        if(m >= 0){
            change(m,i+1);
        }
    }
}

int main(){
    int n;
    int check;
    printf("Nhap so n: ");
    scanf("%d",&n);
    change(n,0);
    for(int i = 0; i< MAX;i++){
        if(c[i]==2){
            check = i-1;
            break;
        }
    }
    printf("So dang nhi phan cua %d la: ",n);
    for(int i = check; i>=0;i--){
        printf("%d",c[i]);
    }
    return 0;
}