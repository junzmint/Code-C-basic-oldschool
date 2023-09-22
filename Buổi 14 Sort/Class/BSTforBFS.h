typedef int ElType;

typedef struct nodeType
{
    ElType element;
    struct nodeType *left;
    struct nodeType *right;
} node;

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

void insertNode(ElType x, treeType *root)
{
    if (*root == NULL)
    {
        *root = (node *)malloc(sizeof(node));
        (*root)->element = x;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (x < (*root)->element)
    {
        insertNode(x, &(*root)->left);
    }
    else if (x > (*root)->element)
    {
        insertNode(x, &(*root)->right);
    }
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

void inorderPrint(treeType tree)
{
    if (tree != NULL)
    {
        inorderPrint(tree->left);
        printf("%d ", tree->element);
        inorderPrint(tree->right);
    }
}

void postorderPrint(treeType tree)
{
    if (tree != NULL)
    {
        postorderPrint(tree->left);
        postorderPrint(tree->right);
        printf("%d ", tree->element);
    }
}

void preorderPrint(treeType tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->element);
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
        if (x < (*root)->element)
        {
            DeleteNode(x, &(*root)->left);
        }
        else if (x > (*root)->element)
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

// Wrapper over print2DUtil()
void drawTree(treeType root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

/////////BFS
struct QueueEl_t
{
    node *elementQ;
    struct QueueEl_t *next;
    struct QueueEl_t *prev;
};

typedef struct QueueEl_t QueueEl;

typedef struct Queue_t
{
    QueueEl *front, *rear;
} Queue;

QueueEl *makeNewNodeQ(node *X)
{
    QueueEl *new = (QueueEl *)malloc(sizeof(QueueEl));
    if (new == NULL)
    {
        printf("Memory node allocation failed.\n");
        return NULL;
    }
    new->elementQ = X;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

Queue *createQueue()
{
    Queue *new = (Queue *)malloc(sizeof(Queue));
    new->front = new->rear = NULL;
    return new;
}

int emptyQueue(Queue *Q)
{
    return (Q->front == NULL);
}

void EnQueue(node *X, Queue *Q)
{
    QueueEl *tmp = makeNewNodeQ(X);
    if (Q->rear == NULL)
    {
        Q->front = Q->rear = tmp;
        return;
    }
    Q->rear->next = tmp;
    tmp->prev = Q->rear;
    Q->rear = tmp;
}

void DeQueue(Queue *Q)
{
    if (Q->front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    QueueEl *temp = Q->front;
    Q->front = Q->front->next;
    if (Q->front == NULL)
    {
        Q->rear = NULL;
    }
    free(temp);
}

void makeQueueEmpty(Queue *Q)
{
    if (Q->front == NULL)
    {
        return;
    }
    void *tmp = Q->front;
    while (Q->front != NULL)
    {
        Q->front = Q->front->next;
        free(tmp);
        tmp = Q->front;
    }
}


void bfs(treeType node)
{
    Queue **queue;
    *queue = createQueue(); // queue of pointer
    if (node != NULL)
    {
        EnQueue(node, *queue);
        while (!emptyQueue(*queue))
        {
            node = (*queue)->front->elementQ;
            DeQueue(*queue);
            printf("%d ", node->element);
            if (node->left != NULL)
            {
                EnQueue(node->left, *queue);
            }
            if (node->right != NULL)
            {
                EnQueue(node->right, *queue);
            }
        }
    }
    makeQueueEmpty(*queue);
}

void free_tree(node *node)
{
    if (node != NULL)
    {
        free_tree(node->right);
        free_tree(node->left);
        free(node);
    }
}

