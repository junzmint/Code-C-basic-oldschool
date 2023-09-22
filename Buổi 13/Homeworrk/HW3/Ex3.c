#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000
#define length_of_name 100
#define MemSpaceSize 8
#define ScreenMaxSize 5
#define MaxPricedSize 10


#include "Header.h"
#include "BSTforPhoneDB.h"
ElType *phoneDB;

#include "option.h"
#include "menuDAT.h"
#include "menuTXT.h"




int main(int argc, char *argv[])
{
    FILE *fptr;
    
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
            menuDAT(fptr);
            free(phoneDB);
            fclose(fptr);
        }
        else if (checkFileType(argv[1][strlen(argv[1]) - 3]) == TXT)
        {
            if ((fptr = fopen(("%s", argv[1]), "r")) == NULL)
            {
                printf("Error file %s!\n", argv[1]);
                fclose(fptr);
                return ERROR;
            }
            menuTXT(fptr);
            free(phoneDB);
            fclose(fptr);
        }
        else
        {
            printf("Error file %s!\n", argv[1]);
            printf("File must be in .txt or .dat format!\n");
            return ERROR;
        }
    }
}