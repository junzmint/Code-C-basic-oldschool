int Option1DAT(FILE *fptr, int File_length, doublelist *root, doublelist *tail, doublelist *cur)
{
    phoneDB = (element_type *)malloc(sizeof(element_type) * File_length);
    if (phoneDB == NULL)
    {
        printf("Allocated memory ERROR!\n");
        return ERROR;
    }
    fread(phoneDB, sizeof(element_type), File_length, fptr);
    fseek(fptr, 0, SEEK_SET);
    for (int i = 0; i < File_length; i++)
    {
        insertAfterCur(phoneDB[i], root, tail, cur);
    }
    printf("Press Enter to continue!");
    getchar();
}

int Option2DAT(doublelist *root, doublelist *cur)
{
    printf("============================================================================================================================\n");
    traversingList(root, cur);
    printf("============================================================================================================================\n");
    printf("Press Enter to continue!");
    getchar();
}

int Option3(int *File_length, doublelist *root, doublelist *tail, doublelist *cur)
{
    int n = 0;
    // int seekPoint = 0;
    char decision;
    element_type tmpelement;
    printf("How many phone model you want to insert: ");
    scanf("%d", &n);
    phoneDB = (element_type *)realloc(phoneDB, (*File_length + n) * sizeof(element_type));
    if (phoneDB == NULL)
    {
        printf("Memory allocation failed!\n");
        return ERROR;
    }
    if (n == 0)
    {
        return SUCCESS;
    }
    do
    {
        printf("Select the way to input the phone model\n");
        printf("1. Before current position\n");
        printf("2. After current position\n");
        printf("3. Insert at first\n");
        printf("4. Insert at last (append)\n");
        printf("Your choice: ");
        getchar();
        scanf("%c", &decision);
    } while (decision != '1' && decision != '2' && decision != '3' && decision != '4');
    if (decision == '1')
    {
        printf("There are %d phone in list\n", *File_length);
        printf("The current position is: %s\n", (*cur)->element.name);
        // printf("Enter your current position you want to insert before: ");
        // scanf("%d", &seekPoint);
        // checkSeekPoint(seekPoint, *File_length);
        for (int i = 0; i < n; i++)
        {

            getchar();
            printf("Enter name %d: ", i + 1);
            gets(tmpelement.name);
            strcpy(phoneDB[*File_length].name, tmpelement.name);
            printf("Enter memory space: ");
            gets(tmpelement.mem_space);
            strcpy(phoneDB[*File_length].mem_space, tmpelement.mem_space);
            printf("Enter screen size: ");
            gets(tmpelement.screen_size);
            strcpy(phoneDB[*File_length].screen_size, tmpelement.screen_size);
            printf("Enter price: ");
            gets(tmpelement.price);
            strcpy(phoneDB[*File_length].price, tmpelement.price);
            insertBeforeCur(tmpelement, root, tail, cur);
        }
        *File_length += n;
    }
    if (decision == '2')
    {
        printf("There are %d phone in list\n", *File_length);
        printf("The current position is: %s\n", (*cur)->element.name);
        // printf("Enter your current position you want to insert after: ");
        // scanf("%d", &seekPoint);
        // checkSeekPoint(seekPoint, *File_length);
        for (int i = 0; i < n; i++)
        {
            getchar();
            printf("Enter name %d: ", i + 1);
            gets(tmpelement.name);
            strcpy(phoneDB[*File_length].name, tmpelement.name);
            printf("Enter memory space: ");
            gets(tmpelement.mem_space);
            strcpy(phoneDB[*File_length].mem_space, tmpelement.mem_space);
            printf("Enter screen size: ");
            gets(tmpelement.screen_size);
            strcpy(phoneDB[*File_length].screen_size, tmpelement.screen_size);
            printf("Enter price: ");
            gets(tmpelement.price);
            strcpy(phoneDB[*File_length].price, tmpelement.price);
            insertAfterCur(tmpelement, root, tail, cur);
        }
        *File_length += n;
    }
    if (decision == '3')
    {
        printf("There are %d phone in list\n", *File_length);
        for (int i = 0; i < n; i++)
        {
            getchar();
            printf("Enter name %d: ", i + 1);
            gets(tmpelement.name);
            strcpy(phoneDB[*File_length].name, tmpelement.name);
            printf("Enter memory space: ");
            gets(tmpelement.mem_space);
            strcpy(phoneDB[*File_length].mem_space, tmpelement.mem_space);
            printf("Enter screen size: ");
            gets(tmpelement.screen_size);
            strcpy(phoneDB[*File_length].screen_size, tmpelement.screen_size);
            printf("Enter price: ");
            gets(tmpelement.price);
            strcpy(phoneDB[*File_length].price, tmpelement.price);
            insertAtHead(tmpelement, root, tail, cur);
        }
        *File_length += n;
    }
    if (decision == '4')
    {
        printf("There are %d phone in list\n", *File_length);
        for (int i = 0; i < n; i++)
        {
            getchar();
            printf("Enter name %d: ", i + 1);
            gets(tmpelement.name);
            strcpy(phoneDB[*File_length].name, tmpelement.name);
            printf("Enter memory space: ");
            gets(tmpelement.mem_space);
            strcpy(phoneDB[*File_length].mem_space, tmpelement.mem_space);
            printf("Enter screen size: ");
            gets(tmpelement.screen_size);
            strcpy(phoneDB[*File_length].screen_size, tmpelement.screen_size);
            printf("Enter price: ");
            gets(tmpelement.price);
            strcpy(phoneDB[*File_length].price, tmpelement.price);
            insertAtTail(tmpelement, root, tail, cur);
        }
        *File_length += n;
    }

    printf("Press Enter to continue!");
}

