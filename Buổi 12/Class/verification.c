#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct verification
{
    int key;
}element;

void sort(element list[],int n){
    int temp;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(list[i].key > list[j].key){
                temp = list[i].key;
                list[i].key = list[j].key;
                list[j].key = temp;        
            }
        }
    }
}

void verify2(element list1[],element list2[],int n, int m){
    int i,j;
    sort(list1,n);
    sort(list2,m);
    i = j = 0;
    while (i<n && j<m)
    {
        if(list1[i].key < list2[j].key){
            printf("%d is not in list 2\n",list1[i].key);
        }
        else if(list2[i].key == list2[j].key){
            printf("%d is in list1 and list2 \n",list1[i].key);
            i++; j++;
        }
        else{
            printf("%d is not in list 1\n",list2[j].key);
        }
        for(;i<n;i++){
            printf("%d is not in list 2\n",list1[i].key);
        }
        for (; j < m; j++){
            printf("%d is not in list 1\n",list2[j].key);
        }
    }
}

int main(){
    element list1[MAX];
    element list2[MAX];
    printf("Each array will be generated 10000 random numbers \n");
    for(int i = 0; i<MAX; i++){
        list1[i].key = rand();
    }
    for(int i = 0; i<MAX; i++){
        list2[i].key = rand();
    }
    printf("List 1: ");
    for(int i = 0; i<MAX; i++){
        printf("%d ",list1[i].key);
    }
    printf("\nList 2: ");
    for(int i = 0; i<MAX; i++){
        printf("%d ",list2[i].key);
    }
    printf("\n");
    verify2(list1,list2,MAX,MAX);
    return 0;
}
