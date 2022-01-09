/**
 * Aufgabenstellung:
 * Schreiben Sie eine Funktion split, die eine Liste destruktiv in zwei Listen gleicher Länge aufteilt. Was machen Sie bei Listen mit ungerader Länge?
 *
 * Um es einfacher zu haben, nehme ich hier auch wieder an, dass es sich um eine Liste mit Integer-Werte handelt.
 * Dadurch ist es einfach diese einfach zu splitten, da ich ja die Liste auch deklarieren muss und es dadurch einfacher wird zu sehen ob die Liste gesplittet ist,
 * als wenn ich die moby-dick-Liste dazu nehme, da diese viel zu groß ist um zu sehen ob es geklappt hat oder es einen Fehler gibt und die gesamte Liste einfach aus-
 * gegeben wurde.
 *
 * Wenn eine Liste mit einer ungeraden Länge gesplitted werden sollte, gebe ich den ersten Wert einfach in die ersten Teil der Liste
 */

typedef struct list{
    int i;
    struct list *next;
}List;

void add(List** head, int data) {
    List *list = (List*) malloc(sizeof(List));
    list->i = data;
    list->next = (*head);
    (*head) = list;
}

void print(List *list) {
    while (list != NULL) {
        printf("%d ", list->i);
        list = list->next;
    }
}
int listLength(List *listInput) {
    int count = 0;
    List *current = listInput;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void split(List *listInput, List **frontList, List **backList) {
    int len = listLength(listInput);
    if (len < 2) {
        *frontList = listInput;
        backList = NULL;
        return;
    }

    List *current = listInput;
    int hCount = (len - 1) / 2;
    for (int i = 0; i < hCount; i++) {
        current = current->next;
    }

    *frontList = listInput;
    *backList = current->next;
    current->next = NULL;
}


void startSplit() {
    List *frontList = NULL;
    List *backList = NULL;
    List *list1 = NULL;

    add(&list1, 1);
    add(&list1, 2);
    add(&list1, 3);
    add(&list1, 4);
    add(&list1, 5);
    add(&list1, 6);
    add(&list1, 7);


    split(list1, &frontList, &backList);
    printf("--- FrontList ---\n");
    print(frontList);
    printf("\n");
    printf("--- BackList ---\n");
    print(backList);
}