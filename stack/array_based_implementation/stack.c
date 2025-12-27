#include <stdlib.h>
#include "stack.h"

Stack *createStack(Deconstructor deconstructor)
{
    Stack *stack = malloc(sizeof(Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    DynamicArr *arr = createArray(deconstructor);

    if (!arr)
        return NULL;

    stack->array = arr;

    return stack;
}

int pop(Stack *stack)
{
    if (!stack)
    {
        return 0;
    }

    if (stack->top == -1)
        return 0;

    stack->top--;
    stack->array->size--;

    return 1;
}

int push(Stack *stack, void *value)
{
    if (!stack)
        return 0;

    if (!append(stack->array, value))
    {
        return 0;
    }
    stack->top++;

    return 1;
}

void *top(Stack *stack)
{
    if (!stack)
        return NULL;

    if (stack->top == -1)
        return NULL;

    return stack->array->data[stack->top];
}

void destroyStack(Stack *stack)
{
    if (!stack)
        return;

    destroyArray(stack->array);
    free(stack);
}