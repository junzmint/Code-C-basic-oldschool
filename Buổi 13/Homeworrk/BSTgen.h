typedef int ElType;

typedef struct nodeType
{
    ElType element;
    struct nodeType *left;
    struct nodeType *right;
} node;

typedef node *treeType;

int IsEmpty(treeType T)
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

void makeNullTree(treeType *t)
{
    (*t) = NULL;
}

int nb_nodes(treeType T) // Number of nodes
{
    if (IsEmpty(T))
    {
        return 0;
    }
    else
    {
        return 1 + nb_nodes(LeftChild(T)) + nb_nodes(RightChild(T));
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
    printf("%d\n", root->element);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void drawTree(treeType root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

void free_tree(treeType tree)
{
    if (tree != NULL)
    {
        free_tree(tree->left);
        free_tree(tree->right);
        free((void*)tree);
    }
}

//Hàm duyệt cây có thể dùng với cả BST
void inorderprint (treeType tree){
    if (tree!=NULL){
        inorderprint (tree->left);
        printf ("%4d\n", tree->element);
        inorderprint (tree->right);
    }
}

void postorderprint (treeType tree){
    if (tree!=NULL){
        postorderprint (tree->left);
        postorderprint (tree->right);
        printf ("%4d\n", tree->element);
    }
}

void preorderprint (treeType tree){
    if (tree!=NULL){
        printf ("%4d\n", tree->element);
        preorderprint (tree->left);
        preorderprint (tree->right);    
    }  
}

treeType InsertNodeBinarySearch(treeType t,ElType x)
{
    if (IsEmpty(t))
    {
        node *new;
        new = (node *)malloc(sizeof(node));
        new->element = x;
        new->left = NULL;
        new-> right = NULL;
        t = new;
    }
    else
    {
        if (x < (t->element)) t->left = InsertNodeBinarySearch(t->left , x);
        else
        {
            if (x > (t->element)) t->right = InsertNodeBinarySearch(t->right, x);
        }
    }
    return t;
}
 
treeType SearchBinarySearch(treeType t, ElType find)
{
    if (IsEmpty(t))
    {
        return NULL;
    }
    else
    {
        if (t->element == find) return t;
        else
        {
            if (t->element <find) return SearchBinarySearch(t->right,find);
            else return SearchBinarySearch(t->left,find);
        }
    }
}

//Find the leftmost node of right subtree and then delete it
ElType DeleteMin(treeType *root){
    ElType k;
    if((*root)->left == NULL){
        k = (*root)->element;
        *root = (*root)->right;
        return k;
    }
    else return DeleteMin(&(*root)->left);
    
}

void DeleteNodeBST(ElType x, treeType *root){
    if((*root) != NULL){
        if(x < (*root)->element) DeleteNodeBST(x, &(*root)->left);
        else if(x > (*root)->element) DeleteNodeBST(x, &(*root)->right);
        else if(((*root)->left == NULL) && ((*root)->right == NULL)) *root = NULL;
        else if((*root)->left == NULL) *root = (*root)->right;
        else if((*root)->right == NULL) *root = (*root)->right;
        else (*root)->element = DeleteMin(&(*root)->right);
    }
}