#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000
int main(int argc, char* argv[]){
    char c[MAX];
    if (argc < 2)
    {
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: ./inverse <SENTENCE>....");
        return 1;
    }
    printf("The inverse sentence is:\n");
    for(int i = argc -1 ; i>0 ; i--){
        printf("%s",argv[i]);
    }
    return 0;
}