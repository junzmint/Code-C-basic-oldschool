#include<stdio.h>
#define MAX 1000

int search(int key, int r[], int n){
    int i,j;
    int tempr;
    for(i = 0; i <= n - 1 && r[i] != key; i++);
    if(key == r[i]){
        if(i > 0){
            tempr = r[i];
            for(j = i; j > 0; j--) r[j] = r[j-1];
            r[0] = tempr;
        return i;
        }
        else{
            return -1;
        }
    }
}

int main(){
    int r[MAX] ={145,234,635,2324,546,123,647,2456,7457,4234,1243252,323,4,5436};
    int i = 0;
    int n = 0;
    while(r[i] != '\0'){
        n++;
        i++;
    }
    int key;
    printf("Key: ");
    scanf("%d",&key);
    int k = search(key,r,n);
    if(k == -1){
        printf("The element is in the index 0\n");
    }
    else{
        printf("The element is in the index %d, and is moved to front\n",k);
        printf("New array: ");
        for(int j = 0; j< n;j++){
            printf("%d ",r[j]);
        }
    }
    return 0;
}