#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
enum{SUCCESS, FAIL};

void Copy(FILE *f1, FILE *f2){
    char c[MAX];
    while (fgets(c,MAX,f1) != NULL)
    {
        fprintf(f2,"%d ",strlen(c)-1);
        fprintf(f2, "%s", c);
    }
}
int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: MYCP <FILENAME1> <FILENAME2>");
        return 1;
    }
    FILE *fptr,*newfile;
    int reval = SUCCESS;        
    if ((fptr = fopen(argv[1], "r")) == NULL){
        printf("Cannot open file 1.\n");
        reval = FAIL;
    }
    else if ((newfile = fopen(argv[2], "w")) == NULL){
        printf("Cannot open file 2.\n");
        reval = FAIL;
    }
    Copy(fptr,newfile);
    fclose(fptr);
    fclose(newfile);
    return reval;
}