int Option1TXT(FILE *fptr, int File_length, treeType *root)
{
    phoneDB = (ElType *)malloc(sizeof(ElType) * File_length);
    if (phoneDB == NULL)
    {
        printf("Allocated memory ERROR!\n");
        return ERROR;
    }
    fseek(fptr, 0, SEEK_SET);
    for (int i = 0; i < File_length; i++)
    {
        fgets(phoneDB[i].name, SIZE, fptr);
        phoneDB[i].name[strlen(phoneDB[i].name) - 1] = '\0';
        fgets(phoneDB[i].mem_space, SIZE, fptr);
        phoneDB[i].mem_space[strlen(phoneDB[i].mem_space) - 1] = '\0';
        fgets(phoneDB[i].screen_size, SIZE, fptr);
        phoneDB[i].screen_size[strlen(phoneDB[i].screen_size) - 1] = '\0';
        fgets(phoneDB[i].price, SIZE, fptr);
        phoneDB[i].price[strlen(phoneDB[i].price) - 1] = '\0';
    }
    fseek(fptr, 0, SEEK_SET);
    for (int i = 0; i < File_length; i++)
    {
        insertNode(phoneDB[i], root);
    }
    printf("%-2s%30s\t%17s\t\t%10s\t\t%s\n", "ID", "Phone name", "Memory space", "Screen size (inch)", "Price(Yen)");
    for (int i = 0; i < File_length; i++)
    {
        printf("%-2d%35s%20s\t\t\t%s\t\t\t%s\n", i + 1, phoneDB[i].name, phoneDB[i].mem_space, phoneDB[i].screen_size, phoneDB[i].price);
    }
    printf("\n");
    getchar();
    printf("Press Enter to continue!");
}

int Option2DAT(FILE *fptr, int File_length, treeType *root)
{
    phoneDB = (ElType *)malloc(sizeof(ElType) * File_length);
    if (phoneDB == NULL)
    {
        printf("Allocated memory ERROR!\n");
        return ERROR;
    }
    fread(phoneDB, sizeof(ElType), File_length, fptr);
    fseek(fptr, 0, SEEK_SET);
    for (int i = 0; i < File_length; i++)
    {
        insertNode(phoneDB[i], root);
    }
    printf("%-2s%30s\t%17s\t\t%10s\t\t%s\n", "ID", "Phone name", "Memory space", "Screen size (inch)", "Price(Yen)");
    for (int i = 0; i < File_length; i++)
    {
        printf("%-2d%35s%20s\t\t\t%s\t\t\t%s\n", i + 1, phoneDB[i].name, phoneDB[i].mem_space, phoneDB[i].screen_size, phoneDB[i].price);
    }
    printf("Press Enter to continue!");
    getchar();
}

int Option3(treeType root)
{
    int choice = 0;
    do
    {
        printf("===============================================================\n");
        printf("1. Display inorder\n");
        printf("2. Display postorder\n");
        printf("3. Display preorder\n");
        printf("4. Quit\n");
        printf("===============================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            inorderPrint(root);
            printf("Press Enter to continue!");
            getchar();
        }
        if (choice == 2)
        {
            postorderPrint(root);
            printf("Press Enter to continue!");
            getchar();
        }
        if (choice == 3)
        {
            preorderPrint(root);
            printf("Press Enter to continue!");
            getchar();
        }
        while (getchar() != '\n')
            ;
    } while (choice != 4);
    printf("Press Enter to continue!");
}

int Option4(treeType *root)
{
    char search[SIZE];
    char tmp[SIZE] = "";
    int *no_response;
    int flag = 0;
    no_response = &flag;
    printf("Enter the phone you want to find:\n");
    getchar();
    gets(search);
    inorderSearch(root, *root, search, &no_response);
    if (no_response == 0)
    {
        printf("There is no result!\n");
    }
    printf("Press Enter to continue!");
}

int Option5(treeType *root, int *File_length)
{
    char delete[SIZE];
    printf("Enter the phone you want to delete: ");
    getchar();
    gets(delete);
    inorderDelete(root, *root, delete, &File_length);
}

int Option6(treeType root, int File_length)
{
    FILE *file_out;
    char file_name[SIZE];
    getchar();
    do
    {
        printf("Enter the output file name (File must be in .dat format): ");
        scanf("%s", &file_name);
    } while (checkFileType(file_name[strlen(file_name) - 3]) != DAT);
    if ((file_out = fopen(("%s", file_name), "w+b")) == NULL)
    {
        printf("Error file %s!\n", file_name[1]);
        return ERROR;
    }
    ElType phoneDBtmp[File_length];
    int count = 0;
    inorderSave(root, phoneDBtmp, &count);
    fwrite(phoneDBtmp, sizeof(ElType), File_length, file_out);
    fclose(file_out);
}

int Option7(int *File_length, treeType *root)
{
    ElType tmp;
    printf("Enter name:\n");
    getchar();
    // gets(phone_book[i].name);
    gets(tmp.name);
    // printf("Memory space: ");
    printf("Enter memory space:\n");
    scanf("%s", tmp.mem_space);
    // printf("Screen size: ");
    printf("Enter screen size:\n");
    scanf("%s", tmp.screen_size);
    // printf("Price");
    printf("Enter price:\n");
    scanf("%s", tmp.price);
    insertNode(tmp, root);
    *File_length += 1;
}