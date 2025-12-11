#include <stdlib.h>
#include <stdio.h>
#include "linked_list_imp_lib.h"

int compareInt(void *arg1, void *arg2)
{
    if (*(int *)arg1 > *(int *)arg2)
        return 1;
    else if (*(int *)arg1 == *(int *)arg2)
        return 0;
    else
        return -1;
}

int main()
{
    int num1 = 7, num2 = 9, num3 = 5, num4 = 60, num5 = 89;
    LList *list = createList(compareInt);
    printf("count: %d\n", list->count);
    append(list, (void *)&num1, 0);
    append(list, (void *)&num2, 0);
    append(list, (void *)&num3, 1);
    append(list, (void *)&num4, list->count);
    append(list, (void *)&num5, 0);

    NODE *temp = list->head;
    printf("List elements: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(int *)temp->dataPtr);
        temp = temp->next;
    }
    printf("deneme: %x %x", (list->head)->dataPtr, (*list->head).dataPtr);
    printf("\ncompare result: %d", compareInt((void *)&num1, (void *)&num2));

    return 0;
}