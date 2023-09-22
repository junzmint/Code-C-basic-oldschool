#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000
#define length_of_name 100
#define MemSpaceSize 8
#define ScreenMaxSize 5
#define MaxPricedSize 10

enum
{
    SUCCESS = 0,
    ERROR = 1,
    TXT = 2,
    DAT = 3
};

typedef struct input
{
    char name[length_of_name];
    char mem_space[MemSpaceSize];
    char screen_size[ScreenMaxSize];
    char price[MaxPricedSize];
} elementess;

typedef elementess ElType;

int checkFileType(char check)
{
    if (check == 'd')
    {
        return DAT;
    }
    if (check == 't')
    {
        return TXT;
    }
}

void swap(ElType *phoneA, ElType *phoneB)
{
    ElType tmp = *phoneA;
    *phoneA = *phoneB;
    *phoneB = tmp;
}

void adjust(ElType phoneDB[], int File_length, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < File_length && strcmp(phoneDB[left].name, phoneDB[largest].name) > 0)
    {
        largest = left;
    }
    if (right < File_length && strcmp(phoneDB[right].name, phoneDB[largest].name) > 0)
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&phoneDB[i], &phoneDB[largest]);
        adjust(phoneDB, File_length, largest);
    }
}

void heapSort(ElType phoneDB[], int File_length)
{
    int step = 0;
    // build max heap
    for (int i = File_length / 2 - 1; i >= 0; i--)
    {
        adjust(phoneDB, File_length, i);
    }
    for (int i = File_length - 1; i >= 0; i--)
    {
        swap(&phoneDB[0], &phoneDB[i]);
        adjust(phoneDB, i, 0);
    }
    
}

int main(int argc, char *argv[])
{
    FILE *fptr;
    ElType *phoneDB;
    if (argc != 2)
    {
        printf("Error syntax!\n");
        printf("Correct syntax: ./program_name <file_name>\n");
        printf("File should be in TXT or DAT format\n");
        return ERROR;
    }
    else
    {
        if (checkFileType(argv[1][strlen(argv[1]) - 3]) == DAT)
        {
            if ((fptr = fopen(("%s", argv[1]), "rb")) == NULL)
            {
                printf("Error file %s!\n", argv[1]);
                fclose(fptr);
                return ERROR;
            }
        }
        fseek(fptr, 0, SEEK_END);
        int File_length = ftell(fptr) / sizeof(ElType);
        fseek(fptr, 0, SEEK_SET);
        phoneDB = (ElType *)malloc(sizeof(ElType) * File_length);
        if (phoneDB == NULL)
        {
            printf("Allocated memory ERROR!\n");
            return ERROR;
        }
        fread(phoneDB, sizeof(ElType), File_length, fptr);
        fseek(fptr, 0, SEEK_SET);
        printf("\n\n");
        printf("List before using heap sort:\n");
        printf("%-2s%30s\t%17s\t\t%10s\t\t%s\n", "ID", "Phone name", "Memory space", "Screen size (inch)", "Price(Yen)");
        for (int i = 0; i < File_length; i++)
        {
            printf("%-2d%35s%20s\t\t\t%s\t\t\t%s\n", i + 1, phoneDB[i].name, phoneDB[i].mem_space, phoneDB[i].screen_size, phoneDB[i].price);
        }
        printf("\n\n");
        printf("List after using heap sort:\n");
        heapSort(phoneDB, File_length);
        for (int i = 0; i < File_length; i++)
        {
            printf("%-2d%35s%20s\t\t\t%s\t\t\t%s\n", i + 1, phoneDB[i].name, phoneDB[i].mem_space, phoneDB[i].screen_size, phoneDB[i].price);
        }
        free(phoneDB);
        fclose(fptr);
    }
}