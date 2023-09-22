#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "BSTforStudent.h"

int main(int argc, char *argv[])
{
    FILE *fptr3;
    if (argc != 2)
    {
        printf("Error syntax!\n");
        printf("Correct syntax: ./program_name <file_name_1>\n");
        printf("File_name_1 use to read\n");
        return 0;
    }
    else if ((fptr3 = fopen(("%s", argv[1]), "r")) == NULL)
    {
        printf("Error file %s!\n", argv[1]);
        printf("Make sure that the file exists or in the same place of the program!\n");
        fclose(fptr3);
        return 0;
    }
    else
    {
        int tracking = 0;
        treeType root = NULL;
        phoneaddress *phonebook;
        phonebook = (phoneaddress *)malloc(sizeof(*fptr3) * sizeof(phoneaddress));
        if (phonebook == NULL)
        {
            printf("Memory allocation failed!\n");
            return 0;
        }
        char ch;
        int point = 0;
        int namePoint = 0;
        char tmp[length_of_name];
        while (fgets(tmp, length_of_name, fptr3) != NULL)
        {
            ch = tmp[0];
            while (ch != ' ')
            {
                phonebook[tracking].name.last[namePoint] = ch;

                point++;
                namePoint++;
                ch = tmp[point];
            }
            phonebook[tracking].name.last[namePoint] = '\0';
            namePoint = 0;
            point++;
            ch = tmp[point];
            while (ch != ' ')
            {
                phonebook[tracking].name.middle[namePoint] = ch;

                namePoint++;
                point++;
                ch = tmp[point];
            }
            phonebook[tracking].name.middle[namePoint] = '\0';
            namePoint = 0;
            point++;
            ch = tmp[point];
            while (ch != '\n')
            {
                phonebook[tracking].name.first[namePoint] = ch;

                namePoint++;
                point++;
                ch = tmp[point];
            }
            phonebook[tracking].name.first[namePoint] = '\0';
            namePoint = 0;
            point = 0;
            tracking++;
        }
        srand(time(0));
        for (int i = 0; i < tracking; i++)
        {
            phonebook[i].score = rand() % 11;
        }
        
        printf("List before sort:\n");
        for (int i = 0; i < tracking; i++)
        {
            printf("%s %s %s: %.2f\n", phonebook[i].name.last, phonebook[i].name.middle, phonebook[i].name.first, phonebook[i].score);
        }
        printf("\n\n");
        for (int i = 0; i < tracking; i++)
        {
            insertNode(phonebook[i], &root);
        }
        printf("List after sort:\n");
        inorderPrint(root);
        printf("\n\n");
        float countScore = 0.0;
        printf("Enter score for counting: ");
        scanf("%f", &countScore);
        ElType tmpCount;
        tmpCount.score = countScore;
        printf("\n\n");
        int choiceCount = 0;
        int result = 0;
        printf("Enter option count:\n");
        printf("1. Count higher\n");
        printf("2. Count lower\n");
        printf("Enter option: ");
        scanf("%d", &choiceCount);
        if (choiceCount == 1)
        {
            result = higherThanKey(tmpCount, root);
            printf("There are %d higher than key\n", result);
        }
        if (choiceCount == 2)
        {
            result = lowerThanKey(tmpCount, root);
            printf("There are %d lower than key\n", result);
        }
        fllush(stdin);
        char name[20];
        gets(name);
        
        free(phonebook);
        fclose(fptr3);
        tracking = 0;
    }
}