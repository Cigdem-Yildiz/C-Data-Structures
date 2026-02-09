#include "stack.h"
#include <stdlib.h>

Stack *createStack(int (*deconstructor)(void *))
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    if (!stack)
        return NULL;

    LList *list = create_list(deconstructor);

    if (!list)
        return NULL;

    stack->list = list;

    stack->top = stack->list->head;

    return stack;
}
int pop(Stack *stack)
{
    if (!stack)
        return 0;
    if (!stack->top)
        return 0;

    if (!delete_first_node(stack->list))
        return 0;

    return 1;
}
int push(Stack *stack, void *pArg)
{
    if (!stack)
        return 0;

    if (!append(stack->list, pArg, 0))
        return 0;

    stack->top++;

    return 1;
}
void *top(Stack *stack)
{
    if (!stack)
        return NULL;

    if (!stack->top)
        return NULL;

    return stack->list->head->dataPtr;
}
int destroyStack(Stack *stack)
{
    if (!stack)
        return 0;
    if (stack->top)
    {
        free(stack);
        return 1;
    }

    if (!destroy_list(stack->list))
        return false;
    free(stack);

    return true;
}