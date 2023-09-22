#include<stdio.h>
#include<stdlib.h>
#include"mang_bam_int.h"

int main(){
    Initialize();
    int choose;
    int number_el;
    int search_el;
    int delete_el;
    int bucket_traverse;
    int insert_el;
    while(1 == 1){
        printf("\n------------------Menu------------------\n");
        printf("1.Creata a hash table\n2.Print the table\n3.Searching\n4.Delete\n5.Traverse a Bucket\n6.Insert an element\n7.Exit\n");
        printf("Your option: ");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            printf("How many elements you want to create : ");
            scanf("%d",&number_el);
            for(int i = 0; i<number_el; i++){
                InsertSet(rand());
            }
            printf("Your hash table is ready\n");
            break;
        case 2:
            printf("hash Table:\n");
            TraverseTable();
            break;
        case 3:
            printf("What is the element you want to search : ");
            scanf("%d",&search_el);
            if(Search(search_el) == 0){
                printf("The table doesn't have that element\n");
            }
            else{
                printf("Your element is searched\n");
                printf("Your element is in %d bucket\n", search_el % B);
            }
            break;
        case 4:
            printf("What is the element you want to delete : ");
            scanf("%d",&delete_el);
            Delete(delete_el);
            printf("The element is deleted\n");
            break;
        case 5:
            printf("Which bucket do you want to traverse : ");
            scanf("%d",&bucket_traverse);
            printf("Bucket %d",bucket_traverse);
            TraverseBucket(bucket_traverse);
            break;
        case 6:
            printf("What is the element you want to insert : ");
            scanf("%d",&insert_el);
            printf("The element is inserted in the bucket %d", insert_el % 10);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Wrong syntax\n");
            break;
        }
    }
}