struct _list {
    struct _list *next;
    int v;
};

struct _list *linsert(int v, struct _list *list) {
    struct _list *new_list;
    new_list = (struct _list*) malloc(sizeof(struct _list));
    new_list->v = v;
    new_list->next = list;
    list = new_list;
    return list;
}

void printIter()