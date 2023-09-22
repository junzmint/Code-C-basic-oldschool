#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000
#define MAX_LEN 80
enum{SUCCESS, FAIL};
typedef struct input
{
    int ID;
    double MSSV;
    char name[SIZE];
    double phoneNumber;
    float score;
} list;

int main()
{
    FILE *file1;
    FILE *file2;
    int choose;
    int run = 0;
    int reval = SUCCESS;
    int num;
    char f1[MAX_LEN];
    char f2[MAX_LEN];
    list *bangdiem;
    list *pointtable;
    list *newtable;
    int keep = 0;
    int new;
    int numberofsv;
    
    while (run == 0)
    {   
        printf("Program Menu\n1. Text to Dat\n2. Display Dat file\n3. Search and Update\n4. Quit\n");
        printf("Choose your option: ");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            printf("Nhap ten file de doc: ");
            scanf("%s",f1);
            printf("Nhap file de ghi: ");
            scanf("%s",f2);
            if ((file1 = fopen(("%s", f1), "r")) == NULL)
            {
                printf("Error file %s!\n", f1);
                printf("Make sure that the file exists or in the same place of the program!\n");
                reval = FAIL;
                return reval;
            }
            else if ((file2 = fopen(("%s", f2), "wb")) == NULL)
            {
                printf("Error file %s!\n", f2);
                printf("Make sure that the file exists or in the same place of the program!\n");
                reval = FAIL;
                return reval;
            }
            printf("How many students in the file: ");
            scanf("%d",&num);
            bangdiem = (list*)malloc((num+1)*sizeof(list));
            fseek(file1, SEEK_SET, 0);
            fread(bangdiem, sizeof(list), num, file1);
            fwrite(bangdiem, sizeof(list), num, file2);
            free(bangdiem);
            fclose(file1);
            fclose(file2);
            continue;
        case 2:
            
            printf("Nhap ten file de doc va ghi: ");
            scanf("%s",f2);
            if ((file2 = fopen(("%s", f2), "rb")) == NULL)
            {
                printf("Error file %s!\n", f2);
                printf("Make sure that the file exists or in the same place of the program!\n");
                reval = FAIL;
                return reval;
            }
            pointtable = (list*)malloc((num+1)*sizeof(list));
            fread(pointtable,sizeof(list),num,file2);
            printf("ID\tMSSV\t\tNAME\t\tTelephone\n");
            for(int i = 0; i<num;i++){
                printf("%d\t%lf\t\t%s\t\t%lf\t%f\n",bangdiem[i].ID,bangdiem[i].MSSV,bangdiem[i].name,bangdiem[i].phoneNumber,bangdiem[i].score);
            }
            free(pointtable);
            fclose(file2);
            continue;
        case 3:
            
            printf("Nhap ten file de doc va ghi them diem sinh vien: ");
            scanf("%s",f2);
            if ((file2 = fopen(("%s", f2), "w+b")) == NULL)
            {
                printf("Error file %s!\n", f2);
                printf("Make sure that the file exists or in the same place of the program!\n");
                reval = FAIL;
                return reval;
            }
            newtable = (list*)malloc((num+1)*sizeof(list));
            fread(newtable,sizeof(list),num,file2);
            printf("Choose 0 to back, choose 1 to enter the score: ");
            scanf("%d",&new);
            while (keep == 0)
            {
                switch (new)
                {
                case 0:
                    break;
                case 1:
                    printf("Choose the students you want to enter: ");
                    scanf("%d",&numberofsv);
                    if(numberofsv < 1 || numberofsv > num){
                        printf("Invalid");
                        break;
                    }
                    printf("Enter the score of the student %d: ",numberofsv);
                    scanf("%f",bangdiem[numberofsv-1].score);
                    fwrite(newtable,sizeof(list),num,file2);
                    break;
                default:
                    printf("Invalid");
                    break;
                }
            }
            free(newtable);
            fclose(file2);
            continue;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid");
            scanf("%d",choose);
            continue;
        }
    }
    
    return 0;
}
