#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "generic.h"
#define MAX 1000
enum{SUCCESS, FAIL};


int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: <PROGRAM'S NAME> <FILENAMEREAD>");
        return 1;
    }
    FILE *file;
    int reval = SUCCESS;        
    if ((file = fopen(argv[1], "r")) == NULL){
        printf("Cannot open file 1.\n");
        reval = FAIL;
        return reval;
    }
    fseek(file,0,SEEK_END);
    int length,number;
    length = ftell(file);
    fseek(file,0,SEEK_SET);
    number = length/sizeof(elementtype);
    elementtype *readfile;
    readfile = (elementtype*)malloc(length);
    fread(readfile,length,1,file);
    for(int i = 0; i <= (number-1);i++){
        InsertBeforeCur(readfile[i]);
    }
    printf("Name\t\t\tTel\t\t\tEmail\n");
    TravelList();
    root = ReverseList(root);
    printf("Name\t\t\tTel\t\t\tEmail\n");
    TravelList();
    free(readfile);
    FreeList();
    return 0;
}






