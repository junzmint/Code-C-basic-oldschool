#include<stdio.h>
#include<conio.h>
#define MAX 1000
int SoSanhChuoi(int *a,int *b,int n){
    if(a[0]==b[0]){
        for(int i = 0; i < n; i++ ){
            if (a[i] == b[i])
            {
                return 1;
            }
            else{
                return 0;
                break;
            }
        }
    }
    else{
        for(int i = 0, j = n-1; i < n, j>=0; i++,j--){
            if (a[i] == b[j])
            {
                return -1;
            }
            else{
                return 0;
            }
        }  
    }  
}

int main(){
    int a[MAX];
    int b[MAX];
    int n,m;
    printf("Nhap so phan tu cua mang a: ");
    scanf("%d",&n);
    printf("Nhap so phan tu cua mang b: ");
    scanf("%d",&m);
    if (n!=m){
        printf("\nHai mang nay do dai khac nhau");
    }
    else{
        for(int i=0; i<n;i++){
            printf("So hang thu %d cua mang a la: ",i+1);
            scanf("%d",&a[i]);
        }
        for(int i=0; i<n;i++){
            printf("So hang thu %d cua mang b la: ",i+1);
            scanf("%d",&b[i]);
        }
        int m = SoSanhChuoi(a,b,n);
        if(m == 1){
            printf("\nHai mang nay giong nhau");
        }
        else if (m == -1)
        {
            printf("\nHai mang nay nghich dao");
        }
        else if (m == 0){
            printf("\nHai mang nay khac nhau");
        }
    }
    getch();
    return 0;
}

