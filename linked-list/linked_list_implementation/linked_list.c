#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

typedef struct Node
{
    void *dataPtr;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    int count;
    // int (*compare)(void *arg1, void *arg2);
    int (*deconstructor)(void *);
} LList;

LList *create_list(int (*deconstructor)(void *))
{
    LList *list = (LList *)malloc(sizeof(LList));
    if (!list)
        return 0;

    list->count = 0;
    list->head = NULL;
    // list->compare = compare;
    list->deconstructor = deconstructor;
    return list;
}

Node *append(LList *list, void *data, int index)
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (!list || !node || index > list->count || index < 0)
        return NULL;

    node->dataPtr = data;

    Node **ite = &list->head;

    for (int i = 0; i < index; i++)
    {
        ite = &((*ite)->next);
    }

    node->next = *ite;
    *ite = node;

    list->count++;

    return node;
}

bool _search(LList *list, void *arg, Node **preOut, Node **curOut)
{
    if (!list || list->count == 0)
    {
        return false;
    }

    Node *pPre = NULL;
    Node *pLoc = list->head;

    while (pLoc)
    {
        if (pLoc->dataPtr == arg)
        {
            *preOut = pPre;
            *curOut = pLoc;

            return true;
        }

        pPre = pLoc;
        pLoc = pLoc->next;
    }

    *curOut = *preOut = NULL;

    return false;
}

bool search_list(LList *list, void *arg, Node **outNode)
{
    Node *tempPre;
    bool found = _search(list, arg, &tempPre, outNode);

    if (!found)
        return false;

    return true;
}

bool _delete(LList *list, Node **pPre, Node **pLoc)
{
    if (!(*pPre))
    {
        list->head = (*pLoc)->next;
        return true;
    }

    (*pPre)->next = (*pLoc)->next;

    return true;
}

bool delete_node(LList *list, void *arg)
{
    Node *pPre, *pLoc;

    bool found = _search(list, arg, &pPre, &pLoc);

    if (!found || !_delete(list, &pPre, &pLoc))
        return false;

    list->count--;

    return true;
}

bool destroy_list(LList *list)
{
}

bool is_empty(LList *list)
{
    if (list)
        return true;
    else
        return false;
}

int list_count(LList *list)
{
    if (is_empty)
        return list->count;
    else
        return 0;
}

bool reverse_list(LList *list)
{
    if (!list)
        return false;

    if (list->count == 0)
    {
        return true;
    }

    Node *pPre = NULL, *pLoc = list->head, *pNext = NULL;

    while (pLoc)
    {
        pNext = pLoc->next;
        pLoc->next = pPre;
        pPre = pLoc;
        pLoc = pNext;
        if (!pLoc)
        {
            list->head = pPre;
            break;
        }
    }

    return true;
}