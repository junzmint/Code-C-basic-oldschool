#include<stdio.h>
#include<math.h>
#include<conio.h>
int main(){
    double n, a[11];
    double avr = 0;
    double stv = 10000000;
    double dis = 0;
    double phantutrung;
    printf("Nhap 10 phan tu cua day: \n");
    for(int i=0; i < 10; i++){
        printf("a[%d]= ",i+1);
        scanf("%f",&a[i]);
        avr += a[i];
    }
    avr = avr/10;
    printf("Gia tri trung binh la %f",avr);
    for (int i = 0; i < n; i++)
    {
        dis = a[i] - avr;
        if(dis<0) dis = dis*(-1);
        if(stv > dis){
            stv = dis;
            phantutrung = i;
        }
    }
    printf("Phan tu trung la %f",phantutrung);
    getch();
    return 0;   
}
