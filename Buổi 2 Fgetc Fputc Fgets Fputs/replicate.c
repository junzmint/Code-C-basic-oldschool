#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
int main(int argc, char* argv[]){
    char c[MAX];
    int n;
    if (argc != 3)
    {
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: ./replicate <WORD> <TIME>");
        return 1;
    }
    strcpy(c,argv[1]);
    n = atof(argv[2]);
    printf("The string returns back:\n");
    for(int i =0;i<n;i++){
        printf("%s",c);
    }
    return 0;
}