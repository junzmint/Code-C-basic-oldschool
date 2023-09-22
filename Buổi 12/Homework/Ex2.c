#include <stdio.h>
#include <time.h>

#define arrSize 200000

int array[arrSize];

void makeArray()
{

    for (int i = 0; i < arrSize; i++)
    {
        array[i] = 2 * i + 3;
    }
}

int Sequential(int key)
{

    for (int i = 0; i < arrSize; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int Sequentialft_Sentinel(int key)
{

    int last = array[arrSize - 1];
    array[arrSize - 1] = key;
    int i = 0;
    while (array[i] != key)
    {
        i++;
    }
    array[arrSize - 1] = last;
    if (i < arrSize - 1 || array[i] == key)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int BinarySearch(int key, int left, int right)
{

    if (right >= left)
    {
        int middle = left + (right - left) / 2;
        if (array[middle] == key)
        {
            return middle;
        }
        if (array[middle] < key)
        {
            return BinarySearch(key, middle + 1, right);
        }
        if (array[middle] > key)
        {
            return BinarySearch(key, left, middle - 1);
        }
    }
    return -1;
}

void menu()
{
    int key = 0;
    int choice = 0;
    do
    {
        printf("=======================WELCOME TO MAIN MENU====================\n");
        printf("1. Sequential search\n");
        printf("2. Sequential search using Sentinel\n");
        printf("3. Binary search\n");
        printf("4. Exit\n");
        printf("===============================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter key: ");
            scanf("%d", &key);
            clock_t start1, end1;
            double cpu_time_used1;
            int result1 = 0;
            start1 = clock();
            result1 = Sequential(key);
            end1 = clock();
            cpu_time_used1 = ((double)(end1 - start1) * 1000.0) / CLOCKS_PER_SEC;
            printf("Execution time for Sequential is: %lf second\n", cpu_time_used1);
            if (result1 == -1)
            {

                printf("Result not found!\n");
            }
            else
            {

                printf("The index of key in array is: %d\n", result1);
            }
        }
        if (choice == 2)
        {
            printf("Enter key: ");
            scanf("%d", &key);
            int result2 = 0;
            clock_t start2, end2;
            double cpu_time_used2;
            start2 = clock();
            result2 = Sequentialft_Sentinel(key);
            end2 = clock();
            cpu_time_used2 = ((double)(end2 - start2) * 1000.0) / CLOCKS_PER_SEC;
            printf("Execution time for Sequential using sentinel is: %lf milisecond\n", cpu_time_used2);
            if (result2 == -1)
            {
                printf("Result not found!\n");
            }
            else
            {
                printf("The index of key in array is: %d\n", result2);
            }
        }
        if (choice == 3)
        {
            printf("Enter key: ");
            scanf("%d", &key);
            int result3 = 0;
            clock_t start3, end3;
            double cpu_time_used3;
            start3 = clock();
            result3 = BinarySearch(key, 0, arrSize);
            end3 = clock();
            cpu_time_used3 = ((double)(end3 - start3) * 1000.0) / CLOCKS_PER_SEC;
            printf("Execution time for Binary search is: %lf milisecond\n", cpu_time_used3);
            if (result3 == -1)
            {

                printf("Result not found!\n");
            }
            else
            {

                printf("The index of key in array is: %d\n", result3);
            }
        }
    } while (choice != 4);
}

void main()
{
    makeArray();
    menu();
}