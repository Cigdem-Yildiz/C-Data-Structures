typedef struct node
{
    void *dataPtr;
    struct node *link;
} NODE;

NODE *createNode(void *itemPtr)
{
    NODE *nodePtr = (NODE *)malloc(sizeof(NODE));
    nodePtr->dataPtr = itemPtr;
    nodePtr->link = NULL;

    return nodePtr;
}

NODE *insertToStart(NODE *head, NODE *node)
{
    node->link = head;
    head = node;

    return head;
}

void insertToNth(NODE *head, NODE *node, int n)
{
    NODE *temp = head;
    for (int i = 2; i < n; i++)
        temp = temp->link;
    node->link = temp->link;
    temp->link = node;
}

void insertToEnd(NODE **head, NODE *node)
{
    NODE **ite = head;
    while (*ite != NULL)
        ite = &(*ite)->link;
    *ite = node;
}