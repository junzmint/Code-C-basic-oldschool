#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000

typedef struct elementtype {
      char name[20];
      char tel[11];
      char email[25];
}elementtype;

struct node_t
{
    elementtype element;
    struct node_t *next;
    struct node_t *prev;
};
typedef struct node_t node;

node *root, *cur, *tail;

node* MakeNewNode(elementtype data){
    node *new;
    new = (node*)malloc(sizeof(node));
    new->element = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

node* InsertHead(elementtype data){
    if(root == NULL){
        node *new;
        new = MakeNewNode(data);
        root = new;
        tail = new;
        cur = new;
        return new;
    }
    else{
        node *new;
        new = MakeNewNode(data);
        root->prev = new;
        new->next = root;
        root = new;
        cur = root;
        return new;
    }
}

node* InsertTail(elementtype data){
    if(root == NULL){
        node *new;
        new = MakeNewNode(data);
        root = new;
        tail = new;
        cur = new;
        return new;
    }
    else{
        node *new;
        new = MakeNewNode(data);
        tail->prev = new;
        new->prev = tail;
        tail = new;
        cur = tail;
        return new;
    }
}

void PrintNode(node *node){
    if(node == NULL){
        printf("Pointer is NULL");
        return;
    }
    printf("%s\t\t%s\t\t%s\n",node->element.name,node->element.tel,node->element.email);
}

void ReadTraverseList(){
    if(root == NULL){
        printf("Error");
        return;
    }
    node *p;
    for(p = root;p != NULL; p = p->next){
        PrintNode(p);
    }
}

void ReadReverseList(){
    if(root == NULL){
        printf("Error");
        return;
    }
    if(tail == NULL){
        printf("Error");
        return;
    }
    node *p;
    for(node *p = tail; p != NULL; p = p->prev){
        PrintNode(p);
    }
}

elementtype ReadNode() /*readdata8*/{
    elementtype data;
    printf("Name: ");
    gets(data.name);
    printf("Email: ");
    gets(data.email);
    printf("Tel: ");
    gets(data.tel);
    return data;
}

int main(){
    elementtype a,b,c;
    ReadNode(a);
    ReadNode(b);
    ReadNode(c);
    InsertHead(a);
    InsertHead(b);
    InsertHead(c);
    ReadTraverseList();
    return 0;
}