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
int lengthRec(struct _list *list) {
    if (list == NULL) {
        return l;
    } else {
        l++;
        lengthRec(list->next);
    }
    return 0;
}

int lengthIter(struct _list *list) {
    int count = 0;
    struct _list *current = list;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void findIter(struct _list *list, int d) {
    int count = 0;
    while (list != NULL && list->v != d) {
        list = list->next;
        count++;
    }
    if (list != NULL) printf("%d\n", count);
    else printf("nicht gefunden\n");
}

void findRec(struct _list *list, d) {
    if (list == NULL) {
        printf("nicht gefunden\n");
        findRec(list->next, d);
    }
    if (list->v == d) {
        printf("gefunden\n");
    }
}