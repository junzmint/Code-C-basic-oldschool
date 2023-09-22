#define B 10
typedef int KeyType;

typedef struct Node_el{
    KeyType key;
    struct Node_el *next;
}Node;
typedef Node* Position;
typedef Position Dict[B];
Dict D;

void Initialize(){
    for(int i = 0; i < B; i++){
        D[i] = NULL;
    }
}

int Search(KeyType x){
    Position P;
    int Found = 0;
    P = D[x % B];
    while ((P != NULL) && (!Found))
    {
        if(P->key == x) Found = 1;
        else P = P->next;
    }
    return Found;
}

void InsertSet(KeyType x){
    int bucket;
    Position P;
    if(!Search(x)){
        bucket = x % 10;
        P = D[bucket];
        D[bucket] = (Node*)malloc(sizeof(Node));
        D[bucket]->key = x;
        D[bucket]->next = P;
    }
}

void Delete(KeyType x){
    int bucket,done;
    Position P,Q;
    bucket = x % 10;
    if(D[bucket] != NULL){
        if(D[bucket]->key == x){
            Q = D[bucket];
            D[bucket] = D[bucket]->next;
            free(Q);
        }
        else{
            done = 0;
            P = D[bucket];
            while ((P->next != NULL) && (!done))
            {
                if(P->next->key == x){
                    done = 1;
                }
                else P = P->next;
            }
            if (done)
            {
                Q = P->next;
                P->next = Q->next;
                free(Q);
            }
        }
    }
}

int EmptyBucket(int b){
    return (D[b] == NULL ? 1:0);
}

int EmptyTable(){
    for(int i = 0; i < B; i++){
        if(D[i] != NULL) return 0;
    }
    return 1;
}

void ClearBucket(int b){
    Position P,Q;
    Q = NULL;
    P = D[b];
    while(P != NULL){
        Q = P;
        P = P->next;
        free(Q);
    }
    D[b] = NULL;
}

void ClearHashTable(){
    for(int i = 0; i < B; i++){
        ClearBucket(i);
    }
}

void TraverseBucket(int b){
    Position p;
    p = D[b];
    while(p != NULL){
        printf("%3d ",p->key);
        p = p->next;
    }
}

void TraverseTable(){
    for(int i = 0; i < B; i++){
        printf("Bucket %d: ",i);
        TraverseBucket(i);
        printf("\n");
    }
}