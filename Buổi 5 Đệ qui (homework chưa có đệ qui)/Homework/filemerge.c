#include<stdio.h>
#include<stdlib.h>
#include <string.h>
enum {SUCCESS, FAIL};

typedef struct phoneaddress {
      char name[20];
      char tel[11];
      char email[25];
}phoneaddress;

int main(int argc, char *argv[]){
    if(argc != 4){
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: filemerge <file 1> <file2> <file is printed the merge data>");
        return 1;
    }
    FILE *filemerge,*file1,*file2;
    int reval = SUCCESS;
    if((filemerge = fopen(argv[3],"w+b")) == NULL){
        printf("Cannot open file to split.\n");
        reval = FAIL;
        return reval;
    }
    if ((file1 = fopen(argv[1],"r+b")) == NULL)
    {
        printf("Cannot open file 1");
        reval = FAIL;
        return FAIL;
    }
    if ((file2 = fopen(argv[2],"r+b")) == NULL)
    {
        printf("Cannot open file 2");
        reval = FAIL;
        return FAIL;
    }
    int length1;
    fseek(file1,0,SEEK_END);
    length1 = ftell(file1);
    fseek(file1,0,SEEK_SET);
    int length2;
    fseek(file2,0,SEEK_END);
    length2 = ftell(file2);
    fseek(file2,0,SEEK_SET);
    phoneaddress *phonearr1,*phonearr2;
    int i, irc;
    phonearr1 =(phoneaddress *)malloc(length1);
    phonearr2 =(phoneaddress *)malloc(length2);
    if (phonearr1 == NULL){
        printf("Memory allocation failed!\n");
        return FAIL;
    }
    if (phonearr2 == NULL){
        printf("Memory allocation failed!\n");
        return FAIL;
    }
    if (fseek(filemerge,0,SEEK_SET) != 0)
    {
        printf("Fseek failed!\n");
        reval = FAIL;
        return reval;
    }
    fseek(filemerge,0,SEEK_SET);
    irc = fread(phonearr1, 1, (length1),file1);
    irc = fwrite(phonearr1, 1, (length1), filemerge);
    fseek(filemerge,0,SEEK_END);
    irc = fread(phonearr2, 1, (length2),file2);
    irc = fwrite(phonearr2, 1, (length2), filemerge);
    free(phonearr1);
    free(phonearr2);
    fclose(file1);
    fclose(file2);
    fclose(filemerge);
    return reval;
}

