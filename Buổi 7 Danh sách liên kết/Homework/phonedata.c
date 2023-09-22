#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {SUCCESS, FAIL};

typedef struct phonecatalog
{
    char model[20];
    int space;
    char screen[20];
    float size;
    int price;
}phonedb;
int reval = SUCCESS;

struct list_el
{
    phonedb addr;
    struct list_el *next;
};
typedef struct list_el node_addr;

node_addr *root, *cur, *prev;

node_addr* MakeNewNode(phonedb address){
    node_addr *new;
    new = (node_addr*)malloc(sizeof(node_addr));
    //strcpy((new->addr).name,"Minh Dung");
    new->addr = address;
    new->next = NULL;
    return new;
}

node_addr* InsertHead(phonedb address){
    node_addr *head;
    head = MakeNewNode(address);
    head->next = root;//Khi ta tạo 1 node, ta dùng dòng này để khiến con trỏ next chỉ tới node đầu tiên(node root trước đó), xong rồi ta chuyển con trỏ root sang node mới thêm
    root = head;
    cur = root;
}

node_addr* InsertAfterCur(phonedb address){
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

node_addr* InsertBeforeCur(phonedb address){
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
    printf("%s\t%d\t%s\t%f\t%d\n",node->addr.model,node->addr.space,node->addr.screen,node->addr.size,node->addr.price);
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

phonedb readNode() /*readdata8*/{
    phonedb data;
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


int main(){
    int choose;
    int check1 = 0;
    int i = 0;
    int pricephone;
    int count = 0;
    FILE *fptx, *fpdat;
    phonedb *phonebase;
    node_addr *p;
    char model[20];
    while (1==1)
    {
        printf("Choose the number you want\n");
        printf("1.Import from Text\n2.Import from Dat\n3.Display List\n4.Search phone by model\n5.Search phone of which the price is under the value inputted\n6.Export to Dat\n7.Manual Insertion\n8.Exit");
        printf("\nYour choose: ");
        scanf("%d",&choose);fflush(stdin);
        switch (choose)
        {
        case 1:
            if(check1 == 1 || check1 == 2){
                printf("You have imported this file before");
            }
            else{
                if ((fptx = fopen("PhoneDB.txt", "r+")) == NULL){
                    printf("Cannot open file.\n");
                    reval = FAIL;
                }
                else{
                    phonebase = (phonedb*)malloc(20*sizeof(phonedb));
                    while(feof(fptx)==0){
                        fscanf(fptx,"%s\t%d\t%s\t%f\t%d",phonebase[i].model,&phonebase[i].space,phonebase[i].screen,&phonebase[i].size,&phonebase[i].price);
                        InsertHead(phonebase[i]);
                        i++;
                    }
                    check1 = 1;
                    free(phonebase);
                    fclose(fptx);
                }
            }
            break;
        case 2:
            if(check1 != 2){
                printf("Press 1 and then 6 first");
            }
            else{
                if ((fpdat = fopen("PhoneDB.dat", "rb+")) == NULL){
                    printf("Cannot open file.\n");
                    reval = FAIL;
                }
                phonebase = (phonedb*)malloc(20*sizeof(phonedb));
                int j = 0;
                while(fread(phonebase, sizeof(phonedb), 1, fpdat) != 0){
                    InsertAfterCur(phonebase[j]);
                }
                TravelList();
                fclose(fpdat);
                free(phonebase);
            }
            break;
        case 3:
            if(check1 == 0){
                printf("Press 1 first");
            }
            else{
                printf("Model\tSpace\tScreen\tSize\tPrice\n");
                TravelList();
            }
            break;    
        case 4:
            if(check1 == 0){
                printf("Press 1 first");
            }
            else{
                printf("Search model: ");
                gets(model);
                for(p = root;p != NULL; p = p->next){
                    if(strcmp(p->addr.model,model) == 0){
                        printf("Model\tSpace\tScreen\tSize\tPrice\n");
                        printf("%s\t%d\t%s\t%f\t%d\n",p->addr.model,p->addr.space,p->addr.screen,p->addr.size,p->addr.price);
                        break;
                    }
                }
                printf("Done\n");
            }
            break;
        case 5:
            if(check1 == 0){
                printf("Press 1 first");
            }
            else{
                printf("Type the price: ");
                scanf("%d",&pricephone);
                for(p = root;p != NULL; p = p->next){
                    if(p->addr.price <= pricephone){
                        printf("%s\t%d\t%s\t%f\t%d\n",p->addr.model,p->addr.space,p->addr.screen,p->addr.size,p->addr.price);
                    }
                }
                printf("Done\n");
            }
            break;
        case 6:
            if(check1 == 0){
                printf("Press 1 first");
            }
            else{
                if ((fpdat = fopen("PhoneDB.dat", "wb+")) == NULL){
                    printf("Cannot open file.\n");
                    reval = FAIL;
                }
                for(p = root;p != NULL; p = p->next){
                    count += 1;
                }
                phonebase = (phonedb*)malloc(count*sizeof(phonedb));
                int k = 0;
                for(p = root;p != NULL;p = p->next){
                    strcpy(phonebase[k].model, p->addr.model);
                    phonebase[k].space = p->addr.space;
                    strcpy(phonebase[k].screen,p->addr.screen);
                    phonebase[k].size = p->addr.size;
                    phonebase[k].price = p->addr.price;
                }
                fwrite(phonebase,sizeof(phonedb),count,fpdat);
                count = 0;
                check1 = 2;
                printf("Done\n");
                free(phonebase);
                free(fpdat);
            }
            break;
        case 7:
            if(check1 == 0){
                printf("Press 1 first");
            }
            else{
                int choice;
                printf("1.Insert at head\n2.Insert before current\n3.Insert after current\n");
                printf("Your option:");
                scanf("%d",&choice);fflush(stdin);
                phonedb new;
                new = readNode();
                if(choice == 1){
                    InsertHead(new);
                }
                if(choice == 2){
                    InsertBeforeCur(new);
                }
                if(choice == 3){
                    InsertAfterCur(new);
                }
                printf("Done\n");
            }
            break;
        case 8:
            FreeList();
            exit(0);
            break;
        default:
            printf("Invalid\n");
            break;
        }
    }
    return reval;    
}