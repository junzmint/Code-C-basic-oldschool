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
    if(argc != 2){
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: fileread <file to read>");
        return 1;
    }
    FILE *file;
    int reval = SUCCESS;
    if((file = fopen(argv[1],"r+b")) == NULL){
        printf("Cannot open file.\n");
        reval = FAIL;
        return reval;
    }
    phoneaddress *phonearr;
    int irc;
    int length,number;
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    number = length / sizeof(phoneaddress);
    phonearr =(phoneaddress *)malloc(number * sizeof(phoneaddress));
    if (phonearr == NULL){
        printf("Memory allocation failed!\n");
        return FAIL;
    }
    if (fseek(file,0,SEEK_SET) != 0)
    {
        printf("Fseek failed!\n");
        reval = FAIL;
        return reval;
    }
    irc = fread(phonearr, sizeof(phoneaddress), number, file);
    printf("No\tName\t\t\tTel\t\tEmail\n");
    for(int i = 0; i <number; i++){
        printf("%d\t%s\t\t%s\t\t%s\n",(i+1),phonearr[i].name,phonearr[i].tel,phonearr[i].tel);
    }
    free(phonearr);
    fclose(file);
    return 0;
}
