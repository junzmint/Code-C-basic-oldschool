#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
enum{SUCCESS, FAIL};

void Copy(FILE *name, FILE *new){
    char c[MAX];
    while ( fgets(c,MAX,name) != NULL)
    {
        fputs(c,new);
        puts(c);
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
        printf("Cannot open file 1 file.\n");
        reval = FAIL;
    }
    else if ((newfile = fopen(argv[2], "a")) == NULL){
        printf("Cannot open file 2 file.\n");
        reval = FAIL;
    }
    Copy(fptr,newfile);
    fclose(fptr);
    fclose(newfile);
    return reval;
}