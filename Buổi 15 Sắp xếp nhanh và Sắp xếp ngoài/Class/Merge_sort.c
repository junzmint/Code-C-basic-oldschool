#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000
#define threshold 200

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

void Merge(int u[], int v[], int e[], int u_right, int v_right){
    int i = 0;
    int j = 0;
    int k = 0;
    while (k <= u_right + v_right + 1)
    {
        if(u[i] < v[j]){
            e[k] = u[i];
            i++;
        }
        else{
            e[k] = v[j];
            j++;
        }
        k++;
    }
    
}

void Merge_Sort(int list[],int left, int right){
    if(right < threshold){
        Quick_sort(list, left, right);
    }
    else{
        int first = (right - left + 1)/2;
        int last = (right - left + 1) - first;
        int u[first];
        int v[last];
        int mid = right/2;
        for(int i = 0, j = 0; i <= mid; i++, j++){
            u[j] = list[i];
        }
        for(int i = mid + 1,j = 0; i <= right; i++, j ++){
            v[j] = list[i];
        }
        Merge_Sort(u,0,mid);
        Merge_Sort(v,0,right - mid - 1);
        Merge(u,v,list,mid,right - mid - 1);
    }
}

int main(){
    int list[MAX];
    for(int i = 0; i< MAX; i++){
        list[i] = rand();
    }
    Merge_Sort(list,0,MAX-1);
    printf("Sorted array: ");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ",list[i]);
    }
    printf("\n");
}