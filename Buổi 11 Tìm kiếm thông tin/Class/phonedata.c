#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "PhoneDB.h"
enum {SUCCESS, FAIL};

int reval = SUCCESS;

int main(){
    int choose;
    int check1 = 0;
    int i = 0;
    int pricephone;
    int count = 0;
    FILE *fptx, *fpdat;
    elementtype *phonebase;
    node *p;
    char model[20];
    while (1==1)
    {
        printf("Choose the number you want\n");
        printf("1.Import from Text\n2.Import from Dat\n3.Display List\n4.Search phone by model\n5.Search phone of which the price is under the value inputted\n6.Export to Dat\n7.Manual Insertion\n8.Exit");
        printf("\nYour choose: ");
        scanf("%d",&choose);fflush(stdin);
        switch (choose)
        {
        case 1:
            if(check1 == 1 || check1 == 2){
                printf("You have imported this file before");
            }
            else{
                if ((fptx = fopen("PhoneDB.txt", "r+")) == NULL){
                    printf("Cannot open file.\n");
                    reval = FAIL;
                }
                else{
                    phonebase = (elementtype*)malloc(20*sizeof(elementtype));
                    while(feof(fptx)==0){
                        fscanf(fptx,"%s\t%d\t%s\t%f\t%d",phonebase[i].model,&phonebase[i].space,phonebase[i].screen,&phonebase[i].size,&phonebase[i].price);
                        InsertHead(phonebase[i]);
                        i++;
                    }
                    check1 = 1;
                    free(phonebase);
                    fclose(fptx);
                }
            }
            break;
        case 2:
            if(check1 != 2){
                printf("Press 1 and then 6 first");
            }
            else{
                if ((fpdat = fopen("PhoneDB.dat", "rb+")) == NULL){
                    printf("Cannot open file.\n");
                    reval = FAIL;
                }
                phonebase = (elementtype*)malloc(20*sizeof(elementtype));
                int j = 0;
                while(fread(phonebase, sizeof(elementtype), 1, fpdat) != 0){
                    InsertAfterCur(phonebase[j]);
                }
                TravelList();
                fclose(fpdat);
                free(phonebase);
            }
            break;
        case 3:
            if(check1 == 0){
                printf("Press 1 first");
            }
            else{
                printf("Model\tSpace\tScreen\tSize\tPrice\n");
                TravelList();
            }
            break;    
        case 4:
            if(check1 == 0){
                printf("Press 1 first");
            }
            else{
                printf("Search model: ");
                gets(model);
                for(p = root;p != NULL; p = p->next){
                    if(strcmp(p->element.model,model) == 0){
                        printf("Model\tSpace\tScreen\tSize\tPrice\n");
                        printf("%s\t%d\t%s\t%f\t%d\n",p->element.model,p->element.space,p->element.screen,p->element.size,p->element.price);
                        break;
                    }
                }
                printf("Done\n");
            }
            break;
        case 5:
            if(check1 == 0){
                printf("Press 1 first");
            }
            else{
                printf("Type the price: ");
                scanf("%d",&pricephone);
                for(p = root;p != NULL; p = p->next){
                    if(p->element.price <= pricephone){
                        printf("%s\t%d\t%s\t%f\t%d\n",p->element.model,p->element.space,p->element.screen,p->element.size,p->element.price);
                    }
                }
                printf("Done\n");
            }
            break;
        case 6:
            if(check1 == 0){
                printf("Press 1 first");
            }
            else{
                if ((fpdat = fopen("PhoneDB.dat", "wb+")) == NULL){
                    printf("Cannot open file.\n");
                    reval = FAIL;
                }
                for(p = root;p != NULL; p = p->next){
                    count += 1;
                }
                phonebase = (elementtype*)malloc(count*sizeof(elementtype));
                int k = 0;
                for(p = root;p != NULL;p = p->next){
                    strcpy(phonebase[k].model, p->element.model);
                    phonebase[k].space = p->element.space;
                    strcpy(phonebase[k].screen,p->element.screen);
                    phonebase[k].size = p->element.size;
                    phonebase[k].price = p->element.price;
                }
                fwrite(phonebase,sizeof(elementtype),count,fpdat);
                count = 0;
                check1 = 2;
                printf("Done\n");
                free(phonebase);
                free(fpdat);
            }
            break;
        case 7:
            if(check1 == 0){
                printf("Press 1 first");
            }
            else{
                int choice;
                printf("1.Insert at head\n2.Insert before current\n3.Insert after current\n");
                printf("Your option:");
                scanf("%d",&choice);fflush(stdin);
                elementtype new;
                new = readNode();
                if(choice == 1){
                    InsertHead(new);
                }
                if(choice == 2){
                    InsertBeforeCur(new);
                }
                if(choice == 3){
                    InsertAfterCur(new);
                }
                printf("Done\n");
            }
            break;
        case 8:
            FreeList();
            exit(0);
            break;
        default:
            printf("Invalid\n");
            break;
        }
    }
    return reval;    
}