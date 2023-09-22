/*Viết chương trình file merge*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000
enum{SUCCESS, FAIL};

void Merge(FILE *f1, FILE *f2, FILE *f3){
    char buff1[MAX], buff2[MAX];
    int len;
    while ((fgets(buff1, MAX,f1)!= NULL) && (fgets(buff2, MAX, f2)!=NULL))
    {
        fputs(buff1,f3);
        fputs(buff2, f3);
    }
    if(buff1!=NULL) fputs(buff1,f3);
    while (fgets(buff1, MAX,f1)!= NULL)
    {
        fputs(buff1,f3);
    }
    while (fgets(buff2, MAX,f2)!= NULL)
    {
        fputs(buff2,f3);
    }
    
}

    


int main(int argc, char* argv[]){
    if(argc != 4){
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: MYCP <FILENAME1> <FILENAME2> <FILENAME3>");
        return 1;
    }
    FILE *file1,*file2,*file3;
    int reval = SUCCESS;        
    if ((file1 = fopen(argv[1], "r")) == NULL){
        printf("Cannot open file 1.\n");
        reval = FAIL;
    }
    if ((file2 = fopen(argv[2], "r")) == NULL){
        printf("Cannot open file 2.\n");
        reval = FAIL;
    }
    if ((file3 = fopen(argv[3], "w")) == NULL){
        printf("Cannot open file 3.\n");
        reval = FAIL;
    }
    Merge(file1,file2,file3);
    fclose(file1);
    fclose(file2);
    fclose(file3);
    return reval;
}