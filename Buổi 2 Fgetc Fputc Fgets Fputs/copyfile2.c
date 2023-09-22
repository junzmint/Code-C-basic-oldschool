#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
enum{SUCCESS, FAIL};

void Copy(FILE *name, FILE *new){
    int c;
    c = fgetc(name);
    if(c>=65 && c<=90){
        c+=32;
    }
    else if(c>=97 && c<=122){
        c-=32;
    }
    while ( c != EOF)
    {
        fputc(c,new);
        putchar(c);
        c = fgetc(name);
        if(c>=65 && c<=90){
            c+=32;
         }
        else if(c>=97 && c<=122){
            c-=32;
        }
    }
}

int main(){
    FILE *fptr,*newfile;
    char filename[] = "lab2.txt";
    char filemoi[] = "lab2w.txt";
    int reval = SUCCESS;        

    if ((fptr = fopen(filename, "r")) == NULL){
        printf("Cannot open lab2.txt file.\n");
        reval = FAIL;
    }
    else if ((newfile = fopen(filemoi, "w")) == NULL){
        printf("Cannot open lab2w.txt file.\n");
        reval = FAIL;
    }
    Copy(fptr,newfile);
    fclose(fptr);
    fclose(newfile);
    return reval;
}