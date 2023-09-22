#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
        /*
        printf("Trang thai %d: ",i);
        for(int k = 0; k < n ;k++){
            printf("%.2f ",list[k]);
        }
        printf("\n");
        */
    }
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
        printf("\n");
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
  
void heapSort(int arr[], int n) {
    int step = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
        adjust(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        adjust(arr, i, 0);
        /*
        printf("Trang thai %d: ", step + 1);
        step = step + 1;
        printArray(arr, n);
        */
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
    float clock1, clock2, clock3, clock4;
    int list1[MAX];
    for(int i = 0; i< MAX; i++){
        list1[i] = rand();
    }
    int list2[MAX];
    for(int i = 0; i< MAX; i++){
        list2[i] = rand();
    }
    clock1 = clock();
    Insertion_sort(list1, MAX);
    clock2 = clock();
    printf("Insertion Sort runtime: %.2fs\n",(clock2-clock1)/CLOCKS_PER_SEC);
    clock3 = clock();
    Selection_sort(list2, MAX);
    clock4 = clock();
    printf("Selection Sort runtime: %.2fs\n",(clock4-clock3)/CLOCKS_PER_SEC);
    return 0;
}