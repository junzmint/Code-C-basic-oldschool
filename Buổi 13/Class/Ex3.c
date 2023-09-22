#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

void main()
{
    treeType root1 = NULL;

    node *n1 = makeNewNode(1);
    node *n2 = makeNewNode(2);
    node *n3 = makeNewNode(3);
    node *n4 = makeNewNode(4);
    node *n5 = makeNewNode(5);
    root1 = n1;
    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;
    int data = 0;
    int choice = 0;
    do
    {
        printf("=======================WELCOME TO MAIN MENU====================\n");
        printf("1. Draw tree\n");
        printf("2. Add leftmost node\n");
        printf("3. Add rightmost node\n");
        printf("4. Count nodes\n");
        printf("5. Calculate height\n");
        printf("6. Count leaves\n");
        printf("7. Count internal nodes\n");
        printf("8. Count right children\n");
        printf("9. Count left children\n");
        printf("10. Inorder print\n");
        printf("11. Delete node from BST\n");
        printf("12. Search node\n");
        printf("13. Exit\n");
        printf("===============================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Your tree: \n");
            printf("-----------------------\n");
            drawTree(root1);
            printf("\n-----------------------\n");
            printf("Press enter to continue");
            getchar();
        }
        if (choice == 2)
        {
            printf("Input data: ");
            scanf("%d", &data);
            Add_Left(&root1, data);
            printf("Press enter to continue");
            getchar();
        }
        if (choice == 3)
        {
            printf("Input data: ");
            scanf("%d", &data);
            Add_Right(&root1, data);
            printf("Press enter to continue");
            getchar();
        }
        if (choice == 4)
        {
            printf("Number of nodes: %d\n", nb_nodes(root1));
            printf("Press enter to continue");
            getchar();
        }
        if (choice == 5)
        {
            printf("Height of tree: %i\n", maxDepth(root1));
            printf("Press enter to continue");
            getchar();
        }
        if (choice == 6)
        {
            printf("Number of leaves: %i\n", countLeaves(root1));
            printf("Press enter to continue");
            getchar();
        }
        if (choice == 7)
        {
            printf("Number of internal nodes: %i\n", countInternalNodes(root1));
            printf("Press enter to continue");
            getchar();
        }
        if (choice == 8)
        {
            printf("Number of right children: %i\n", countRightChildren(root1));
            printf("Press enter to continue");
            getchar();
        }
        if (choice == 9)
        {
            printf("number of left children: %i\n", countLeftChildren(root1));  
            printf("Press enter to continue");
            getchar();
        }
        if (choice == 10)
        {
            printf("Inorder print:\n");inorderprint(root1);
            printf("Press enter to continue");
            getchar();
        }
        if (choice == 11){
            printf("Input key: ");
            scanf("%d", &data);
            DeleteNodeBST(data, &root1);
            printf("Press enter to continue");
            getchar();
        }
        getchar();
        if (choice == 12){
            node *find = Find_node(3,root1);
            printf("%d\n",find->element);
            find->element = 10;
            drawTree(root1);
        }
    } while (choice != 13);
    free_tree(root1);
}