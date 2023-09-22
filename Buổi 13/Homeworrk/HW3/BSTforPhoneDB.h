typedef node *treeType;

void makeNullTree(treeType *t)
{
    (*t) = NULL;
}

node *makeNewNode(ElType newData)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode != NULL)
    {
        newNode->element = newData;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

int emptyTree(treeType T)
{
    return (T == NULL);
}

node *LeftChild(node *n)
{
    if (n != NULL)
    {
        return (n->left);
    }
    else
    {
        return (NULL);
    }
}

node *RightChild(node *n)
{
    if (n != NULL)
    {
        return (n->right);
    }
    else
    {
        return (NULL);
    }
}

int isLeaf(node *n)
{
    if (n != NULL)
    {
        return (LeftChild(n) == NULL) && (RightChild(n) == NULL);
    }
    else
    {
        return -1;
    }
}

int nb_nodes(treeType T) // Number of nodes
{
    if (emptyTree(T))
    {
        return 0;
    }
    else
    {
        return 1 + nb_nodes(LeftChild(T)) + nb_nodes(RightChild(T));
    }
}

node *createFrom2(ElType v, node *l, node *r)
{
    node *N;
    N = (node *)malloc(sizeof(node));
    N->element = v;
    N->left = l;
    N->right = r;
    return N;
}

node *Add_Left(treeType *Tree, ElType newData)
{
    node *newNode = makeNewNode(newData);
    if (newNode == NULL)
        return newNode;
    if (*Tree == NULL)
    {
        *Tree = newNode;
    }
    else
    {
        node *Lnode = *Tree;
        while (Lnode->left != NULL)
        {
            Lnode = Lnode->left;
        }
        Lnode->left = newNode;
    }
    return newNode;
}

node *Add_Right(treeType *Tree, ElType newData)
{
    node *newNode = makeNewNode(newData);
    if (newNode == NULL)
        return newNode;
    if (*Tree == NULL)
    {
        *Tree = newNode;
    }
    else
    {
        node *Rnode = *Tree;
        while (Rnode->right != NULL)
        {
            Rnode = Rnode->right;
        }
        Rnode->right = newNode;
    }
    return newNode;
}

int maxDepth(node *T)
{
    if (T == NULL)
    {
        return -1;
    }
    else
    {
        int leftDepth = maxDepth(T->left);
        int rightDepth = maxDepth(T->right);

        if (leftDepth > rightDepth)
        {
            return leftDepth + 1;
        }
        else
        {
            return rightDepth + 1;
        }
    }
}

int countLeaves(treeType T)
{
    if (T == NULL)
    {
        return 0;
    }
    if (isLeaf(T))
    {
        return 1;
    }
    else
    {
        return countLeaves(T->left) + countLeaves(T->right);
    }
}

int countInternalNodes(treeType T)
{
    if (T == NULL || isLeaf(T))
    {
        return 0;
    }
    return (1 + countInternalNodes(T->left) + countInternalNodes(T->right));
}

int countRightChildren(treeType T)
{
    if (T == NULL)
    {
        return 0;
    }
    int count_left = 0;
    int count_right = 0;
    if (T->left != NULL)
    {
        count_left = countRightChildren(T->left);
    }
    if (T->right != NULL)
    {
        count_right = 1 + countRightChildren(T->right);
    }
    return count_left + count_right;
}

int countLeftChildren(treeType T)
{
    if (T == NULL)
        return 0;
    int count_left = 0;
    int count_right = 0;

    if (T->left != NULL)
    {
        count_left = 1 + countLeftChildren(T->left);
    }
    if (T->right != NULL)
    {
        count_right = countLeftChildren(T->right);
    }
    return count_right + count_left;
}

void print2DUtil(treeType root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%s ", root->element.name);

    // Process left child
    print2DUtil(root->left, space);
}

void drawTree(treeType root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

void prettyPrint(treeType tree, char *prefix)
{
    char *prefixend = prefix + strlen(prefix);
    if (tree != NULL)
    {
        printf("%04d", tree->element);
        if (tree->left != NULL)
        {
            if (tree->right == NULL)
            {
                printf("\304");
                strcat(prefix, "     ");
            }
            else
            {
                printf("\302");
                strcat(prefix, "\263    ");
            }
        }
        prettyPrint(tree->left, prefix);
        *prefixend = '\0';
        if (tree->right != NULL)
        {
            if (tree->left != NULL)
            {
                printf("\n%s", prefix);
                printf("\300");
            }
            else
            {
                printf("\304");
            }
        }
        strcat(prefix, "     ");
        prettyPrint(tree->right, prefix);
    }
}

int compareName(char name1[], char name2[])
{
    return strcmp(name1, name2);
}

void insertNode(ElType x, treeType *root)
{
    if (*root == NULL)
    {
        *root = (node *)malloc(sizeof(node));
        (*root)->element = x;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (compareName(x.name, (*root)->element.name) < 0)
    {
        insertNode(x, &(*root)->left);
    }
    else if (compareName(x.name, (*root)->element.name) > 0)
    {
        insertNode(x, &(*root)->right);
    }
    else
    {
        insertNode(x, &(*root)->left);
    }
}

void inorderPrint(treeType tree)
{
    if (tree != NULL)
    {
        inorderPrint(tree->left);
        printf("%s\n", tree->element.name);
        inorderPrint(tree->right);
    }
}

void postorderPrint(treeType tree)
{
    if (tree != NULL)
    {
        postorderPrint(tree->left);
        postorderPrint(tree->right);
        printf("%s\n", tree->element.name);
    }
}

void preorderPrint(treeType tree)
{
    if (tree != NULL)
    {
        printf("%s\n", tree->element.name);
        preorderPrint(tree->left);
        preorderPrint(tree->right);
    }
}

ElType DeleteMin(treeType *root)
{
    ElType key;
    if ((*root)->left == NULL)
    {
        key = (*root)->element;
        node *tmp = *root;
        (*root) = (*root)->right;
        free(tmp);
        return key;
    }
    else
    {
        return DeleteMin(&(*root)->left);
    }
}

void DeleteNode(ElType x, treeType *root)
{
    if (*root != NULL)
    {
        if (strcmp(x.name, (*root)->element.name) < 0)
        {
            DeleteNode(x, &(*root)->left);
        }
        else if (strcmp(x.name, (*root)->element.name) > 0)
        {
            DeleteNode(x, &(*root)->right);
        }
        else if ((*root)->left == NULL && (*root)->right == NULL)
        {
            node *tmp = *root;
            *root = NULL;
            free(tmp);
        }
        else if ((*root)->left == NULL)
        {
            node *tmp = *root;
            *root = (*root)->right;
            free(tmp);
        }
        else if ((*root)->right == NULL)
        {
            node *tmp = *root;
            *root = (*root)->left;
            free(tmp);
        }
        else
        {
            (*root)->element = DeleteMin(&(*root)->right);
        }
    }
}

void inorderSearch(treeType *root, treeType tree, char search[], int **no_response)
{

    if (tree != NULL)
    {
        inorderSearch(root, (tree)->left, search, no_response);
        if (strncmp(search, (tree)->element.name, strlen(search)) == SUCCESS)
        {
            printf("%s\n", (tree)->element.name);
            **no_response++;
            printf("Do you want to update this phone?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            printf("Enter your option: ");
            int choice = 0;
            ElType tmp;
            scanf("%d", &choice);
            if (choice == 1)
            {
                DeleteNode(tree->element, root);
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
            }
        }
        inorderSearch(root, (tree)->right, search, no_response);
    }
}

void inorderDelete(treeType *root, treeType tree, char delete[], int **File_length)
{
    if (tree != NULL)
    {
        inorderDelete(root, (tree)->left, delete, File_length);
        if (strncmp(delete, tree->element.name, strlen(delete)) == SUCCESS)
        {
            
            DeleteNode(tree->element, root);
            **File_length -= 1;
        }
        inorderDelete(root, (tree)->right, delete, File_length);
    }
}

void inorderSave(treeType tree, ElType phoneDBtmp[], int *count)
{
    if (tree != NULL)
    {
        inorderSave(tree->left, phoneDBtmp, count);
        phoneDBtmp[*count] = tree->element;
        *count +=1;
        inorderSave(tree->right, phoneDBtmp, count);
    }
}
// Wrapper over print2DUtil()

void free_tree(node *node)
{
    if (node != NULL)
    {
        free_tree(node->right);
        free_tree(node->left);
        free(node);
    }
}