#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
enum{SUCCESS, FAIL};
void Copy(FILE *name, FILE *new){
    char c[MAX];
    char a = '\n';
    while ( fgets(c,MAX,name) != NULL)
    {
        fputs(c,new);
        fputc(a,new);
        puts(c);
    }
}
int main(){
    FILE *fptr,*newfile;
    char filename[] = "lab4.txt";
    char filemoi[] = "lab4w.txt";
    int reval = SUCCESS;        
    if ((fptr = fopen(filename, "r")) == NULL){
        printf("Cannot open lab4.txt file.\n");
        reval = FAIL;
    }
    else if ((newfile = fopen(filemoi, "w")) == NULL){
        printf("Cannot open lab4w.txt file.\n");
        reval = FAIL;
    }
    Copy(fptr,newfile);
    fclose(fptr);
    fclose(newfile);
    return reval;
}