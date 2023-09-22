#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
enum{SUCCESS, FAIL, MAX_ELEMENT = 20};

typedef struct phonenumber_t
{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;

int main(){
    FILE *fp;
    int reval = SUCCESS;
    if ((fp = fopen("phonebook.dat","r+b")) == NULL){
		printf("Can not open %s.\n", "phonebook.dat");
		reval = FAIL;
	} 
    int a, b;
    phoneaddress *ptr;
    printf("The start position is :");
    scanf("%d",&a);
    printf("The end position is: ");
    scanf("%d",&b);
    ptr = (phoneaddress *)calloc(b-a+1,sizeof(phoneaddress));
    fseek(fp,(a-1)*sizeof(phoneaddress),SEEK_SET);
    fread(ptr,sizeof(phoneaddress),b-a+1,fp);
    for(int i =a; i<b;i++){
        printf("%s",ptr[i].name);
    }
    return 0;


}