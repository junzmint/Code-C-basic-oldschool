#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000
enum {SUCCESS, FAIL};

char *subStr(char *s1, int offset, int number) {
    char *SubStr;
    int i;
    SubStr = (char *)malloc(number * sizeof(char));
    for(i = 0; i < number; i++) {
        SubStr[i] = s1[i+offset];
    }
    SubStr[number] = '\0';
    return SubStr;
}

int main(){
    char *s1,*sub;
    int reval = SUCCESS;
    int offset;
    int number;
    s1 = (char *)malloc(MAX * sizeof(char));
    if (s1 == NULL)
    {
        printf("Memory allocation failed!\n");
        return FAIL;
    }
    printf("Type the string: ");
    gets(s1);
    fflush(stdin);
    printf("Choose the start index(start from 0): ");
    scanf("%d",&offset);
    printf("Choose the number of charater you want to print: ");
    scanf("%d",&number);
    if(offset < 0 || number < 1) {
        printf("Invalid arguments\n");
        return FAIL;
    }
    while((strlen(s1)-offset)<number){
        printf("Invalid\n");
        printf("Choose the start index(start from 0): ");
        scanf("%d",&offset);
        printf("Choose the number of charater you want to print: ");
        scanf("%d",&number);
    }
    sub = (char *)malloc(number * sizeof(char));
    sub = subStr(s1, offset, number);
    printf("%s",sub);
    free(sub);
    free(s1);
    return 0;
}
