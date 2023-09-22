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
    if(argc != 5){
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: filesplit <file to read> <the number of contact of file1> <file1> <file2>");
        return 1;
    }
    FILE *filesplit,*file1,*file2;
    int reval = SUCCESS;
    if((filesplit = fopen(argv[1],"r+b")) == NULL){
        printf("Cannot open file to split.\n");
        reval = FAIL;
        return reval;
    }
    int numbercontact1;
    numbercontact1 = atoi(argv[2]);
    int length,number;
    fseek(filesplit, 0, SEEK_END);
    length = ftell(filesplit);
    number = length / sizeof(phoneaddress);
    fseek(filesplit, 0, SEEK_SET);
    phoneaddress *phonearr;
    int irc;
    phonearr =(phoneaddress *)malloc(number * sizeof(phoneaddress));
    if (phonearr == NULL){
        printf("Memory allocation failed!\n");
        return FAIL;
    }
    if (numbercontact1 >= number)
    {   
        printf("The number of contacts you want to split is more than the number of contacts in phonebook.dat, so every contacts will be print in phonebook1.dat.\n");
        if ((file1 = fopen(argv[3],"w+b")) == NULL)
        {
            printf("Cannot open file 1");
            reval = FAIL;
            return FAIL;
        }
        if (fseek(filesplit,0,SEEK_SET) != 0)
        {
            printf("Fseek failed!\n");
            reval = FAIL;
            return reval;
        }
        irc = fread(phonearr,sizeof(phoneaddress),number,filesplit);
        irc = fwrite(phonearr, sizeof(phoneaddress),number,file1);
        free(phonearr);
        fclose(filesplit);
        fclose(file1);
        return reval;
    }

    if ((file1 = fopen(argv[3],"w+b")) == NULL)
    {
        printf("Cannot open file 1");
        reval = FAIL;
        return FAIL;
    }
    if ((file2 = fopen(argv[4],"w+b")) == NULL)
    {
        printf("Cannot open file 2");
        reval = FAIL;
        return FAIL;
    }
    if (fseek(filesplit,0,SEEK_SET) != 0)
    {
        printf("Fseek failed!\n");
        reval = FAIL;
        return reval;
    }
    fseek(filesplit, 0 ,SEEK_SET);
    irc = fread(phonearr,sizeof(phoneaddress),numbercontact1,filesplit);
    irc = fwrite(phonearr,sizeof(phoneaddress),numbercontact1,file1);
    fseek(filesplit, (numbercontact1)*sizeof(phoneaddress),SEEK_SET);
    irc = fread(phonearr,sizeof(phoneaddress),(number -numbercontact1),filesplit);
    irc = fwrite(phonearr, sizeof(phoneaddress),(number - numbercontact1),file2);
    free(phonearr);
    fclose(filesplit);
    fclose(file1);
    fclose(file2);
    return reval;
}
    
    