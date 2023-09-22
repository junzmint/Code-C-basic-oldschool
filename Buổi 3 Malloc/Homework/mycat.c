#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define page_length 24
int size_file(FILE *fptr1)
{
    long int size = 0;
    fseek(fptr1, 0, SEEK_END);
    size = ftell(fptr1);
    fseek(fptr1, 0, SEEK_SET);
    return size;
}

int main(int argc, char *argv[])
{
    if (argc != 3 && argc != 2)
    {
        printf("Error syntax!\n");
        printf("Correct syntax: ./program_name <file_name> to display all content\n");
        printf("\tOr  ./program_name <filename> <-p> to display content page by page\n");
        return 0;
    }
    else if (argc == 3 && strcmp(argv[2], "-p") != 0)
    {
        printf("Error syntax!\n");
        printf("Correct syntax: ./program_name <file_name> to display all content\n");
        printf("\tOr  ./program_name <filename> <-p> to display content page by page\n");
        return 0;
    }
    FILE *fptr1;
    if ((fptr1 = fopen(("%s", argv[1]), "r")) == NULL)
    {
        printf("Error file %s!\n", argv[1]);
        printf("Make sure that the file exists or in the same place of the program!\n");
        fclose(fptr1);
        return 0;
    }
    if (argc == 2)
    {
        long int size = size_file(fptr1);
        char *str;
        str = (char *)calloc(sizeof(char), size);
        printf("Content in file will be fully displayed!\n");
        while (feof(fptr1) == 0)
        {
            fgets(str, size, fptr1);
            printf("%s", str);
        }
        free(str);
        fclose(fptr1);
    }
    else if (argc == 3 && strcmp(argv[2], "-p") == 0)
    {
        char decision;
        int one_page_size = 0;
        long int size = size_file(fptr1);
        char *str;
        str = (char *)calloc(sizeof(char), size);
        printf("Content in file will be displayed page by page!\n");
        while (feof(fptr1) == 0 && one_page_size < page_length)
        {
            fgets(str, size, fptr1);
            printf("%s", str);
            one_page_size++;
        }
        while (decision != 'x' && decision != 'X')
        {
            one_page_size = 0;
            printf("Enter \"n\" character for the next page\n");
            printf("Enter \"r\" character to reload from start\n");
            printf("Enter \"x\" character to end program\n");
            printf("Your decision: ");
            scanf("%c", &decision);
            getchar();
            if (decision == 'n' || decision == 'N')
            {
                if (feof(fptr1) != 0)
                {
                    printf("This is the last page, cannot go next!\n");
                }
                else
                {
                    while (feof(fptr1) == 0 && one_page_size < page_length)
                    {
                        fgets(str, size, fptr1);
                        printf("%s", str);
                        one_page_size++;
                    }
                    one_page_size = 0;
                }
            }
            else if (decision == 'r' || decision == 'R')
            {
                fseek(fptr1, 0, SEEK_SET);
                while (feof(fptr1) == 0 && one_page_size < page_length)
                {
                    fgets(str, size, fptr1);
                    printf("%s", str);
                    one_page_size++;
                }
                one_page_size = 0;
            }
        }
        free(str);
        fclose(fptr1);
    }
    return 0;
}