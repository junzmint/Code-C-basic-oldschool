int menuDAT(FILE *fptr, doublelist *root, doublelist *tail, doublelist *cur)
{
    fseek(fptr, 0, SEEK_END);
    int File_length = ftell(fptr) / sizeof(element_type);
    fseek(fptr, 0, SEEK_SET);
    int choice;
    int check1DAT = 0;
    do
    {
        printf("\n");
        printf("=======================WELCOME TO MAIN MENU====================\n");
        printf("======================THIS IS .DAT FILE TYPE===================\n");
        printf("1. Import from Dat: Build a list from .dat file\n");
        printf("2. Display the list\n");
        printf("3. Add new phone\n");
        printf("4. Insert at position\n");
        printf("5. Delete at position\n");
        printf("6. Delete current\n");
        printf("7. Delete first\n");
        printf("8. Delete last\n");
        printf("9. Search and update\n");
        printf("10. Reverse List\n");
        printf("11. Save to file\n");
        printf("12. Quit\n");
        printf("File_length: %d\n", File_length);
        printf("===============================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Option 1\n");
            fseek(fptr, 0, SEEK_END);
            File_length = ftell(fptr) / sizeof(element_type);
            fseek(fptr, 0, SEEK_SET);
            Option1DAT(fptr, File_length, root, tail, cur);
            check1DAT++;
        }
        if (choice == 2 && check1DAT != 0)
        {
            printf("Option 2\n");
            Option2DAT(root, cur);
        }
        else if (choice == 2)
        {
            printf("You must use function 1 before using this\n");
            getchar();
            printf("Press Enter to continue!");
        }
        if (choice == 3 && check1DAT != 0)
        {
            printf("Option 3\n");
            Option3(&File_length, root, tail, cur);
        }
        else if (choice == 3)
        {
            printf("You must use function 1 before using this\n");
            getchar();
            printf("Press Enter to continue!");
        }
        if (choice == 4 && check1DAT != 0)
        {
            printf("Option 4\n");
            Option4(&File_length, root, tail, cur);
        }
        else if (choice == 4)
        {
            printf("You must use function 1 before using this\n");
            getchar();
            printf("Press Enter to continue!");
        }
        if (choice == 5 && check1DAT != 0)
        {
            printf("Option 5\n");
            Option5(&File_length, root, tail, cur);
        }
        else if (choice == 5)
        {
            printf("You must use function 1 before using this\n");
            getchar();
            printf("Press Enter to continue!");
        }
        if (choice == 6 && check1DAT != 0)
        {
            printf("Option 6\n");
            Option6(&File_length, root, tail, cur);
        }
        else if (choice == 6)
        {
            printf("You must use function 1 before using this\n");
            getchar();
            printf("Press Enter to continue!");
        }
        if (choice == 7 && check1DAT != 0)
        {
            printf("Option 7\n");
            Option7(&File_length, root, tail, cur);
        }
        else if (choice == 7)
        {
            printf("You must use function 1 before using this\n");
            getchar();
            printf("Press Enter to continue!");
        }
        if (choice == 8 && check1DAT != 0)
        {
            printf("Option 8\n");
            Option8(&File_length, root, tail, cur);
        }
        else if (choice == 8)
        {
            printf("You must use function 1 before using this\n");
            getchar();
            printf("Press Enter to continue!");
        }
        if (choice == 9 && check1DAT != 0)
        {
            printf("Option 9\n");
            Option9(File_length, root, tail, cur);
        }
        else if (choice == 9)
        {
            printf("You must use function 1 before using this\n");
            getchar();
            printf("Press Enter to continue!");
        }
        if (choice == 10 && check1DAT != 0)
        {
            printf("Option 10\n");
            Option10(File_length, root, tail, cur);
        }
        else if (choice == 10)
        {
            printf("You must use function 1 before using this\n");
            getchar();
            printf("Press Enter to continue!");
        }
        if (choice == 11 && check1DAT != 0)
        {
            printf("Option 11\n");
            Option11(fptr, File_length, root);
        }
        else if (choice == 11)
        {
            printf("You must use function 1 before using this\n");
            getchar();
            printf("Press Enter to continue!");
        }
        printf("\n");
        while (getchar() != '\n')
            ;
    } while (choice != 12);
}