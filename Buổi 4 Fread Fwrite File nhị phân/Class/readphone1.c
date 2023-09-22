#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum {SUCCESS, FAIL, MAX_ELEMENT = 20};

// the phone book structure
typedef struct phoneaddress {
      char name[20];
      char tel[11];
      char email[25];
}phoneaddress;

int main(void){
    FILE *fp;
    phoneaddress *phonearr;
    
    int i, irc,begin,end;
    int reval = SUCCESS;
    printf("begin = "); scanf("%d",&begin);
    printf("end = "); scanf("%d",&end);
    printf("Read from %d data to %d data \n",begin,end);
    if ((fp = fopen("phonebook.dat","r+b")) == NULL){
		printf("Can not open %s.\n", "phonebook.dat");
		reval = FAIL;
	} 
    phonearr =(phoneaddress *)malloc((end-begin+1) * sizeof(phoneaddress));
    if (phonearr == NULL){
        printf("Memory allocation failed!\n");
        return FAIL;
    }

    if (fseek(fp,(begin-1)*sizeof(phoneaddress),SEEK_SET) != 0)
    {
        printf("Fseek failed!\n");
        return FAIL;
    }
    irc = fread(phonearr, sizeof(phoneaddress), (end-begin+1), fp);
    for (i=0; i<(end-begin+1); i++){
        printf("%s-",phonearr[i].name);
        printf("%s-",phonearr[i].tel);
        printf("%s\n",phonearr[i].email);
    }
/*
    strcpy(phonearr[1].name,"___");
    strcpy(phonearr[1].tel,"___");
    strcpy(phonearr[1].email,"-------------");
*/
    fseek(fp,(begin-1)*sizeof(phoneaddress),SEEK_SET);
    irc = fwrite(phonearr, sizeof(phoneaddress), (end-begin+1) , fp);
    printf("___fwrite return code = %d\n", irc);
    fclose(fp); free(phonearr);

    return reval;
}