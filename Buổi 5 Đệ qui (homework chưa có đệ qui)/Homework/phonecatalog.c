#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {SUCCESS, FAIL};

typedef struct phonecatalog
{
    char model[20];
    int space;
    char screen[20];
    float size;
    int price;
}phonedb;
int reval = SUCCESS;

int main(){
    FILE *fp;
    FILE *fpdat;
    phonedb *phonedata;
    int manda = 0;
    int choose;
    int i = 0;
    int number = 20;
    printf("Welcome to the program\n");
    while(1==1)
    {
        printf("Please choose your of option (Caution: Please choose 1 before other to make a dat file)\n");
        printf("1. Import DB from the PhoneDB.txt to creat PhoneDB.dat\n2. Import form PhoneDB.dat\n3. Print all Database\n4. Search phone by Model\n5. Exit the program");
        printf("\nYour option: ");
        scanf("%d",&choose);
        if(choose == 1){
            if((fp = fopen("PhoneDB.txt","r+")) == NULL){
                printf("Cannot open file.\n");
                reval = FAIL;
                return reval;
            }
            if((fpdat = fopen("PhoneDB.dat","wb")) == NULL){
                printf("Cannot open file.\n");
                reval = FAIL;
                return reval;
            }
            int length,irc;
            phonedata = (phonedb*)malloc(20*sizeof(phonedb));
            if (phonedata == NULL){
                printf("Memory allocation failed!\n");
                return FAIL;
            }
            if (fseek(fp,0,SEEK_SET) != 0)
            {
                printf("Fseek failed!\n");
                reval = FAIL;
                return reval;
            }
            while (feof(fp) == 0)
            {
                fscanf(fp,"%s\t\t%d\t%s\t%f\t%d",phonedata[i].model,&phonedata[i].space,phonedata[i].screen,&phonedata[i].size,&phonedata[i].price);
                printf("%s\t\t%d\t%s\t%f\t%d\n",phonedata[i].model,phonedata[i].space,phonedata[i].screen,phonedata[i].size,phonedata[i].price);
                i++;
            }
            irc = fwrite(phonedata,sizeof(phonedb),1,fpdat);
            //printf("%d",irc);
            printf("Done\n");
            free(phonedata);
            fclose(fp);
            fclose(fpdat);
            manda = 1;
        }
        else if(choose == 2){
            if(manda = 0){
                printf("Please choose 1 first.\n");
                continue;
            }
            int luachon;
            printf("Choose 1 to full reading, 2 to partial reading: ");
            scanf("%d",&luachon);
            if((fpdat = fopen("PhoneDB.dat","r+b")) == NULL){
                printf("Cannot open file.\n");
                reval = FAIL;
                return reval;
            }
            if(luachon == 1){
                int irc;
                fseek(fpdat,0,SEEK_SET);
                phonedata = (phonedb*)malloc(i*sizeof(phonedb));
                irc = fread(phonedata,i,sizeof(phonedb),fpdat);
                printf("\n%d",irc);
            }
            if(luachon == 2){
                printf("Read from the beginning\n");
                printf("How many kinds of phone you want to read: ");
                scanf("%d",&number);
                phonedata = (phonedb*)malloc(number*sizeof(phonedb));
                fseek(fpdat, 0 ,SEEK_SET);
                fread(phonedata, number, sizeof(phonedb),fpdat);
                }
            }
        else if(choose == 3){
            if(manda = 0){
                printf("Please choose 1 first.\n");
            }
            for(int j = 0; j<number;j++){
                printf("%s\t\t%d\t%s\t%f\t%d\n",phonedata[j].model,phonedata[j].space,phonedata[j].screen,phonedata[j].size,phonedata[j].price);
            }
            free(phonedata);
        }
        else if(choose == 4){
            if(manda = 0){
                printf("Please choose 1 first.\n");
            }
            if((fpdat = fopen("PhoneDB.dat","r+b")) == NULL){
                printf("Cannot open file.\n");
                reval = FAIL;
                return reval;
            }
            int irc;
            phonedata = (phonedb*)malloc(i*sizeof(phonedb));
            irc = fread(phonedata,i,sizeof(phonedb),fpdat);
            char phone[20];
            printf("The phone you like to search is: ");
            fflush(stdin);
            gets(phone);
            for(int j = 0; j < i;j++ ){
                if(strcmp(phone,phonedata[j].model)==0){
                    printf("%s\t\t%d\t%s\t%f\t%d\n",phonedata[j].model,phonedata[j].space,phonedata[j].screen,phonedata[j].size,phonedata[j].price);
                }
            }
            free(phonedata);
        }
        else if(choose == 5){
            exit(0);
        }
        else{
            printf("Invalid\n");
        }
    }
}
