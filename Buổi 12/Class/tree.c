#include<stdio.h>
#include<stdlib.h>
typedef struct input
{
    char name[20];
    char mem_space[20];
    char screen_size[20];
    char price[20];
}elementtype;

typedef struct nodeType
{
    elementtype element;
    struct nodeType *left;
    struct nodeType *right;
}nodeType;

typedef struct nodeType *Treetype;

void MakeNullTree(Treetype *root){
    (*root) = NULL;
}

int isEmpty(Treetype root){
    return root == NULL;
}

Treetype LeftChild(Treetype n){
    if(n != NULL) return n->left;
    else return NULL;
}

Treetype RightChild(Treetype n){
    if(n != NULL) return n->right;
    else return NULL;
}

nodeType *makeNewNode(elementtype new_element)
{
    nodeType *new = (nodeType *)malloc(sizeof(nodeType));
    if(new != NULL){
        new->element = new_element;
        new->left = NULL;
        new->right = NULL;
    }
    return new;
}

int IsLeaf(Treetype n){
    if(n!= NULL)
        return(LeftChild(n) == NULL) && (RightChild(n) == NULL);
    else
        return -1;
}

int nb_nodes(Treetype T){
    if(isEmpty(T)) return 0;
    else return 1 + nb_nodes(LeftChild(T)) + nb_nodes(RightChild(T));
}

Treetype creatfrom2(elementtype v, Treetype l, Treetype r){
    Treetype N;
    N = (nodeType *)malloc(sizeof(nodeType));
    N->element = v;
    N->left = l;
    N->right = r;
    return N;
}

Treetype AddRigth(Treetype *Tree, elementtype data){
    nodeType *NewNode = makeNewNode(data);
    if (NewNode == NULL)
    {
        return (NewNode);
    }
    if(*Tree == NULL)
        *Tree = NewNode;
    else{
        nodeType *Rnode = *Tree;
        while (Rnode->right !=NULL)
        {
            Rnode = Rnode->right;
        }
        Rnode->right = NewNode;
    }
    return NewNode;
}

Treetype AddLeft(Treetype *Tree, elementtype data){
    nodeType *NewNode = makeNewNode(data);
    if (NewNode == NULL)
    {
        return (NewNode);
    }
    if(*Tree == NULL)
        *Tree = NewNode;
    else{
        nodeType *Lnode = *Tree;
        while (Lnode->left !=NULL)
        {
            Lnode = Lnode->left;
        }
        Lnode->left = NewNode;
    }
    return NewNode;
}




