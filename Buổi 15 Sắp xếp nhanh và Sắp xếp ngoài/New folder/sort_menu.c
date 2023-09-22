#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200000

void Insertion_sort(int list[], int n/*do lon cua mang*/){
    int i, j;
    int next;
    for(i = 1; i<n;i++){
        next = list[i];
        for(j = i - 1; j>=0 && next < list[j]; j --){
            list[j+1] = list[j];
        }
        list[j+1] = next;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
  
void adjust(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
        largest = left;
  
    if (right < n && arr[right] > arr[largest])
        largest = right;
  
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        adjust(arr, n, largest);
    }
}
  
void Heap_Sort(int arr[], int n) {
    int step = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
        adjust(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        adjust(arr, i, 0);
    }
}

void Selection_sort(int list[], int n){
    int i, j, min;
    int tmp;
    for(i = 0; i< n-1;i++){
        min = i;
        for(j = i + 1; j <= n-1; j++){
            if(list[j] < list[min]) min = j;
        }
        tmp = list[i];
        list[i] = list[min];
        list[min] = tmp;
    }
}

void Bubble_sort(int list[], int n){
    int tmp;
    for(int i = 0; i< n-1; i++){
        for(int j = 0; j < n - i - 1 ; j++){
            if(list[j] > list[j+1]){
                tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
    }
}

void Selection_sort(int list[], int n){
    int i, j, min;
    int tmp;
    for(i = 0; i< n-1;i++){
        min = i;
        for(j = i + 1; j <= n-1; j++){
            if(list[j] < list[min]) min = j;
        }
        tmp = list[i];
        list[i] = list[min];
        list[min] = tmp;
    }
}

int main(){
    int choose = 0;
    int check = 0;
    while(choose != 7){
        printf("-------------- Sort Menu --------------\n")
        printf("")
    }
}