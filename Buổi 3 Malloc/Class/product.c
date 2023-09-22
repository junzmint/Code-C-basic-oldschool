#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
enum{SUCCESS, FAIL};

typedef struct Banggia{
    int number;
    char name[1000];
    long int price;
}BangGia;

void Copy(FILE *f1){
    BangGia d[MAX];
    int i = 0;
    char c[MAX];
    printf("No\tProductName\t\t\tPrice\n");
    while (fscanf(f1,"%d\t%s\t%d",&d[i].number,&d[i].name,&d[i].price) != EOF)
    {
        printf("%d\t%s\t\t%d\n",d[i].number,d[i].name,d[i].price);
        i++;
    }
   ;
}


int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: MYCP <FILENAME1> <FILENAME2>");
        return 1;
    }
    FILE *file1;
    int reval = SUCCESS;        
    if ((file1 = fopen(argv[1], "r")) == NULL){
        printf("Cannot open file 1.\n");
        reval = FAIL;
    }
    Copy(file1);
    fclose(file1);
    return reval;
}