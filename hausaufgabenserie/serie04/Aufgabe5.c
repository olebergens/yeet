#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/**
 * Ich nehme hier bei der Aufgabe auch wieder an, dass ich eine Textdatei mit Integer-Zahlen einlese und diese dann sortiert ausgebe.
 */
typedef struct integerList{
    int i;
    struct integerList *next;
}IntegerList;

/**
 *
 * @param list : unsortierte Liste welche übergeben wird -> ich sortiere vom kleinsten zum größten -> 1 .. n
 * @return sortierte liste
 */
IntegerList *sort(IntegerList *list) {
    if (list == NULL || list->next == NULL) return NULL;
    // setze mehrere Variablen um immer Zugriff drauf zu haben, was mal das größte war, welches zur Zeit das größte ist etc..
    IntegerList *current = list, *largest = list, *prev = list, *prevLargest = list;
    // solange wir nicht am Ende der Liste angelangt sind
    while (current != NULL) {
        // wenn der jetzige Wert kleiner als der größte Wert swapping like hell
        if (current->i < largest->i) {
            prevLargest = prev;
            largest = current;
        }
        prev = current;
        current = current->next;
    }

    IntegerList *tempIntegerList;

    // swap
    if (largest != list) {
        prevLargest->next = list;
        tempIntegerList = list->next;
        list->next = largest->next;
        largest->next = tempIntegerList;
    }

    largest->next = sort(largest->next);
    return largest;
}


int start(void) {
    FILE *file;
    char line[128];
    IntegerList *current, *head;

    head = current = NULL;

    // FILE Path so ändern, dass die File genommen wird, welche gemeint ist -> hardcoded weil ich als Beispiel die Moby-Dick.txt in die IDE geladen habe um die zu benutzen
    file = fopen("/Users/ole/Desktop/Universität Rostock/Imperative Programmierung/ok0579/hausaufgabenserie/serie04/Zahlenspass.txt", "r");

    while (fgets(line, sizeof(line), file)) {
        IntegerList *node = malloc(sizeof(IntegerList));
        node->i = atoi(line);
        node->next = NULL;
        if (head == NULL) current = head = node;
        else current = current->next = node;
    }

    fclose(file);

    /**
     * Hier wird eine Schleife durchlaufen, welches jedes Element aus der Liste ausgibt.
     */
    head = sort(head);
    for (current = head; current; current=current->next) {
        printf("%d\n", current->i);
    }
    return 0;
}