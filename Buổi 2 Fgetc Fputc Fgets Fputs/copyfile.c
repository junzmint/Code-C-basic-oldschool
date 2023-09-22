#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
enum{SUCCESS, FAIL};
void Copy(FILE *name, FILE *new){
    int c;
    c = fgetc(name);
    while ( c != EOF)
    {
        fputc(c,new);
        putchar(c);
        c = fgetc(name);
    }
}

int main(){
    FILE *fptr,*newfile;
    char filename[] = "lab1.txt";
    char filemoi[] = "lab1w.txt";
    int reval = SUCCESS;        

    if ((fptr = fopen(filename, "r")) == NULL){
        printf("Cannot open lab1.txt file.\n");
        reval = FAIL;
    }
    else if ((newfile = fopen(filemoi, "w")) == NULL){
        printf("Cannot open lab1w.txt file.\n");
        reval = FAIL;
    }
    Copy(fptr,newfile);
    fclose(fptr);
    fclose(newfile);
    return reval;
}