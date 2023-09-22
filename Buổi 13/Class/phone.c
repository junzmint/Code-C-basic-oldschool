#include <stdio.h>
#define MAX 20
enum{FAIL=0 , SUCCESS=1};
typedef struct phoneaddress_t{
    char name [20];
    char tell[11];
    char email[25];
}phoneaddress;
typedef struct Node{
  phoneaddress key;
  struct Node* Left,Right;
} NodeType;
typedef NodeType* TreeType;
TreeType Search (char* email,TreeType Root){
    if (Root = NULL) return NULL; // not found
    else if (strcmp((Root->key).email, email)==0)
                return Root;
    else if (strcmp ( (Root->key).email, email) < 0)
    //continue searching in the right sub tree
        return Search (email,Root->Right);
    else {
    // continue searching in the left sub tree
    return Search (email,Root->Left);
    }
}
void InsertNode (phoneaddress x,TreeType *Root ) {
    if (*Root == NULL) { 
        *Root= (NodeType*) malloc(sizeof (NodeType)) ;
        (*Root)->key = x;
        (*Root)->Left = NULL;
        (*Root) ->Right = NULL;
    }
    else if (strcmp( ( (*Root) ->key) . email, x.email) > 0)
        InsertNode (x, (*Root) ->Left);
    else if (strcmp( ((*Root)->key).email, x.email)>0)
        InsertNode (x, (*Root)->Right);
}

int main (void)
{
   FILE *fp;
   phoneaddress phonearr[MAX];
   TreeType root;
   int i,n, irc; // return code
   int reval = SUCCESS; 
   int n=10;
  //read from this file to array again
    if ((fp =fopen ("phonebook.dat","rb")) == NULL) { 
        printf("Can not open %s. \n", "phonebook.dat");         
        reval = FAIL; 
    }
    irc = fread (phonearr, sizeof(phoneaddress), n,fp);
    fclose(fp);
    for(i=0; i<n;i++){
       //root= InsertNode(phonearr[i],root);
       InsertNode(phonearr[i],&root);
    }

}