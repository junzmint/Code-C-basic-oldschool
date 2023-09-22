#include<stdio.h>
#include<conio.h>
void ChuyenDoi(double *a, int *m, double *n){
    int m = *a;
    double n = *a - m;
    printf("Phan nguyen la %d\n",m);
    printf("Phan thap phan la %f",n);
}
int main(){
    double a = 10.57;
    printf("\nSo a la %f\n",a);
    ChuyenDoi(&a);
    getch();
    return 0;
}