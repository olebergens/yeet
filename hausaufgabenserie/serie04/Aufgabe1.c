typedef struct {
    char *chr;
}DATA;

typedef struct {
    struct listElement *next;
    DATA d;
}listElement;

int start(void) {
    FILE *file;
    char line[128];
    listElement *current, *head;

    head = current = NULL;
    file = fopen("/Users/ole/Desktop/Universität Rostock/Imperative Programmierung/ok0579/hausaufgabenserie/serie04/moby-dick.txt", "r");

    while (fgets(line, sizeof(line), file)) {
        listElement *node = malloc(sizeof(listElement));
        node->d.chr = strdup(line);
        node->next = NULL;
        if (head == NULL)
            current = head = node;
        else
            current = current->next = node;
    }
    fclose(file);
    for (current = head; current; current=current->next) {
        printf("%s", current->d.chr);
    }
    return 0;
}
