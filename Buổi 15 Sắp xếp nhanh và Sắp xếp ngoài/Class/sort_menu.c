#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 2000000

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
    int choose = 0;
    int check = 0;
    int *data;
    float clock1,clock2;
    while(1 == 1){
        printf("-------------- Sort Menu --------------\n");
        printf("1.Create Dataset\n2.Insertion Sort\n3.Selection Sort\n4.Bubble Sort\n5.Heap Sort\n6.Quick sort\n7.Exit\n");
        printf("Your option: ");
        scanf("%d",&choose);
        printf("\n");
        switch (choose)
        {
        case 1:
            data = (int *)malloc(MAX*sizeof(int));
            for(int i = 0; i < MAX; i++){
                data[i] = rand();
            }
            printf("Dataset is ready\n");
            check = 1;
            break;
        case 2:
            if(check == 0){
                printf("You haven't generate the dataset yet\n");
            }
            else{
                clock1 = clock();
                Insertion_sort(data,MAX);
                clock2 = clock();
                printf("Insertion Sort runtime: %.2fs\n",(clock2-clock1)/CLOCKS_PER_SEC);
                free(data);
                printf("The data set is free, you need to generate a new one\n");
                check = 0;
            }
            break;
        case 3:
            if(check == 0){
                printf("You haven't generate the dataset yet\n");
            }
            else{
                clock1 = clock();
                Selection_sort(data,MAX);
                clock2 = clock();
                printf("Selection Sort runtime: %.2fs\n",(clock2-clock1)/CLOCKS_PER_SEC);
                free(data);
                printf("The data set is free, you need to generate a new one\n");
                check = 0;
            }
            break;
        case 4:
            if(check == 0){
                printf("You haven't generate the dataset yet\n");
            }
            else{
                clock1 = clock();
                Bubble_sort(data,MAX);
                clock2 = clock();
                printf("Bubble Sort runtime: %.2fs\n",(clock2-clock1)/CLOCKS_PER_SEC);
                free(data);
                printf("The data set is free, you need to generate a new one\n");
                check = 0;
            }
            break;
        case 5:
            if(check == 0){
                printf("You haven't generate the dataset yet\n");
            }
            else{
                clock1 = clock();
                Heap_Sort(data,MAX);
                clock2 = clock();
                printf("Heap Sort runtime: %.2fs\n",(clock2-clock1)/CLOCKS_PER_SEC);
                free(data);
                printf("The data set is free, you need to generate a new one\n");
                check = 0;
            }
            break;
        case 6:
            if(check == 0){
                printf("You haven't generate the dataset yet\n");
            }
            else{
                clock1 = clock();
                Quick_sort(data,0,MAX-1);
                clock2 = clock();
                printf("Quick Sort runtime: %.2fs\n",(clock2-clock1)/CLOCKS_PER_SEC);
                free(data);
                printf("The data set is free, you need to generate a new one\n");
                check = 0;
            }
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Wrong argument\n");
            break;
        }
    }
}