#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000
enum{SUCCESS, FAIL};

typedef struct phoneaddress {
      char name[20];
      char tel[11];
      char email[25];
}phoneaddress;
//Tạo struct của từng node trong danh sách
struct list_el
{
    phoneaddress addr;
    struct list_el *next;
};
typedef struct list_el node_addr;
//có 2 trường là giá trị phoneaddress và con trỏ trỏ đến node tiếp
node_addr *root, *cur, *prev; //tạo các con trỏ: root để trỏ đến phần tử đầu tiên của danh sách, cur để trỏ đến phần tử hiện tại của danh sách, prev để trỏ đến phần tử trước nó

node_addr* MakeNewNode(phoneaddress address){
    node_addr *new;
    new = (node_addr*)malloc(sizeof(node_addr));
    //strcpy((new->addr).name,"Minh Dung");
    new->addr = address;
    new->next = NULL;
    return new;
}

node_addr* InsertHead(phoneaddress address){
    node_addr *head;
    head = MakeNewNode(address);
    head->next = root;//Khi ta tạo 1 node, ta dùng dòng này để khiến con trỏ next chỉ tới node đầu tiên(node root trước đó), xong rồi ta chuyển con trỏ root sang node mới thêm
    root = head;
    cur = root;
}

node_addr* InsertAfterCur(phoneaddress address){
    node_addr *new_item = MakeNewNode(address);
    if ( root == NULL ) {
	    root = new_item;
	    cur = root;
    }
    else if(cur == NULL){
        return 0;
    }
    else{
        new_item->next = cur->next;
        cur->next = new_item;
        prev = cur;
        cur = cur->next;
    }
}

node_addr* InsertBeforeCur(phoneaddress address){
    node_addr *new_item = MakeNewNode(address);
    if(root == NULL){
        root = new_item;
        prev = NULL;
        cur = root;
    }
    else if(cur == NULL){
        return 0;
    }
    else{
        new_item->next = cur;
        if(cur == root){
            root = new_item;
            cur = root; //khi add vào danh sách, con trỏ cur sẽ biến thành node mới đc add
        }
        else{
            prev->next = new_item;
            cur = new_item;
        }
    }
}

void PrintNode(node_addr *node){
    if(node == NULL){
        printf("pointer is NULL");
        return;
    }//phải kiếm tra trỏ có null ko đề phòng bị crash
    printf("%s\t\t%s\t\t%s\n",node->addr.name,node->addr.tel,node->addr.email);
}

void TravelList(){
    if(root == NULL){
        printf("There is no data");
        return;
    }
    node_addr *p;
    for(p = root;p != NULL; p = p->next){
        PrintNode(p);
    }
}

void FreeList(){
    node_addr *to_free = root;
    while (to_free != NULL)
    {
        root = root->next;
        free(to_free);
        to_free = root;
    }
    
}


phoneaddress readNode() /*readdata8*/{
    phoneaddress data;
    printf("Name: ");
    gets(data.name);
    printf("Email: ");
    gets(data.email);
    printf("Tel: ");
    gets(data.tel);
    return data;
}




int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: <PROGRAM'S NAME> <FILENAMEREAD>");
        return 1;
    }
    FILE *file;
    int reval = SUCCESS;        
    if ((file = fopen(argv[1], "r")) == NULL){
        printf("Cannot open file 1.\n");
        reval = FAIL;
        return reval;
    }
    fseek(file,0,SEEK_END);
    int length,number;
    length = ftell(file);
    fseek(file,0,SEEK_SET);
    number = length/sizeof(phoneaddress);
    phoneaddress *readfile;
    readfile = (phoneaddress*)malloc(length);
    fread(readfile,length,1,file);
    for(int i = 0; i <= (number-1);i++){
        InsertBeforeCur(readfile[i]);
    }
    printf("Name\t\t\tTel\t\tEmail\n");
    /*
    second_node = InsertAfterCur(readfile[2]);
    third_node = InsertBeforeCur(readfile[3]);
    forth_node = InsertHead(readfile[4]);
    */
    TravelList();
    printf("The root node is:\n");
    PrintNode(root);
    FreeList();
    return 0;
}






