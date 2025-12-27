#include <stdlib.h>
#include "dynamic_array.h"

DynamicArr *createArray(Deconstructor deconstructor)
{
    DynamicArr *arr = malloc(sizeof(DynamicArr));
    if (!arr)
        return NULL;
    arr->size = 0;
    arr->capasity = 4;
    arr->deconstructor = deconstructor;
    arr->data = malloc(sizeof(void *) * arr->capasity);
    if (!arr->data)
    {
        free(arr);
        return NULL;
    }

    return arr;
}

void destroyArray(DynamicArr *arr)
{
    if (!arr)
        return;
    for (int i = 0; i < arr->size; i++)
    {
        void *current_data = arr->data[i];
        if (arr->deconstructor)
            arr->deconstructor(current_data);
    }

    free(arr->data);
    free(arr);
}

static int resizeArray(DynamicArr *arr)
{
    int new_capasity = arr->capasity * 2;
    void **temp = realloc(arr->data, sizeof(void *) * new_capasity);

    if (!temp)
        return 0;

    arr->data = temp;
    arr->capasity = new_capasity;

    return 1;
}

int append(DynamicArr *arr, void *data)
{
    if (arr->size >= arr->capasity)
        if (resizeArray(arr) == 0)
            return 0;

    arr->data[arr->size++] = data;

    return 1;
}

void *get(DynamicArr *arr)
{
    if (!arr)
        return NULL;
    return arr->data[arr->size - 1];
}

void *removeAt(DynamicArr *arr, int index)
{
    if (!arr)
        return NULL;
    if (index < 0 || index >= arr->size)
        return NULL;

    void *value = arr->data[index];

    for (int i = index; i < arr->size - 1; i++)
    {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;

    return value;
}

int isEmpty(DynamicArr *arr)
{
    if (!arr || arr->size == 0)
        return 1;
    return 0;
}