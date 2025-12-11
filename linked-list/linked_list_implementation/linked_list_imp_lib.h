#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    void *dataPtr;
    struct Node *next;
} NODE;

typedef struct LinkedList
{
    NODE *head;
    int count;
    int (*compare)(void *arg1, void *arg2);
    int (*deconstructor)();
} LList;

LList *createList(int (*compare)(void *arg1, void *arg2))
{
    LList *list = (LList *)malloc(sizeof(LList));
    if (!list)
        return 0;

    list->count = 0;
    list->head = NULL;
    list->compare = compare;
    // list->deconstructor = deconstructor;
    return list;
}

NODE *append(LList *list, void *data, int index)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    if (!list || !node || index > list->count || index < 0)
        return 0;
    node->dataPtr = data;

    NODE **ite = &list->head;

    for (int i = 0; i < index; i++)
    {
        ite = &((*ite)->next);
    }

    node->next = *ite;
    *ite = node;

    list->count++;

    return node;
}

int deleteNode(LList *list, void *arg)
{
    return 0;
}

bool _search(LList *list, NODE **preN, NODE **locN, void *arg)
{
    if (!list || list->count == 0)
    {
        return false;
    }
}