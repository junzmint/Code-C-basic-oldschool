#include <stdio.h>
#define MAX_ELEMENT 30

#define length_of_name 100
#define MemSpaceSize 8
#define ScreenMaxSize 5
#define MaxPricedSize 10

typedef struct phoneaddress_t
{
    char name[length_of_name];
    char mem_space[MemSpaceSize];
    char screen_size[ScreenMaxSize];
    char price[MaxPricedSize];
} phone_address;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error syntax!\n");
        printf("Correct syntax: ./program_name <file_name>\n");
        printf("File should be a plain text to write and read\n");
        return 0;
    }
    else
    {
        FILE *fptr1;
        if ((fptr1 = fopen(("%s", argv[1]), "rb")) == NULL)
        {
            printf("Error file %s!\n", argv[1]);
            fclose(fptr1);
            return 0;
        }
        else
        {
            int irc;
            fseek(fptr1, 0, SEEK_END);
            int File_length = ftell(fptr1) / sizeof(phone_address);
            fseek(fptr1, 0, SEEK_SET);
            phone_address phone_book1[MAX_ELEMENT];
            printf("file length: %d\n", File_length);
            irc = fread(phone_book1, sizeof(phone_address), File_length, fptr1);
            // printf("fread return code = %d\n", irc);
            for (int i = 0; i < File_length; i++)
            {
                printf("%-2d%35s%20s\t\t\t%s\t\t\t%s\n", i + 1, phone_book1[i].name, phone_book1[i].mem_space, phone_book1[i].screen_size, phone_book1[i].price);
            }
            fclose(fptr1);
            return 0;
        }
    }
}