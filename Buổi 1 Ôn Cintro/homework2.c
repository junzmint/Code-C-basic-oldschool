#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

typedef struct Phrase
{
    char word[20];
}Pharses;

int GetRandom(int min,int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}


int main(){
    Pharses article[MAX],noun[MAX],verb[MAX],prep[MAX];
    int a,b,c,d;
    printf("How many Article phrases do you want (Must be more than 2): ");
    scanf("%d",&a);
    while (a < 2)
    {
        printf("So nhap vao khong dung yeu cau, xin nhap lai: ");
        scanf("%d",&a);
    }
    printf("How many Noun phrases do you want (Must be more than 2): ");
    scanf("%d",&b);
    while (b < 2)
    {
        printf("So nhap vao khong dung yeu cau, xin nhap lai: ");
        scanf("%d",&b);
    }
    printf("How many Verb phrases do you want (Must be more than 2): ");
    scanf("%d",&c);
    while (c < 2)
    {
        printf("So nhap vao khong dung yeu cau, xin nhap lai: ");
        scanf("%d",&c);
    }
    printf("How many Preposition phrases do you want (Must be more than 2): ");
    scanf("%d",&d);
    while (d < 2)
    {
        printf("So nhap vao khong dung yeu cau, xin nhap lai: ");
        scanf("%d",&d);
    }
    getchar();
    for(int i = 0; i< a; i++){
        printf("Nhap chu thu %d cua mang article : ",i+1);
        gets(article[i].word);
        fflush(stdin);
    }
    for(int i = 0; i< b; i++){
        printf("Nhap chu thu %d cua mang noun : ",i+1);
        gets(noun[i].word);
        fflush(stdin);
    }
    for(int i = 0; i< c; i++){
        printf("Nhap chu thu %d cua mang verb : ",i+1);
        gets(verb[i].word);
        fflush(stdin);
    }
    for(int i = 0; i< d; i++){
        printf("Nhap chu thu %d cua mang preposition : ",i+1);
        gets(prep[i].word);
        fflush(stdin);
    }
    printf("Cac cau ngau nhien duoc tao thanh la :\n");
    for (int i = 0; i < 10; i++)
    {   
        char title[20];
        int random;
        random = GetRandom(0,a-1);
        for (int j = 0; j < strlen(article[random].word); j++)
        {
            title[j] = article[random].word[j];
        }
        title[strlen(article[random].word)] = '\0';
        for(int k = 0; k < strlen(title);k++){
            if(k == 0){
                title[k] = title[k] -32;
            }
            else{
                title[k] = title[k];
            }
        }
        printf("%s %s %s %s %s %s.\n",title,noun[GetRandom(0,b-1)].word,verb[GetRandom(0,c-1)].word,prep[GetRandom(0,d-1)].word,article[GetRandom(0,a-1)].word,noun[GetRandom(0,b-1)].word);
    }
    getch();
    return 0;
}
