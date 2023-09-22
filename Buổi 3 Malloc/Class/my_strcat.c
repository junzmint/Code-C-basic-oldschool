#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char *s1, *s2, *s3;
    printf("Nhap day s1: ");
    gets(s1);
    fflush(stdin);
    printf("Nhap day s2: ");
    gets(s2);
    fflush(stdin);
    s3 = (char *)malloc((strlen(s1)+strlen(s2)+1)*sizeof(char));
    if(s3 == NULL){
        printf("Memory allocation failed");
        return 1;
    }
    strcpy(s3,s1);
    strcpy(s3+strlen(s1),s2);
    puts(s3);
    free(s3);
    return 0;
}