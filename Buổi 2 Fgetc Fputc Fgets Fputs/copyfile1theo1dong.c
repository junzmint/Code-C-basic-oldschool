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
int main(){
    FILE *fptr,*newfile;
    char filename[] = "lab3.txt";
    char filemoi[] = "lab3w.txt";
    int reval = SUCCESS;        
    if ((fptr = fopen(filename, "r")) == NULL){
        printf("Cannot open lab3.txt file.\n");
        reval = FAIL;
    }
    else if ((newfile = fopen(filemoi, "w")) == NULL){
        printf("Cannot open lab3w.txt file.\n");
        reval = FAIL;
    }
    Copy(fptr,newfile);
    fclose(fptr);
    fclose(newfile);
    return reval;
}