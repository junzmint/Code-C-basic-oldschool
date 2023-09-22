#include<stdio.h>
#include<string.h>
#define MAX 1000

int check(char *s, int len){
    int n = len;
    if(n == 0){
        return 0;
    }
    else
    {
        if(s[strlen(s) - n] >= 65 && s[strlen(s) - len] <= 90){
            return s[strlen(s) - n];
        }
        else{
            check(s,len - 1);
        }
    }
    if(len == 0){
        return 0;
    }
}

int main(){
    char c[MAX];
    printf("Type the string to check: ");
    gets(c);
    if(check(c,strlen(c)) == 0){
        printf("This string doesn't have any capital characters.");
    }
    else{
        printf("The first capital letter is : %c",check(c,strlen(c)));
    }
    return 0;
}