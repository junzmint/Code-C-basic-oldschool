typedef struct elementtype {
      char name[20];
      char tel[11];
      char email[25];
}elementtype;
//Tạo struct của từng node trong danh sách
struct node_t
{
    elementtype element;
    struct node_t *next;
};
typedef struct node_t node;
//có 2 trường là giá trị elementtype và con trỏ trỏ đến node tiếp
node *root, *cur, *prev; //tạo các con trỏ: root để trỏ đến phần tử đầu tiên của danh sách, cur để trỏ đến phần tử hiện tại của danh sách, prev để trỏ đến phần tử trước nó

node* MakeNewNode(elementtype data){
    node *new;
    new = (node*)malloc(sizeof(node));
    //strcpy((new->element).name,"Minh Dung");
    new->element = data;
    new->next = NULL;
    return new;
}

node* InsertHead(elementtype data){
    node *head;
    head = MakeNewNode(data);
    head->next = root;//Khi ta tạo 1 node, ta dùng dòng này để khiến con trỏ next chỉ tới node đầu tiên(node root trước đó), xong rồi ta chuyển con trỏ root sang node mới thêm
    root = head;
    cur = root;
    prev = NULL;
}

node* InsertAfterCur(elementtype data){
    node *new_item = MakeNewNode(data);
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

node* InsertBeforeCur(elementtype data){
    node *new_item = MakeNewNode(data);
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

void DeleteAtHead(){
    node *del;
    if(root == NULL){
        printf("List Empty\n");
        return;
    }
    del = root;
    root = del->next;
    cur = root;
    prev = NULL;
    free(del);
}

void DeleteAtCur(){
    if(root == NULL){
        printf("List Empty\n");
        return;
    }
    if(cur == NULL){
        return;
    }
    if(cur == root){
        DeleteAtHead();
    }
    else{
        prev->next = cur->next;//Cập nhật con trỏ prev->next trỏ đến vị trí next của cur hiện tại
        free(cur);
        cur = prev->next;
    }
}

void PrintNode(node *node){
    if(node == NULL){
        printf("Pointer is NULL");
        return;
    }//phải kiếm tra trỏ có null ko đề phòng bị crash
    printf("%s\t\t%s\t\t%s\n",node->element.name,node->element.tel,node->element.email);
}

void TravelList(){
    if(root == NULL){
        printf("There is no data");
        return;
    }
    node *p;
    for(p = root;p != NULL; p = p->next){
        PrintNode(p);
    }
}

node *ReverseList(node* root){
    node *cur, *prev;
    cur = prev = NULL;
    while (root != NULL)
    {
        cur = root;
        root = root->next;
        cur->next = prev;
        prev = cur;
    }
    return prev;
}

void FreeList(){
    node *to_free = root;
    while (to_free != NULL)
    {
        root = root->next;
        free(to_free);
        to_free = root;
    }
    printf("The list is free now\n");    
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


