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

void printIter(struct _list *list) {
    while (list != NULL) {
        printf("value: %d\n", list->v);
        list = list->next;
    }
}

void printRec(struct _list *list) {
    if (list != NULL) {
        printf("value: %d\n", list->v);
        printRec(list->next);
    }
}

int l = 0;
int lengthIter(struct _list *list) {
    if (list == NULL) return l;
    else {
        l++;
        lengthIter(list->next);
    }
}