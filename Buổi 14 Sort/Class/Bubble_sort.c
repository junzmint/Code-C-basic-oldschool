#include<stdio.h>

void Bubble_sort(float list[], int n){
    float tmp;
    for(int i = 0; i< n-1; i++){
        for(int j = 0; j < n - i - 1 ; j++){
            if(list[j] > list[j+1]){
                tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            };
        }
    }
}

int main(){
    float list[] = {12.5,34.7,2.6,1.5,6.8,10.4};
    printf("Trang thai dau tien cua mang: ");
    for(int k = 0; k< 6;k++){
        printf("%.2f ",list[k]);
    }
    printf("\n");
    Bubble_sort(list,6);
    return 0;
}