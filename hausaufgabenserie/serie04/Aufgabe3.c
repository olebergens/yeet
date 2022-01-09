/**
 * Aufgabenstellung:
 * Schreiben Sie eine Funktion merge, die zwei sortierte Listen zu einer sortierten Liste zusammenmischt (auch merge darf destruktiv arbeiten)
 *
 * Ich nehme mal an, bei den Listen wird es sich um Listen mit Integer-Werten handeln.
 * Deswegen habe ich die ListInformation mit einer Value geschrieben, die einen Integer-Wert inne hat.
 * Im Grunde aber, sollte der merge-Algorithmus auch mit jeder anderen Liste klarkommen.
 */

typedef struct {
    int i;
    struct DATA *next;
}ListInformation;

ListInformation* merge(ListInformation* data1, ListInformation* data2) {
    if (data1 == NULL) return data2;
    else if (data2 == NULL) return data1;

    ListInformation *mergeHead = NULL;
    if (data1->i <= data2->i) {
        mergeHead = data1;
        data1 = data1->next;
    } else {
        mergeHead = data2;
        data2 = data2->next;
    }

    ListInformation *mergeTail = mergeHead;
    while (data1 != NULL && data2 != NULL) {
        ListInformation *tempListInformation = NULL;
        if (data1->i <= data2->i) {
            tempListInformation = data1;
            data1 = data1->next;
        } else {
            tempListInformation = data2;
            data2 = data2->next;
        }
        mergeTail->next = tempListInformation;
        mergeTail = tempListInformation;
    }

    if (data1 != NULL)mergeTail->next = data1;
    else if (data2 != NULL)mergeTail->next = data2;

    return mergeHead;
}

void addToList(ListInformation** head, int data) {
    ListInformation *listInformation = (ListInformation*) malloc(sizeof(ListInformation));
    listInformation->i = data;
    listInformation->next = (*head);
    (*head) = listInformation;
}

void printList(ListInformation *listInformation) {
    while (listInformation != NULL) {
        printf("%d ", listInformation->i);
        listInformation = listInformation->next;
    }
}

void reverseList(ListInformation **pListInformation) {
    ListInformation *prev = NULL;
    ListInformation *current = *pListInformation;
    ListInformation *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *pListInformation = prev;
}

/**
 * Ich erstelle hier in der Funktion ja die Liste. Dadurch ist die Liste ja erstmal von den Daten her umgedreht und muss erst wieder einmal reversed werden.
 * Sollte man jetzt aber schon zwei sortierte Listen haben, welche nicht mehr umgedreht werden brauchen, so ist dieser Schritt nicht nötig.
 * Es dient jetzt dabei nur, dass die temporär hardcoded Liste umgedreht wird und ich es schnell kontrollieren kann, ob alles funktioniert wie es soll.
 */
int starter(void) {
    ListInformation *result = NULL;
    ListInformation *list1 = NULL;
    ListInformation *list2 = NULL;

    addToList(&list1, 3);
    addToList(&list1, 4);
    addToList(&list1, 5);

    addToList(&list2, 1);
    addToList(&list2, 5);
    addToList(&list2, 8);

    // Beide Listen umdrehen, da die Eingabe ja verkehrt herum läuft!
    reverseList(&list1);
    reverseList(&list2);

    printf("Linked List 1:\n");
    printList(list1);
    printf("\n\n\n");
    printf("Linked List 2:\n");
    printList(list2);
    printf("\n\n\n");
    result = merge(list1, list2);
    printf("Merged List:\n");
    printList(result);
}