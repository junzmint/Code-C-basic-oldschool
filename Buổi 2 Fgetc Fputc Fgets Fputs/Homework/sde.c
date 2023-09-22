#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 1000

float TinhNghiem(float a, float b, float c, float delta){
    if(a == 0){
        printf("He so A = 0, phuong trinh co 1 nghiem la : %f",-c/b);
    }
    else{
        if(delta == 0 ){
            printf("Phuong trinh co nghiem kep : %f",-b/(2*a));
        }
        else if(delta > 0){
            printf("Phuong trinh co 2 nghiem phan biet :\n");
            printf("x1 = %f\n",(-b+sqrt(delta)/(2*a)));
            printf("x2 = %f",(-b-sqrt(delta)/(2*a)));
        }
        else{
            printf("Phuong trinh vo nghiem");
        }
    }
}

int main(int argc, char* argv[]){
    float a, b, c, delta;
    if(argc != 4){
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: SDE <A> <B> <C>");
        return 1;
    }
    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);
    delta = b*b - 4*a*c;
    TinhNghiem(a,b,c,delta);
    int choose = 0;
    while (choose == 0 || choose ==1)
    {
        if (choose != 1 && choose != 2)
        {
            printf("\nNhap so ban mong muon\n");
            printf("1. De tinh tiep phuong trinh bac 2 moi.\n");
            printf("2. De thoat chuong trinh.\n");
            printf("Nhap so ban muon : ");
            scanf("%d",&choose);
        }
        else if(choose == 1){
            float d,e,f,delta2;
            printf("\nNhap he so a : ");
            scanf("%f",&d);
            printf("Nhap he so b : ");
            scanf("%f",&e);
            printf("Nhap he so c : ");
            scanf("%f",&f);
            delta2 = e*e - 4*d*f;
            TinhNghiem(d,e,f,delta2);
            printf("\nNhap so 1 hoac 2 de tiep tuc....\n");
            printf("1. De tinh tiep phuong trinh bac 2 moi.\n");
            printf("2. De thoat chuong trinh.\n");
            printf("Nhap so ban muon : ");
            scanf("%d",&choose);
        }
        else if (choose ==2)
        {
            printf("Tam biet....\n");
            exit(0);
        }
    }
    return 0;
}
    
    
    
