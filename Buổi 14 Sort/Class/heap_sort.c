#include <stdio.h>

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
        printf("Trang thai %d: ", step + 1);
        step = step + 1;
        printArray(arr, n);
    }
}


  
int main() {
    int arr[] = {54,65,325,654,325,3,564,52,564,75,6454,43};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Trang thai ban dau: ");
    printArray(arr, n);
    printf("\n");
    heapSort(arr, n);
    printf("Mang da sap xep: \n");
    printArray(arr, n);
}
