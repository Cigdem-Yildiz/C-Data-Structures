#include <stdlib.h>
#include <stdio.h>
#include "linked_list_imp_lib.h"

int compare(void *arg1, void *arg2)
{
    int value1 = *(int *)arg1;
    int value2 = *(int *)arg2;

    if (value1 > value2)
        return 1;
    else if (value1 == value2)
        return 0;
    else
        return -1;
}

int main()
{
    LList *list = createList(compare);

    int a = 0, b = 1, c = 2, d = 3, e = 4;
    void *pa = &a, *pb = &b, *pc = &c, *pd = &d, *pe = &e;
    append(list, pa, 0);
    append(list, pb, 0);
    append(list, pc, 0);
    append(list, pd, 0);
    append(list, pe, 0);

    NODE *temp = list->head;

    while (temp->next != NULL)
    {
        printf("%d ", *(int *)temp->dataPtr);
        temp = temp->next;
    }
    printf("%d ", *(int *)temp->dataPtr);

    bool flag = deleteNode(list, pd);

    if (flag)
        printf("true");
    else
        printf("false");

    return 0;
}