int menuDAT(FILE *fptr)
{
    treeType root = NULL;
    fseek(fptr, 0, SEEK_END);
    int File_length = ftell(fptr) / sizeof(ElType);
    fseek(fptr, 0, SEEK_SET);
    char choice;
    int check2DAT = 0;
    do
    {
        printf("\n");
        printf("=======================WELCOME TO MAIN MENU====================\n");
        printf("======================THIS IS .DAT FILE TYPE===================\n");
        printf("1. Import from Text: Build a list from .txt file (DISABLE)\n");
        printf("2. Import from Dat: Build a list from .dat file\n");
        printf("3. Display the list\n");
        printf("4. Search and update phone by Model\n");
        printf("5. Delete phone\n");
        printf("6. Export to Dat\n");
        printf("7. Add phone model\n");
        printf("8. Quit\n");
        printf("File_length: %d\n", File_length);
        printf("===============================================================\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        if (choice == '1')
        {
            printf("DISABLE! Wrong file type\n");
            getchar();
            printf("Press Enter to continue!");
        }
        if (choice == '2')
        {
            printf("Option 2\n");
            Option2DAT(fptr, File_length, &root);
            check2DAT++;
        }
        if (choice == '3' && check2DAT != 0)
        {
            printf("Option 3\n");
            Option3(root);
        }
        else if (choice == '3')
        {
            printf("You must use function 2 before using this\n");
            getchar();
            printf("Press Enter to continue!");
        }

        if (choice == '4' && check2DAT != 0)
        {
            printf("Option 4\n");
            Option4(&root);
        }
        else if (choice == '4')
        {
            printf("You must use function 2 before using this\n");
            getchar();
            printf("Press Enter to continue!");
        }

        if (choice == '5' && check2DAT != 0)
        {
            printf("Option 5\n");
            Option5(&root, &File_length);

        }
        else if (choice == '5')
        {
            printf("You must use function 2 before using this\n");
            getchar();
            printf("Press Enter to continue!");
        }
        if (choice == '6' && check2DAT != 0)
        {
            printf("Option 6\n");
            Option6(root, File_length);
        }
        else if (choice == '6')
        {
            printf("You must use function 2 before using this\n");
            getchar();
            printf("Press Enter to continue!");
        }
        if (choice == '7' && check2DAT != 0)
        {
            printf("Option 7\n");
            Option7(&File_length, &root);
        }
        else if (choice == '7')
        {
            printf("You must use function 2 before using this\n");
            getchar();
            printf("Press Enter to continue!");
        }
        printf("\n");
        while (getchar() != '\n')
            ;
    } while (choice != '8');
    free_tree(root);
}