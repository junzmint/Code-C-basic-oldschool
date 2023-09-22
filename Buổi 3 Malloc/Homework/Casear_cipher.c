#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE_MAX 100000
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error syntax!\n");
        printf("Correct syntax: ./program_name <file_name> <offset number>\n");
        printf("File should be a plain text to encrypt\n");
        printf("Or cipher text to encrypt\n");
        return 0;
    }
    else
    {
        FILE *fptr1;
        if ((fptr1 = fopen(("%s", argv[1]), "r")) == NULL)
        {
            printf("Error file %s!\n", argv[1]);
            printf("Make sure that the file exists or in the same place of the program!\n");
            fclose(fptr1);
            return 0;
        }
        else
        {
            if (*argv[2] < 48 || *argv[2] > 57)
            {
                printf("Offset number must be a....number, duh!\n");
                return 0;
            }
            else
            {
                char decision;
                char ch;
                int offset = *argv[2] - 48;
                while (decision != 'x' && decision != 'X')
                {
                    printf("Press 'e' to encrypt, 'd' to decrypt and 'x' to exit the program: ");
                    scanf("%c", &decision);
                    getchar();
                    if (decision == 'e' || decision == 'E')
                    {
                        while (feof(fptr1) == 0)
                        {
                            ch = fgetc(fptr1);
                            if (isalpha(ch) == 1)
                            {
                                ch -= 65;
                                if (ch + offset > 25)
                                {
                                    ch = ((ch + offset - 26) % 26) + 65;
                                }
                                else if (ch - offset < 0)
                                {
                                    ch = ((ch + offset + 26) % 26) + 65;
                                }
                                else
                                {
                                    ch = ((ch + offset) % 26) + 65;
                                }
                                printf("%c", ch);
                            }
                            else if (isalpha(ch) == 2)
                            {
                                ch -= 97;
                                if (ch + offset > 25)
                                {
                                    ch = ((ch + offset - 26) % 26) + 97;
                                }
                                else if (ch + offset < 0)
                                {
                                    ch = ((ch + offset + 26) % 26) + 97;
                                }
                                else
                                {
                                    ch = ((ch + offset) % 26) + 97;
                                }
                                printf("%c", ch);
                            }
                            else
                            {
                                printf("%c", ch);
                            }
                        }
                        fseek(fptr1, 0, SEEK_SET);
                        printf("\n");
                    }
                    if (decision == 'd' || decision == 'D')
                    {
                        while (feof(fptr1) == 0)
                        {
                            ch = fgetc(fptr1);
                            if (isalpha(ch) == 1)
                            {
                                ch -= 65;
                                if (ch - offset > 25)
                                {
                                    ch = ((ch - offset - 26) % 26) + 65;
                                }
                                else if (ch - offset < 0)
                                {
                                    ch = ((ch - offset + 26) % 26) + 65;
                                }
                                else
                                {
                                    ch = ((ch - offset) % 26) + 65;
                                }
                                printf("%c", ch);
                            }
                            else if (isalpha(ch) == 2)
                            {
                                ch -= 97;
                                if (ch - offset > 25)
                                {
                                    ch = ((ch - offset - 26) % 26) + 97;
                                }
                                else if (ch - offset < 0)
                                {
                                    ch = ((ch - offset + 26) % 26) + 97;
                                }
                                else
                                {
                                    ch = ((ch - offset) % 26) + 97;
                                }
                                printf("%c", ch);
                            }
                            else
                            {
                                printf("%c", ch);
                            }
                        }
                        fseek(fptr1, 0, SEEK_SET);
                        printf("\n");
                    }
                }
            }
        }
    }
}