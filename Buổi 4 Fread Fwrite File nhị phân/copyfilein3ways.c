#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000
#define MAX_LEN 80
enum{SUCCESS, FAIL};

void character(FILE *file1, FILE *file2){
    int c;
    c = fgetc(file1);
    while (c != EOF)
    {
        fputc(c,file2);
        c = fgetc(file1);
    }
}

void line(FILE *file1, FILE *file2){
    char c[MAX];
    while ( fgets(c,MAX,file1) != NULL)
    {
        fputs(c,file2);
    }
}

void block(FILE *file1,FILE *file2) {
    char *s;
    int n, irc;
    printf("Size of block (char): ");
    scanf("%d", &n);
    s = (char *)malloc(n * sizeof(char));
    fseek(file1, SEEK_SET, 0);
    while(fread(s, sizeof(char), n, file1) != 0){
    fwrite(s, sizeof(char), n, file2);
    }
}

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: <PROGRAM'S NAME> <FILENAMECOPY> <FILENAMEPRINT>");
        return 1;
    }
    FILE *file1,*file2;
    int reval = SUCCESS;        
    if ((file1 = fopen(argv[1], "r")) == NULL){
        printf("Cannot open file 1.\n");
        reval = FAIL;
        return reval;
    }
    if ((file2 = fopen(argv[2], "w")) == NULL){
        printf("Cannot open file 2.\n");
        reval = FAIL;
        return reval;      
    }
    int choose;
    double time, start, end;
    printf("Choose your option: \n");
    printf("1. Copy by character\n2. Copy by line\n3. Copy by block - optional size\n");
    printf("Type your option here: ");
    scanf("%d",&choose);
    switch (choose)
    {
    case 1:
        start = clock();
        character(file1,file2);
        end = clock();
        time = (end - start);
        printf("Run time is %f",time/1000);
        break;
    case 2:
        start = clock();
        line(file1,file2);
        end = clock();
        time = (end - start);
        printf("Run time is %f",time/1000);
        break;
    case 3:
        start = clock();
        block(file1,file2);
        end = clock();
        time = (end - start);
        printf("Run time is %f",time/1000);
        break;
    default:
        printf("Invalid, choose again: ");
        scanf("%d",&choose);
        break;
    }
    fclose(file1);
    fclose(file2);
    return reval;
}