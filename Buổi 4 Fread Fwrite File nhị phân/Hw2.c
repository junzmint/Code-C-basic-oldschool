#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000
typedef struct input
{
    int ID;
    double MSSV;
    char name[SIZE];
    double phoneNumber;
    float score;
} list;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error syntax!\n");
        printf("Correct syntax: ./program_name <file_name_1> <file_name_2>\n");
        printf("File_name_1 use to read\n");
        printf("File_name_2 use to print result\n");
        return 0;
    }
    
    FILE *fptr1;
    FILE *fptr2;
    if ((fptr1 = fopen(("%s", argv[1]), "r")) == NULL)
    {
        printf("Error file %s!\n", argv[1]);
        printf("Make sure that the file exists or in the same place of the program!\n");
        fclose(fptr1);
        return 0;
    }
    else if ((fptr2 = fopen(("%s", argv[2]), "w")) == NULL)
    {
        printf("Error file %s!\n", argv[2]);
        printf("Make sure that the file exists or in the same place of the program!\n");
        fclose(fptr1);
        fclose(fptr2);
        return 0;
    }

    int trace = 0;
    int soluong, choose, nhapthem;
    list *bangdiem;
    printf("Nhap so luong sinh vien trong file: ");
    scanf("%d",&soluong);
    bangdiem = (list*)malloc(soluong*sizeof(list));
    while (feof(fptr1) == 0)
    {
        fscanf(fptr1, "%d\t%lf\t%s\t\t%lf", &bangdiem[trace].ID, &bangdiem[trace].MSSV, bangdiem[trace].name, &bangdiem[trace].phoneNumber);
        printf("Enter score for student %d: ", trace + 1);
        scanf("%f", &bangdiem[trace].score);
        while (bangdiem[trace].score>10)
        {
            printf("Invalid\n");
            printf("Enter score for student %d: ", trace + 1);
            scanf("%f", &bangdiem[trace].score);
        }
        fprintf(fptr2, "%-d\t%.0lf\t%s\t\t%.0lf\t%.2f\n", bangdiem[trace].ID, bangdiem[trace].MSSV, bangdiem[trace].name, bangdiem[trace].phoneNumber, bangdiem[trace].score);
        printf("%-d\t%.0lf\t%s\t\t%.0lf\t%.2f\n", bangdiem[trace].ID, bangdiem[trace].MSSV, bangdiem[trace].name, bangdiem[trace].phoneNumber, bangdiem[trace].score);                
        trace++;
    }
    trace = 0;
    printf("DONE!\n");
    printf("Do you want to type more student information (press 0 to continue, press 1 to exit): ");
    scanf("%d",&choose);
    while (choose == 0)
    {   
        int i = 0;
        printf("How many students you want to type more: ");
        scanf("%d",&nhapthem);
        bangdiem = realloc(bangdiem,nhapthem*sizeof(list));
        while (i < nhapthem)
        {   
            printf("The valid syntax is ");
            printf("<ID>    <MSSV>  <NAME>      <PhoneNumber>\n");
            scanf("%d\t%lf\t%s\t\t%lf", &bangdiem[trace].ID, &bangdiem[trace].MSSV, bangdiem[trace].name, &bangdiem[trace].phoneNumber);
            printf("Enter score for student %d: ", bangdiem[trace].ID);
            scanf("%f", &bangdiem[trace].score);
            while (bangdiem[trace].score>10)
            {   
                printf("Invalid\n");
                printf("Enter score for student %d: ", trace + 1);
                scanf("%f", &bangdiem[trace].score);
            }
            fprintf(fptr2, "%-d\t%.0lf\t%s\t\t%.0lf\t%.2f\n", bangdiem[trace].ID, bangdiem[trace].MSSV, bangdiem[trace].name, bangdiem[trace].phoneNumber, bangdiem[trace].score);
            printf("%-d\t%.0lf\t%s\t\t%.0lf\t%.2f\n", bangdiem[trace].ID, bangdiem[trace].MSSV, bangdiem[trace].name, bangdiem[trace].phoneNumber, bangdiem[trace].score);               
            trace++;
            i++;
        }
        i = 0;
        trace = 0;
        printf("DONE!\n");
        printf("Do you want to type more student information(press 0 to continue, press 1 to exit): ");
        scanf("%d",&choose);
    }
    if(choose == 1){
        printf("Goodbye");
        fclose(fptr1);
        fclose(fptr2);
        free(bangdiem);
        exit(0);
        return 0;
    }
}
