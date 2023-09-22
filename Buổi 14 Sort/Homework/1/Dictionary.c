#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000
#define DictionaryLength 54376

enum
{
    SUCCESS = 0,
    ERROR = 1
};

#include "BSTforDic.h"

int sum = 0;

int checkOpenFileReadBIN(FILE *fptr, char *argv[], int number)
{
    if ((fptr = fopen(("%s", argv[number]), "rb")) == NULL)
    {
        printf("Error file %s!\n", argv[number]);
        printf("Make sure that the file exists or in the same place of the program!\n");
        fclose(fptr);
        return ERROR;
    }
}

int checkOpenFileWriteBIN(FILE *fptr, char *argv[], int number)
{
    if ((fptr = fopen(("%s", argv[number]), "w+b")) == NULL)
    {
        printf("Error file %s!\n", argv[number]);
        printf("Make sure that the file exists or in the same place of the program!\n");
        fclose(fptr);
        return ERROR;
    }
}

int toTree(FILE *fptr1, treeType *rootViet, treeType *rootEng)
{

    char check;
    char storage[SIZE];
    strncpy(storage, "\0", SIZE);
    ElType tmp;
    int countWords = 0;
    // tmp = (ElType *) malloc(sizeof(ElType));
    fseek(fptr1, 0, SEEK_SET);
    int i = 0;
    while (fgets(storage, SIZE, fptr1) != NULL)
    {
        strncpy(tmp.Vietnamese, "\0", SIZE);
        strncpy(tmp.English, "\0", SIZE);
        countWords++;
        for (i = 0;; i++)
        {
            if (storage[i] == ':')
            {
                tmp.Vietnamese[i - 1] = '\0';
                strncpy(tmp.Vietnamese, storage, i);
                i += 2;
                break;
            }
        }
        for (int u = 0; i < strlen(storage) - 1; i++)
        {
            tmp.English[u] = storage[i];
            u++;
        }
        i = 0;
        insertNodeViet(tmp, rootViet);
        insertNodeEng(tmp, rootEng);
        strncpy(tmp.Vietnamese, "\0", SIZE);
        strncpy(tmp.English, "\0", SIZE);
        strncpy(storage, "\0", SIZE);
    }
    fseek(fptr1, 0, SEEK_SET);
    return countWords;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error syntax!\n");
        printf("Correct syntax: ./program_name <file_name_1>\n");
        printf("File_name_1 use to read\n");
        return 0;
    }
    else
    {
        FILE *fptr1;
        int countWords = 0;
        system("CHCP 65001");
        if (checkOpenFileReadBIN(fptr1, argv, 1) == ERROR)
            return ERROR;
        fptr1 = fopen(argv[1], "r");
        treeType rootViet;
        treeType rootEng;
        makeNullTree(&rootViet);
        makeNullTree(&rootEng);
        countWords = toTree(fptr1, &rootViet, &rootEng);
        inorderPrint(rootEng);
        int choice = 0;
        do
        {
            printf("=======================WELCOME TO MAIN MENU====================\n");
            printf("1. Searching word\n");
            printf("2. Delete word\n");
            printf("3. Adding word\n");
            printf("4. Save data to file\n");
            printf("5. Print list (inorder print)\n");
            printf("6. Quit\n");
            printf("There are %d words in file\n", countWords);
            printf("===============================================================\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                int searchChoice = 0;
                char searchWord[SIZE];
                strncpy(searchWord, "\0", SIZE);
                printf("Which searching option:\n");
                printf("1. Vietnamese searching\n");
                printf("2. English searching\n");
                printf("Enter your choice: ");
                scanf("%d", &searchChoice);
                printf("Enter word you want to search: ");
                getchar();
                gets(searchWord);
                if (searchChoice == 1)
                {
                    BSTforVietnamese(searchWord, rootViet);
                }
                if (searchChoice == 2)
                {
                    BSTforEnglish(searchWord, rootEng);
                }
                strncpy(searchWord, "\0", SIZE);
            }
            if (choice == 2)
            {
                int deleteChoice = 0;
                char deleteWord[SIZE];
                strncpy(deleteWord, "\0", SIZE);
                printf("Which deleting option:\n");
                printf("1. Vietnamese deleting\n");
                printf("2. English deleting\n");
                printf("Enter your choice: ");
                scanf("%d", &deleteChoice);
                printf("Enter word you want to delete: ");
                getchar();
                gets(deleteWord);
                if (deleteChoice == 1)
                {
                    DeleteNodeViet(deleteWord, &rootViet);
                }
                if (deleteChoice == 2)
                {
                    DeleteNodeEng(deleteWord, &rootEng);
                }
                strncpy(deleteWord, "\0", SIZE);
            }
            if (choice == 3)
            {
                ElType tmp;
                getchar();
                strncpy(tmp.English, "\0", SIZE);
                strncpy(tmp.Vietnamese, "\0", SIZE);
                printf("Enter English word: ");
                gets(tmp.English);
                printf("Enter Vietnamese meaning: ");
                gets(tmp.Vietnamese);
                insertNodeEng(tmp, &rootEng);
                insertNodeViet(tmp, &rootViet);
                strncpy(tmp.English, "\0", SIZE);
                strncpy(tmp.Vietnamese, "\0", SIZE);
            }
            if (choice == 4)
            {
                FILE *file_out;
                char filename[SIZE];
                getchar();
                printf("Enter file name: ");
                gets(filename);
                if ((file_out = fopen(filename, "w")) == NULL)
                {
                    printf("Error opening file to write!\n");
                }
                inorderSave(rootViet, file_out);
                fclose(file_out);
            }
            if (choice == 5)
            {
                inorderPrint(rootViet);
            }
            

        } while (choice != 6);
        free_tree(rootViet);
        free_tree(rootEng);
        fclose(fptr1);
    }
}