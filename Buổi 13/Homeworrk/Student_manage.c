#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#include"BSTgen_Ex2.h"

typedef struct student
{
    char name[40];
}student_t;

int main(){
    int choose;
    int checkpoint = 0;
    FILE *fp;
    char filename[MAX];
    student_t *list;
    int number;
    treeType root;
    while(1 == 1){
        printf("\n------Student manager program------\n");
        printf("1.Import the student list\n2.Display the list\n3.Search students\n4.Exit\n");
        printf("Your choose:");
        scanf("%d",&choose);
        fflush(stdin);
        printf("---------------------------------------\n");
        switch (choose)
        {
        case 1:
            checkpoint = 1;
            printf("Filename: ");
            gets(filename);
            fflush(stdin);
            if((fp = fopen(filename,"r")) == NULL){
                printf("Cannot open file.\n");
                return 1;
            }
            printf("How many students in the file? ");
            scanf("%d",&number);
            list = (student_t *)malloc(number * sizeof(student_t));
            int j = 0;
            while (fgets(list[j].name,MAX,fp) != NULL)
            {
                root = InsertNodeBinarySearch(root, list[j].name);
                //printf("%s\n",list[j].name);
                j++;
            }
            //drawTree(root);
            break;
        case 2:
            if(checkpoint == 0){
                printf("You haven't import the data yet\n");
            }
            else{

            }
            break;
        case 3:
            if(checkpoint == 0){
                printf("You haven't import the data yet\n");
            }
            else{
                
            }
            break;
        case 4: 
            printf("Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Wront syntax, you will back to the Menu screen\n");
            break;
        }
    }
}