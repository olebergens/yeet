#include "string.h"
#include "stdio.h"
#include "stdlib.h"

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
 *
 * Komischerweise erlebe ich nicht das angesproche reverse ausgeben wie in der Hausaufgabendatei.
 * Wenn ich die Datei in die Liste speichere und wieder ausgebe, gebe ich die Liste gleich in der richtigen Reihenfolge wieder aus und nicht
 * reversed wie es in Aufgabe 2 steht.
 */

int main(void) {
    FILE *file;
    char line[128];
    listElement *current, *head;

    head = current = NULL;

    // FILE Path so ändern, dass die File genommen wird, welche gemeint ist -> hardcoded weil ich als Beispiel die Moby-Dick.txt in die IDE geladen habe um die zu benutzen
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
