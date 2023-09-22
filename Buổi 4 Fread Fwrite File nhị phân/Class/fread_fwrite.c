#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
#define MAX_LEN 80
enum{SUCCESS, FAIL};

void Copy(FILE *name, FILE *new){
    int num;
    char buff[MAX_LEN+1];
    while (!feof(name))
    {
        num = fread(buff,sizeof(char),MAX_LEN,name);
        buff[num*sizeof(char)] = '\0';
        printf("%s",buff);
        fwrite(buff,sizeof(char),num,new);
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