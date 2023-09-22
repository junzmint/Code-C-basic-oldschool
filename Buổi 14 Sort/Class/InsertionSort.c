//Do phuc tap O(n) - O(n^2)
//Giong kieu sap xep khi choi bai
#include<stdio.h>
void Insertion_sort(float list[], int n/*do lon cua mang*/){
    int i, j;
    float next;
    for(i = 1; i<n;i++){
        next = list[i];
        for(j = i - 1; j>=0 && next < list[j]; j --){
            list[j+1] = list[j];
        }
        list[j+1] = next; 
        printf("Trang thai %d: ",i);
        for(int k = 0; k < n ;k++){
            printf("%.2f ",list[k]);
        }
        printf("\n");
    }
}

int main(){
    float list[] = {12.5,34.7,2.6,1.5,6.8,10.4};
    for(int k = 0; k< 6;k++){
        printf("%.2f ",list[k]);
    }
    printf("\n");
    Insertion_sort(list,6);
    return 0;
}