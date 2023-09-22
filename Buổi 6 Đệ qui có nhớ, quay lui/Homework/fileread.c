#include<stdio.h>
#include<stdlib.h>
#include <string.h>
enum {SUCCESS, FAIL};

typedef struct vnedict
{
    char vne[30];
    char eng[50];
}dict;

int main(){
    FILE *file;
    int reval = SUCCESS;
    if((file = fopen("vnedict2.dat","r+b")) == NULL){
        printf("Cannot open file.\n");
        reval = FAIL;
        return reval;
    }
    dict *phonearr;
    int irc;
    phonearr =(dict *)malloc(54373 * sizeof(dict));
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
    irc = fread(phonearr, sizeof(dict), 54373, file);
    for(int i = 0; i <54373; i++){
        printf("%s : %s\n",phonearr[i].vne,phonearr[i].eng);
    }
    free(phonearr);
    fclose(file);
    return 0;
}
