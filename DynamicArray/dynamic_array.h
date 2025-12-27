typedef void (*Deconstructor)(void *);

typedef struct
{
    int size;
    int capasity;
    void **data;
    Deconstructor deconstructor;
} DynamicArr;

DynamicArr *createArray(Deconstructor);
void destroyArray(DynamicArr *);
static int resizeArray(DynamicArr *);
int append(DynamicArr *, void *);
void *get(DynamicArr *);
void *removeAt(DynamicArr *, int);
int isEmpty(DynamicArr *);