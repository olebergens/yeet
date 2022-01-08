typedef struct {
    char *chr;
}DATA;

typedef struct {
    struct listElement *next;
    DATA d;
}listElement;

void showList(listElement* start) {
    if (start != NULL){
        listElement  *p = start;
        printf("%s", p->d.chr);
        while (p->next != NULL) {
            p = p->next;
            printf("%s", p->d.chr);
        }
    } else  {
        printf("Die List ist leer!\n");
    }
}

int appendElement(listElement** start, const DATA* dInp) {
    listElement *newElement = (listElement*) malloc(sizeof(listElement));
    if (newElement != NULL) {
        newElement->d.chr = dInp->chr;
        newElement->next = NULL;
        if (*start == NULL) {
            *start = newElement;
        } else {
            listElement *n = *start;
            while (n->next != NULL) n = n->next;
            n->next = newElement;
        }
        return 0;
    }
    return -1;
}

int start(void) {
    listElement * start = NULL;
    DATA myD;
    myD.chr = "Hallo\n";
    appendElement(&start, &myD);
    myD.chr = "Welt\n";
    appendElement(&start, &myD);
    myD.chr = "!";
    appendElement(&start, &myD);
    showList(start);
    return 0;
}