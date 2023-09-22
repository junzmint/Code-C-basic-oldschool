#include<stdio.h>
int count(int n){
    static int dem =0;
    if(n!=0 ){
    
        dem++;
        count(n/10);
    }
    return dem;
}
int main (){
    int k ,n;
    printf("enter n=");scanf("%d",&n);
    printf("%d co %d chu so",n,count(n));
}