typedef struct Node
{
    void *dataPtr;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    int count;
    int (*compare)(void *arg1, void *arg2);
    int (*deconstructor)(void *);
} LList;

LList *create_list(int (*compare)(void *, void *), int (*deconstructor)(void *)){}
Node *append(LList *, void *, int ){}
bool _search(LList *, void *, Node **, Node **){}
bool search_list(LList *, void *, Node **){}
bool _delete(LList *, Node **, Node **){}
bool delete_node(LList *, void *){}
bool destroy_list(LList *){}
bool is_empty(LList *){}
int list_count(LList *){}
bool reverse_list(LList *){}