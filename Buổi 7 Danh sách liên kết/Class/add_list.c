#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000

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
    else{
        new_item->next = cur->next;
        cur->next = new_item;
        prev = cur;
        cur = cur->next;
    }
}

void PrintNode(node_addr *node){
    if(node == NULL){
        printf("Loi con tro NULL");
        return;
    }//phải kiếm tra trỏ có null ko đề phòng bị crash
    printf("%s\t\t%s\t\t%s\n",node->addr.name,node->addr.tel,node->addr.email);
}

void TravelList(){
    node_addr *p;
    for(p = root;p != NULL; p = p->next){
        PrintNode(p);
    }
}


phoneaddress readNode() /*readdata8*/{
    phoneaddress data;
    printf("Nhap ten: ");
    gets(data.name);
    printf("Nhap email: ");
    gets(data.email);
    printf("Nhap so dien thoai: ");
    gets(data.tel);
    return data;
}




int main(){
    phoneaddress firstnode,secondnode;
    for(int i =0;i < 2; i++){
        secondnode = readNode();
        InsertHead(secondnode);
        PrintNode(root);
    }
    InsertAfterCur(readNode());
    PrintNode(cur);
    printf("In ra list để check node\n");
    TravelList();
    return 0;
}






