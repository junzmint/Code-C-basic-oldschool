#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 1000

typedef struct BangTen
{
    char name[100];
    char firstname[10];
}BangSV;

void SapXep(BangSV *a,int n){
    
    for(int i=0; i<n-1; i++){
        for(int j=i+1;j<n;j++){
           for(int k = 0; k<10;k++){
                BangSV d;
                if(a[i].firstname[k] == '\0' || a[j].firstname[k] == '\0' ){
                    break;
                }
                else if(a[i].firstname[k] == a[j].firstname[k]){
                    continue;
                }
                else if(a[i].firstname[k] > a[j].firstname[k]){
                    d = a[i];
                    a[i] = a[j];
                    a[j] = d;
                    break;
                }
                else{
                    break;
                }
            }
        }
    }
}


int main(){
    int sosinhvien;
    BangSV array[MAX];
    printf("Nhap so sinh vien: ");
    scanf("%d",&sosinhvien);
    getchar();
    for(int i=0; i<sosinhvien;i++){
        printf("Nhap ten sinh vien thu %d : ",i+1);
        gets(array[i].name);
        fflush(stdin);
    }
    for(int i=0; i<sosinhvien;i++){
        char m[10];
        for(int j=0,k = strlen(array[i].name)-1; j<10,k>=0;j++,k--){
            if(array[i].name[k] != ' '){
                m[j] = array[i].name[k];
            }
            else{
                m[j] = '\0';
                break;
            }
        }
        for(int j=0,k = strlen(m)-1; j<10,k>=0;j++,k--){
            if(m[k] != '\0'){
                array[i].firstname[j] = m[k];
            }
        }
        array[i].firstname[strlen(m)] = '\0';
    }
    SapXep(array,sosinhvien);
    printf("\nBang sap xep ten theo thu tu la\n");
    for(int i=0;i<sosinhvien;i++){
        printf("%d.%s\n",i+1,array[i].name);
    }
    getch();
    return 0;
}