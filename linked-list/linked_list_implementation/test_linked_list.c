#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "linked_list.h"

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

int free_data(void *arg)
{
}

void print_list(LList *list)
{
    Node *pTemp = list->head;
    while (pTemp != NULL)
    {
        int *data = (int *)pTemp->dataPtr;

        printf("[%d] -> ", *data);

        pTemp = pTemp->next;
    }
    printf("NULL\n");
}

int main()
{
    LList *list = create_list(free_data);

    int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5;
    void *pa = &a, *pb = &b, *pc = &c, *pd = &d, *pe = &e, *pf = &f;
    append(list, pa, 0);
    append(list, pb, 0);
    append(list, pc, 0);
    append(list, pd, 0);
    append(list, pe, 0);

    print_list(list);

    delete_node(list, pd);
    delete_node(list, pa);

    print_list(list);

    append(list, pa, 1);

    print_list(list);

    Node *pOut;
    printf(search_list(list, pf, &pOut) ? "True\n" : "False\n");

    bool is_reversed = reverse_list(list);

    printf(is_reversed ? "True\n" : "False\n");

    print_list(list);

    delete_first_node(list);
    print_list(list);

    return 0;
}