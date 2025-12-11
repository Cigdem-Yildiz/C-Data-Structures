#include <stdio.h>
#include <stdlib.h>
#include "node_lib1.h"

NODE *head = NULL;

int main()
{
    int num, num2, num3, num4, num5;

    printf("Enter an int(insertToEnd): ");
    scanf("%d", &num);

    NODE *temp = createNode(&num);
    insertToEnd(&head, temp);
    printf("n1 data: %d\n", *(int *)(temp->dataPtr));

    head = insertToStart(head, temp);
    printf("head ile n1 data: %d\n\n", *(int *)(head->dataPtr));

    printf("Enter an int(insertToStart): ");
    scanf("%d", &num2);

    temp = createNode(&num2);
    printf("n2 data: %d\n\n", *(int *)(temp->dataPtr));
    head = insertToStart(head, temp);
    printf("head ile 1. data: %d\n", *(int *)(head->dataPtr));
    printf("head ile 2. data: %d\n\n", *(int *)(head->link->dataPtr));

    printf("Enter an int(insertToStart): ");
    scanf("%d", &num3);
    temp = createNode(&num3);
    head = insertToStart(head, temp);

    printf("\n3. node: %d\n\n", *(int *)(head->link->link->dataPtr));
    printf("ilk uc eleman: ");
    temp = head;
    while (1)
    {
        printf("%d ", *(int *)(temp->dataPtr));
        if (temp->link == NULL)
            break;
        temp = temp->link;
    }

    printf("\nEnter an int(insertToNth): ");
    scanf("%d", &num4);

    temp = createNode(&num4);
    insertToNth(head, temp, 3);
    printf("3. siraya eklendi");

    printf("\nEnter an int(insertToEnd): ");
    scanf("%d", &num5);

    temp = createNode(&num5);
    insertToEnd(&head, temp);

    temp = head;
    if (temp->link->link->link->link == NULL)
        printf("\nNULL\n");
    else
        printf("DEGIL\n\n");

    printf("\n\nLinked List Elemanlari: ");
    while (1)
    {
        printf("%d ", *(int *)(temp->dataPtr));
        if (temp->link == NULL)
            break;
        temp = temp->link;
    }

    return 0;
}
