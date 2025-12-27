#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void delete(void *data)
{
    return;
}

void print(Stack *stack)
{
    printf("Stack elements: ");
    for (int i = 0; i < stack->array->size; i++)
    {
        printf("%d ", *(int *)(stack->array->data[i]));
    }
    printf("\n");
}
int main()
{
    Stack *stack = createStack(delete);

    int x = 7, y = 11, z = 93;
    void *value1 = &x, *value2 = &y, *value3 = &z;

    push(stack, value1);
    push(stack, value2);
    push(stack, value3);
    printf("Top: %d\n", *(int *)(top(stack)));

    pop(stack);
    pop(stack);
    printf("Top: %d\n", *(int *)(top(stack)));

    push(stack, value3);
    push(stack, value2);
    print(stack);

    destroyStack(stack);

    return 0;
}