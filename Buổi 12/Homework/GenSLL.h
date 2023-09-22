node *makeNewNode(element_type new_element)
{
    node *new;
    new = (node *)malloc(sizeof(node));
    new->element = new_element;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void insertAtHead(element_type new_phone, doublelist *root, doublelist *tail, doublelist *cur)
{
    node *new = makeNewNode(new_phone);
    if (*root == NULL)
    {
        *root = new;
        *cur = *root;
        *tail = *cur;
        return;
    }
    new->next = *root;
    (*root)->prev = new;
    *root = new;
    *cur = *root;
}

void insertAtTail(element_type new_phone, doublelist *root, doublelist *tail, doublelist *cur)
{
    node *new = makeNewNode(new_phone);
    if (*root == NULL)
    {
        *root = new;
        *cur = *root;
        *tail = *cur;
        return;
    }
    if (tail == NULL)
    {
        printf("Tail pointer ERROR!\n");
        return;
    }
    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
}

void insertBeforeCur(element_type new_phone, doublelist *root, doublelist *tail, doublelist *cur)
{
    node *new = makeNewNode(new_phone);
    if ((*root) == NULL)
    {
        (*root) = new;
        (*cur) = (*root);
        (*tail) = (*cur);
    }
    else
    {
        if (*cur == *root)
        {
            insertAtHead(new_phone, root, tail, cur);
        }
        else
        {
            new->next = *cur;
            new->prev = (*cur)->prev;
            (*cur)->prev->next = new;
            (*cur)->prev = new;
            *cur = new;
        }
    }
}

void insertAfterCur(element_type new_addr, doublelist *root, doublelist *tail, doublelist *cur)
{
    if (*root == NULL)
    {
        *root = makeNewNode(new_addr);
        *cur = *root;
        *tail = *cur;
        return;
    }
    else if (*cur == NULL)
    {
        printf("Current pointer ERROR!\n");
        return;
    }
    node *new = makeNewNode(new_addr);
    new->next = (*cur)->next;
    (*cur)->next = new;
    new->prev = *cur;
    *cur = (*cur)->next;
    if ((*cur)->next == NULL)
    {
        *tail = *cur;
    }
}

void seekCurrent(int seekPoint, doublelist *root, doublelist *cur)
{
    node *tmp = *root;
    for (int i = 0; i < seekPoint; i++)
    {
        tmp = tmp->next;
    }
    *cur = tmp;
}

void checkSeekPoint(int seekPoint, int File_length, doublelist *root, doublelist *cur)
{
    while (seekPoint < 0)
    {
        printf("Seek point must be >= 0: ");
        scanf("%d", &seekPoint);
    }
    if (seekPoint >= File_length)
    {
        seekCurrent(File_length - 1, root, cur);
    }
    else
    {
        seekCurrent(seekPoint, root, cur);
    }
}

node *insertAtPosition(elementess new_element, int *File_length, int seekPoint, doublelist *root, doublelist *tail, doublelist *cur)
{
    if (*root == NULL)
    {
        insertAtHead(new_element, root, tail, cur);
        return *root;
    }
    checkSeekPoint(seekPoint, *File_length, root, cur);
    insertAfterCur(new_element, root, tail, cur);
    *File_length += 1;
    return *cur;
}

void deleteAtFirst(int *File_length, doublelist *root, doublelist *cur)
{
    if (*root == NULL)
    {
        printf("There is no element in list!\n");
        return;
    }
    node *tmp = *root;
    *root = (*root)->next;
    (*root)->prev = NULL;
    free(tmp);
    *cur = *root;
    *File_length -= 1;
}

void deleteAtLast(int *File_length, doublelist *tail, doublelist *cur)
{
    if (*tail == NULL)
    {
        printf("Tail pointer ERROR!\n");
        return;
    }
    node *tmp = *tail;
    tmp->prev->next = NULL;
    *tail = (*tail)->prev;
    free(tmp);
    *cur = *tail;
    *File_length -= 1;
}

node *deleteAtPosition(int *File_length, int n, doublelist *root, doublelist *tail, doublelist *cur)
{
    if (*root == NULL)
    {
        printf("There is no element in list!\n");
        return NULL;
    }
    if (n == 0)
    {
        deleteAtFirst(File_length, root, cur);
        return *root;
    }
    if (n == *File_length - 1)
    {
        deleteAtLast(File_length, tail, cur);
        return *root;
    }
    node *tmp = *root;
    for (int i = 0; i < n; i++)
    {
        tmp = tmp->next;
        *cur = tmp;
    }
    (*cur)->prev->next = (*cur)->next;
    (*cur)->next->prev = (*cur)->prev;
    if ((*cur)->next == NULL)
    {
        *cur = (*cur)->prev;
    }
    else
    {
        *cur = (*cur)->next;
    }
    free(tmp);
    *File_length -= 1;
    return *root;
}

void deleteCurrentNode(int *File_length, doublelist *root, doublelist *tail, doublelist *cur)
{
    if (*root == NULL)
    {
        printf("There is no element in list!\n");
        return;
    }
    if (*cur == NULL)
    {
        printf("Current pointers ERROR!\n");
        return;
    }
    if (*cur == *root)
    {
        *root = (*root)->next;
        free(cur);
        (*root)->prev = NULL;
        *cur = *root;
        *File_length -= 1;
        return;
    }
    node *tmp = *cur;
    if (*cur == *tail)
    {
        (*cur)->prev->next = (*cur)->next;
        *tail = (*cur)->prev;
    }
    else
    {
        (*cur)->prev->next = (*cur)->next;
        (*cur)->next->prev = (*cur)->prev;
    }
    free(tmp);
    if ((*cur)->next == NULL)
    {
        *cur = (*cur)->prev;
    }
    else
    {
        *cur = (*cur)->next;
    }
    *File_length -= 1;
}

// void moveToFront(doublelist *root, doublelist *tail, doublelist *cur)
// {
//     node *tmp = *cur;
//     if (*cur == *tail)
//     {   
//         *tail = (*tail)->prev;
//     }
//     while (tmp != NULL)
//     {
//         tmp = (*cur)->prev;
//         (*cur)->prev = (*cur)->prev->prev;
//         tmp->next = (*cur)->next;
//         (*cur)->next = tmp;
//         tmp->prev = *cur;
//         tmp = (*cur)->prev;
//     }
//     *root = *cur;
//     free(tmp);
// }

void moveToFrontver2(doublelist *root, doublelist *tail, doublelist *cur)
{
    node *tmp = *cur;
    element_type elementDB;
    while(tmp->prev != NULL)
    {
        elementDB = tmp->element;
        tmp->element = tmp->prev->element;
        tmp->prev->element = elementDB;
        tmp = tmp->prev;
    }
}

void transpose(doublelist *root, doublelist *tail, doublelist *cur)
{
    node *tmp = *cur;
    element_type elementDB;
    if (tmp->prev != NULL)
    {
        elementDB = tmp->element;
        tmp->element = tmp->prev->element;
        tmp->prev->element = elementDB;
    }
}

void list_reverse(int File_length, doublelist *root, doublelist *tail, doublelist *cur)
{
    int count = 0;
    node *tmp = NULL;
    if (*root == NULL)
    {
        printf("There is no element in list!\n");
        return;
    }
    *tail = *root;
    *cur = *root;
    while (*cur != NULL)
    {
        count++;
        tmp = (*cur)->next;
        (*cur)->next = (*cur)->prev;
        (*cur)->prev = tmp;
        if (count == File_length)
        {
            *root = *cur;
        }
        (*cur) = (*cur)->prev;
    }
}

int storeLinkedList(FILE *file_out, int File_length, doublelist *root)
{
    node *tmp = *root;
    int tracking = 0;
    element_type phoneDBtmp[File_length];
    if (tmp == NULL)
    {
        printf("root pointers ERROR\n");
    }
    while (tmp != NULL)
    {
        phoneDBtmp[tracking] = tmp->element;
        tracking++;
        tmp = tmp->next;
    }
    fwrite(phoneDBtmp, sizeof(element_type), File_length, file_out);
}

void traversingList(doublelist *root, doublelist *cur)
{
    int tracking = 0;
    node *p;
    printf("%-2s%30s\t%17s\t\t%10s\t\t%s\n", "ID", "Phone name", "Memory space", "Screen size (inch)", "Price(Yen)");
    for (p = *root; p != NULL; p = p->next)
    {
        printf("%-2d%35s%20s\t\t\t%s\t\t\t%s\n", tracking + 1, p->element.name, p->element.mem_space, p->element.screen_size, p->element.price);
        tracking++;
        *cur = p;
    }
}

void freeList(doublelist *tmp)
{
    node *to_free = *tmp;
    while (to_free != NULL)
    {
        *tmp = (*tmp)->next;
        free(to_free);
        to_free = *tmp;
    }
}
