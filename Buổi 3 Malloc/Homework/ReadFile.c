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
    else
    {
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
        else
        {

            int trace = 0;
            list bangdiem[SIZE];
            while (feof(fptr1) == 0)
            {
                fscanf(fptr1, "%d\t%lf\t%s\t%lf", &bangdiem[trace].ID, &bangdiem[trace].MSSV, bangdiem[trace].name, &bangdiem[trace].phoneNumber);
                printf("Enter score for student %d: ", trace + 1);
                scanf("%f", &bangdiem[trace].score);
                fprintf(fptr2, "%-d\t%.0lf\t%s\t%.0lf\t%.2f\n", bangdiem[trace].ID, bangdiem[trace].MSSV, bangdiem[trace].name, bangdiem[trace].phoneNumber, bangdiem[trace].score);
                printf("%-d\t%.0lf\t%s\t%.0lf\t%.2f\n", bangdiem[trace].ID, bangdiem[trace].MSSV, bangdiem[trace].name, bangdiem[trace].phoneNumber, bangdiem[trace].score);
                trace++;
            }
            trace = 0;
            printf("DONE!\n");
            fclose(fptr1);
            fclose(fptr2);
            return 0;
        }
    }
}