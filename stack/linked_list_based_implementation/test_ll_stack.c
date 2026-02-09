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
    printf("[DEBUG] Program baslatildi...\n");

    Stack *stack = createStack(free_stack);

    int a = 0, b = 1, c = 2, d = 3, e = 4;
    void *pa = &a, *pb = &b, *pc = &c, *pd = &d, *pe = &e;
    if (stack == NULL)
    {
        printf("[HATA] Stack olusturulamadi (Bellek hatasi olabilir).\n");
        return 1;
    }
    printf("[DEBUG] Stack basariyla olusturuldu.\n");

    push(stack, pa);
    printf("[DEBUG] pa degeri eklendi.\n");

    push(stack, pb);
    printf("[DEBUG] pb degeri eklendi.\n");

    printf("Stack Top: %d\n", *(int *)top(stack));
    print_stack(stack);

    destroyStack(stack);
    printf("[DEBUG] Stack temizlendi ve program bitti.\n");

    push(stack, pc);
    push(stack, pd);
    push(stack, pe);

    print_stack(stack);

    return 0;
}