#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int free_stack(void *) {}

void print_stack(Stack *stack)
{
    Node *pTemp = stack->list->head;
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

    Stack *stack = createStack(free_stack);

    int a = 0, b = 1, c = 2, d = 3, e = 4;
    void *pa = &a, *pb = &b, *pc = &c, *pd = &d, *pe = &e;
    if (stack == NULL)
        return 1;

    push(stack, pa);
    push(stack, pb);
    push(stack, pc);
    push(stack, pd);
    push(stack, pe);

    print_stack(stack);
    int *top_value = (int *)top(stack);

    if (top_value == NULL)
        printf("null\n");

    printf("Stack top: %d\n", *top_value);
    printf("Stack count: %d\n", stack->list->count);

    printf(destroyStack(stack) ? "True\n" : "False\n");
    print_stack(stack);
    printf(stack == NULL ? "Empty\n" : "Full\n");

    return 0;
}