int Option4(int *File_length, doublelist *root, doublelist *tail, doublelist *cur)
{
    element_type tmpelement;
    phoneDB = (element_type *)realloc(phoneDB, (*File_length + 1) * sizeof(element_type));
    if (phoneDB == NULL)
    {
        printf("Memory reallocation failed!\n");
        return ERROR;
    }
    int seekPoint = 0;
    if (*File_length == 0)
    {
        printf("There is no available position because there is no element in list\n");
        printf("Auto add new element as root!\n");
    }
    else
    {
        printf("There is %d elements in list\n", *File_length);
        printf("Enter your current position you want to insert: ");
        scanf("%d", &seekPoint);
    }
    getchar();
    printf("Enter name: ");
    gets(tmpelement.name);
    strcpy(phoneDB[*File_length].name, tmpelement.name);
    printf("Enter memory space: ");
    gets(tmpelement.mem_space);
    strcpy(phoneDB[*File_length].mem_space, tmpelement.mem_space);
    printf("Enter screen size: ");
    gets(tmpelement.screen_size);
    strcpy(phoneDB[*File_length].screen_size, tmpelement.screen_size);
    printf("Enter price: ");
    gets(tmpelement.price);
    strcpy(phoneDB[*File_length].price, tmpelement.price);
    insertAtPosition(tmpelement, File_length, seekPoint, root, tail, cur);
    printf("Press Enter to continue!");
}

int Option5(int *File_length, doublelist *root, doublelist *tail, doublelist *cur)
{
    if (*File_length == 0)
    {
        printf("There is no element in list!\n");
        return ERROR;
    }
    int n;
    printf("There are %d phone in list\n", *File_length);
    do
    {
        printf("Enter position you want to delete (0 <= x < %d): ", *File_length);
        scanf("%d", &n);
    } while (n < 0 || n >= *File_length);
    deleteAtPosition(File_length, n, root, tail, cur);
    getchar();
    printf("Press Enter to continue!");
}

int Option6(int *File_length, doublelist *root, doublelist *tail, doublelist *cur)
{
    printf("The current node is at %s\n", (*cur)->element.name);
    deleteCurrentNode(File_length, root, tail, cur);
    getchar();
    printf("Press Enter to continue!");
}

int Option7(int *File_length, doublelist *root, doublelist *tail, doublelist *cur)
{
    deleteAtFirst(File_length, root, cur);
    getchar();
    printf("Press Enter to continue!");
}

int Option8(int *File_length, doublelist *root, doublelist *tail, doublelist *cur)
{
    deleteAtLast(File_length, tail, cur);
    getchar();
    printf("Press Enter to continue!");
}

int Option9(int File_length, doublelist *root, doublelist *tail, doublelist *cur)
{
    int choice = 0;
    char search[SIZE];
    char tmp[SIZE] = "";
    int no_response = 0;
    node *tmp_node = *root;
    printf("Enter the phone you want to find:\n");
    getchar();
    gets(search);
    for (int i = 0; i < File_length; i++)
    {
        strncpy(tmp, tmp_node->element.name, strlen(search));
        if (strcmp(search, tmp) == SUCCESS)
        {
            printf("%-2d%35s%20s\t\t\t%s\t\t\t%s\n", i + 1, tmp_node->element.name, tmp_node->element.mem_space, tmp_node->element.screen_size, tmp_node->element.price);
            printf("Do you want to update this phone?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            printf("Enter your option: ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("Enter name:\n");
                getchar();
                // gets(phone_book[i].name);
                gets(tmp_node->element.name);
                // printf("Memory space: ");
                printf("Enter memory space:\n");
                scanf("%s", tmp_node->element.mem_space);
                // printf("Screen size: ");
                printf("Enter screen size:\n");
                scanf("%s", tmp_node->element.screen_size);
                // printf("Price");
                printf("Enter price:\n");
                scanf("%s", tmp_node->element.price);
            }
        }
        else
        {
            no_response++;
        }
        tmp_node = tmp_node->next;
    }
    if (no_response == File_length)
    {
        printf("\nThere is no result\n");
    }
    no_response = 0;
    getchar();
    printf("Press Enter to continue!");
}

int Option10(int File_length, doublelist *root, doublelist *tail, doublelist *cur)
{
    list_reverse(File_length, root, tail, cur);
    *cur = *root;
    getchar();
    printf("Press Enter to continue!");
}

int Option11(FILE *fptr, int File_length, doublelist *root)
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
    fseek(fptr, 0, SEEK_SET);
    SaveDatFile(file_out, File_length, root);
    fclose(file_out);
    getchar();
    printf("Press Enter to continue!");
}