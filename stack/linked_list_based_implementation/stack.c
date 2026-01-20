#include "stack.h"
#include <stdlib.h>

Stack *createStack(int (*deconstructor)(void *))
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    if (!stack)
        return NULL;

    stack->top = stack->list->head;
    LList *list = create_list(deconstructor);

    if (!list)
        return NULL;

    stack->list = list;

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

    return stack->list->head;
}
void destroyStack(Stack *stack)
{
}