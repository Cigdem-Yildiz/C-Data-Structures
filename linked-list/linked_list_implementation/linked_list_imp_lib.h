#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE
{
    void *dataPtr;
    struct NODE *next;
} NODE;

typedef struct LinkedList
{
    NODE *head;
    int count;
    int (*compare)(void *arg1, void *arg2);
    int (*deconstructor)();
} LList;

LList *createList(int (*compare)(void *arg1, void *arg2), int (*deconstructor)())
{
    LList *list = (LList *)malloc(sizeof(LList));
    if (!list)
        return 0;

    list->count = 0;
    list->head = NULL;
    list->compare = compare;
    list->deconstructor = deconstructor;
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

bool _search(LList *list, void *arg, NODE **preOut, NODE **curOut)
{
    if (!list || list->count == 0)
    {
        return false;
    }

    NODE *pPre = NULL;
    NODE *pLoc = list->head;

    while (pLoc)
    {
        if (pLoc->dataPtr == arg)
        {
            preOut = &pPre;
            curOut = &pLoc;

            return true;
        }

        pPre = pLoc;
        pLoc = pLoc->next;
    }

    *curOut = *preOut = NULL;

    return false;
}

bool searchList(LList *list, void *arg, NODE **outNode)
{
    NODE **pPre;
    bool found = _search(list, arg, pPre, outNode);

    if (!found)
        return false;

    return true;
}

bool _delete(NODE **pPre, NODE **pLoc)
{
    if (!(*pLoc)->next)
    {
        (*pPre)->next = NULL;
        return true;
    }
    (*pPre)->next = (*pLoc)->next;
    return true;
}

bool deleteNode(LList *list, void *arg)
{
    NODE **pPre = NULL, **pLoc = NULL;

    bool found = _search(list, arg, pPre, pLoc);

    if (!found || !_delete(pPre, pLoc))
        return false;

    return true;
}
