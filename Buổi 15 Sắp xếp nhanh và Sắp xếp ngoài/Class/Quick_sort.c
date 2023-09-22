#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000000


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void Quick_sort(int list[], int left, int right){
    int i,j;
    int pivot, temp;
    if(left < right){
        i = left;
        j = right + 1;
        pivot = list[left];
        do{
            do i++; while(list[i] < pivot);
            do j--; while(list[j] > pivot);
            if(i < j) swap(&list[i],&list[j]);
        }while(i < j);
        swap(&list[left],&list[j]);
        Quick_sort(list,left,j-1);
        Quick_sort(list,j+1,right);
    }
}

int main(){
    float clock1, clock2;
    int list1[MAX];
    for(int i = 0; i< MAX; i++){
        list1[i] = rand();
    }
    clock1 = clock();
    Quick_sort(list1, 0, MAX-1);
    clock2 = clock();
    /*
    printf("Sorted array: ");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ",list1[i]);
    }
    printf("\n");
    */
    printf("Quick Sort runtime: %.2fs\n",(clock2-clock1)/CLOCKS_PER_SEC);
    return 0;
}