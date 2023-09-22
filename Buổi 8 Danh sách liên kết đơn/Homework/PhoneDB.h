typedef struct elementtype {
    char model[20];
    int space;
    char screen[20];
    float size;
    int price;
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
node *sublist1_root;

node *MakeNewNode(elementtype data){
    node *new;
    new = (node*)malloc(sizeof(node));
    //strcpy((new->element).name,"Minh Dung");
    new->element = data;
    new->next = NULL;
    return new;
}

node *InsertHead(elementtype data){
    node *head;
    head = MakeNewNode(data);
    head->next = root;//Khi ta tạo 1 node, ta dùng dòng này để khiến con trỏ next chỉ tới node đầu tiên(node root trước đó), xong rồi ta chuyển con trỏ root sang node mới thêm
    root = head;
    cur = root;
    prev = NULL;
    return head;
}

node *InsertAfterCur(elementtype data){
    node *new_item = MakeNewNode(data);
    if ( root == NULL ) {
	    root = new_item;
	    cur = root;
        return new_item;
    }
    else if(cur == NULL){
        return 0;
    }
    else{
        new_item->next = cur->next;
        cur->next = new_item;
        prev = cur;
        cur = cur->next;
        return new_item;
    }
}

node *InsertBeforeCur(elementtype data){
    node *new_item = MakeNewNode(data);
    if(root == NULL){
        root = new_item;
        prev = NULL;
        cur = root;
        return new_item;
    }
    else if(cur == NULL){
        return 0;
    }
    else{
        new_item->next = cur;
        if(cur == root){
            root = new_item;
            cur = root; //khi add vào danh sách, con trỏ cur sẽ biến thành node mới đc add
            return new_item;
        }
        else{
            prev->next = new_item;
            cur = new_item;
            return new_item;
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
    printf("%s\t%d\t%s\t%f\t%d\n",node->element.model,node->element.space,node->element.screen,node->element.size,node->element.price);
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

elementtype readNode() /*readdata8*/{
    elementtype data;
    printf("Model: ");
    gets(data.model);fflush(stdin);
    printf("Space: ");
    scanf("%d",&data.space);fflush(stdin);
    printf("Screen: ");
    gets(data.screen);fflush(stdin);
    printf("Size: ");
    scanf("%f",&data.size);fflush(stdin);
    printf("Price: ");
    scanf("%d",&data.price);fflush(stdin);
    return data;
}

int LengthList(){
    node *p;
    int count = 0;
    for(node *p = root; p != NULL; p = p->next){
        count += 1;
    }
    return count;
}

node *insertAtPosition(elementtype data, int n){
    node *new;
    if(root == NULL){
        printf("List empty\n");
        new = InsertHead(data);
        return new;
    }
    else{
        int length_index = (LengthList() - 1);
        if(n < 0){
            printf("Invalid.\n");
            return 0;
        }
        else if(n == 0){
            new = InsertHead(data);
            return new;
        }
        else if(n == 1){
            cur = root;
            prev = NULL;
            new = InsertAfterCur(data);
            return new;
        }
        else if(n > length_index){
            int count = 0;
            node *p;
            for(p = root; p != NULL; p = p->next){
                if(count == length_index - 1){
                    break;
                }
                else{
                    count += 1;
                }
            }
            prev = p;
            cur = prev->next;
            printf("It's out of list index, it will be added at the last of the list.\n");
            new = InsertAfterCur(data);
            return new;
        }
        else{
            int count = 0;
            node *p;
            for(p = root; p != NULL; p = p->next){
                if(count == n - 2){
                    break;
                }
                else{
                    count += 1;
                }
            }
            prev = p;
            cur = prev->next;
            new = InsertAfterCur(data);
            return new;
        }
    }
}

node *deleteAtPosition(int n){
    if(root == NULL){
        printf("List Empty\n");
    }
    if(cur == NULL){
        printf("List Empty\n");
    }
    else{
        int length_index = (LengthList() - 1);
        if(n > length_index){
            printf("Out of range.\n");
        }
        else{
            int count = 0;
            node *p;
            for(p = root; p != NULL; p = p->next){
                if(count == n - 1){
                    break;
                }
                else{
                    count += 1;
                }
            }
            prev = p;
            cur = prev->next;
            DeleteAtCur();
            return root;
        }
    }
}

node *split(int n1, int n2){
    if(root == NULL){
        printf("List empty\n");
    }
    if(cur == NULL){
        return 0;
    }
    if(n1 < 0){
        printf("n1 is wrong syntax\n");
    }
    else{
        int length_index = -1 + LengthList();
        if(n2 > (length_index + 1 - n1)){
            printf("It's out of list index\n");
            return 0;
        }
        else{
            int count = 0;
            if(n1 == 0){
                sublist1_root = root;
                for(node *p = root; p != NULL; p = p->next){
                    count += 1;
                    cur = p;
                    if(count == n2){
                        break;
                    }
                }
                root = cur->next;
                cur = root;
                prev = NULL;
                return sublist1_root;
            }
            else{
                for(node *p = root; p != NULL; p = p->next){
                    cur = p;
                    if(count == n1){
                        break;
                    }
                    else{
                        count += 1;
                    }
                }
                count = 0;
                sublist1_root = cur;
                node *check;
                for(node *p = root; p != NULL; p = p->next){
                    check = p;
                    count += 1;
                    if(count == n1){
                        break;
                    }
                }
                count = 0;
                for(node *p = root; p!= NULL; p =p->next){
                    count += 1;
                    cur = p;
                    if(count == n1+n2+1){
                        break;
                    }
                }
                count = 0;
                check->next = cur;
                cur = root;
                return sublist1_root;
                
            }
        }
    }
}

void PrintFileTxt(FILE *fp){
    if ((fp = fopen("PhoneDB2.txt", "w+")) == NULL){
        printf("Cannot open file.\n");
        return;
    }
    for(node *node = root; node != NULL; node = node->next){
        fprintf(fp,"%s\t%d\t%s\t%f\t%d\n",node->element.model,node->element.space,node->element.screen,node->element.size,node->element.price);
    }
}

void PrintFileDat(FILE *fp){
    if ((fp = fopen("PhoneDB2.dat", "wb+")) == NULL){
        printf("Cannot open file.\n");
        return;
    }
    elementtype *arr;
    arr = (elementtype*)malloc(LengthList()*sizeof(elementtype));
    node *p = root;
    for(int i = 0; i < LengthList(); i++){
        arr[i] = p->element;
        p = p->next;
        if(p == NULL){
            break;
        }
    }
    fwrite(arr,sizeof(elementtype),LengthList(),fp);
    return;
}