#include "Header.h"
#include "GenSLL.h"
#include "option.h"
#include "menu.h"

int main(int argc, char *argv[])
{
    FILE *fptr;
    if (argc != 2)
    {
        printf("Error syntax!\n");
        printf("Correct syntax: ./program_name <file_name>\n");
        printf("File should be in DAT format\n");
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
            doublelist root = NULL;
            doublelist tail = NULL;
            doublelist cur = NULL;
            menuDAT(fptr, &root, &tail, &cur);
            if (root != NULL)
            {
                freeList(&root);
                free(phoneDB);
            }
            fclose(fptr);
        }
        else
        {
            printf("Error file %s!\n", argv[1]);
            printf("File must be in .dat format!\n");
            return ERROR;
        }
    }
}