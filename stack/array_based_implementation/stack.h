#include "../DynamicArray/dynamic_array.h"

typedef struct
{
    int top;
    DynamicArr *array;
} Stack;

Stack *createStack(Deconstructor);
int pop(Stack *);
int push(Stack *, void *);
void *top(Stack *);
void destroyStack(Stack *);