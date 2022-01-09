typedef struct {
    char *chr;
}DATA;

typedef struct {
    struct listElement *next;
    DATA d;
}listElement;

/**
 * @param pListElement : Eingegebene Liste, welche reversed werden soll.
 * Reversed wird die Liste per einfachem swapping der Elemente.
 */
void reverseLinkedList(listElement** pListElement) {
    listElement *prev = NULL;
    listElement *current = *pListElement;
    listElement *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *pListElement = prev;
}

/**
 * start-methode -> wird in der Main-Funktion aufgerufen --> Bei Abgabe bitte in int main(void) ändern damit es zu keinen Schwierigkeiten kommt
 * -> hab ich so weil ich die Hausaufgaben in einem Gesamtprojekt schreibe und nicht für jede Hausaufgabenserie ein neues Projekt aufmache
 */
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
        if (head == NULL) current = head = node;
        else current = current->next = node;
    }

    fclose(file);
    /**
     * Wir reversen hier die Liste mit der Funktion um eine verkettete Liste umzudrehen
     */
    reverseLinkedList(&head);
    /**
     * Hier wird eine Schleife durchlaufen, welches jedes Element aus der Liste ausgibt.
     */
    for (current = head; current; current=current->next) {
        printf("%s", current->d.chr);
    }
    return 0;
}
