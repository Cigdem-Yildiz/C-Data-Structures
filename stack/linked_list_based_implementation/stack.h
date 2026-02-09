#include "../../linked-list/linked_list_implementation/linked_list.h"

typedef struct
{
    Node *top;
    LList *list;
} Stack;

Stack *createStack(int (*deconstructor)(void *));
int pop(Stack *);
int push(Stack *, void *);
void *top(Stack *);
int destroyStack(Stack *);