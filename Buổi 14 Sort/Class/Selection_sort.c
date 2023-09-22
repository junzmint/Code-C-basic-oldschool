#include<stdio.h>

void Selection_sort(float list[], int n){
    int i, j, min;
    float tmp;
    for(i = 0; i< n-1;i++){
        min = i;
        for(j = i + 1; j <= n-1; j++){
            if(list[j] < list[min]) min = j;
        }
        tmp = list[i];
        list[i] = list[min];
        list[min] = tmp;
        printf("Trang thai %d: ",i+1);
        for(int k = 0; k < n ;k++){
            printf("%.2f ",list[k]);
        }
        printf("\n");
    }
}

int main(){
    float list[] = {12.5,34.7,2.6,1.5,6.8,10.4};
    printf("Trang thai dau tien cua mang: ");
    for(int k = 0; k< 6;k++){
        printf("%.2f ",list[k]);
    }
    printf("\n");
    Selection_sort(list,6);
    return 0;
}