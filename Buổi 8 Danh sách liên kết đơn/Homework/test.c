#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "PhoneDB.h"

int main(){
    FILE *fptx, *fp;
    if ((fptx = fopen("PhoneDB.txt", "r+")) == NULL){
        printf("Cannot open file.\n");
        return 0;
    }
    elementtype *phonebase;
    int i = 0;
    phonebase = (elementtype*)malloc(20*sizeof(elementtype));
    while(feof(fptx)==0){
        fscanf(fptx,"%s\t%d\t%s\t%f\t%d",phonebase[i].model,&phonebase[i].space,phonebase[i].screen,&phonebase[i].size,&phonebase[i].price);
        InsertHead(phonebase[i]);
        i++;
    }
    TravelList();
    PrintFileDat(fp);
    return 0;
}