#include "List.h"
#include "List.c"

#include "stdio.h"
/**
 * Meine Gedanken zu dieser Aufgabe sehen so aus:
 * Wir dürfen nicht einfach anschauen, ob die beiden Listen so gleich sind ->
 * daraufhin ist ja eine Abfrage in Richtung
 * WENN(List1 == List2) RETURN WAHR
 * ANSONSTEN RETURN FALSE
 * nicht erlaubt.
 * Somit dachte ich, dass wir einfach die Liste durchgehen und schauen ob es die gleichen Werte sind.
 * Also nehme ich eine Schleife beide Listen durchläuft. Somit vergleiche ich dann die beiden Werte.
 * Eine Frage stellt sich mir dabei aber:
 * ist eine Liste, welche nicht sortiert ist gleich zu einer sortierten Liste beispielsweise:
 * List a = {1, 2, 3, 4, 5, 6}
 * List b = {6, 5, 4, 3, 2, 1}
 * ist dies gleich oder nicht? Die Werte der Liste sind ja gleich aber nicht in der gleichen Reihenfolge.
 * Wenn die beiden Listen trotz dessen noch gleich sein sollten, so sortieren wir am beiden einfach beide Listen vor dem check und dann sind die ja in der sortierten
 * Reihenfolge und das Problem ist gelöst. Sollten beide Listen trotz gleicher Werte aber ungleich sein, ist der Schritt des Sortierens unnötig.
 *
 * Tut mir leid, falls ich mir dazu zu viele Gedanken gemacht habe! :)
 */

/**
 * @param list : Liste, welche sortiert werden soll
 * @return list : sortierte Liste
 *
 * Wie ich schon oben geschrieben habe, weiß ich nicht direkt ob dies nötig ist etc.
 * Daraufhin habe ich die Funktion benutzt, welche letzte Woche in der letzten Aufgabe programmiert werden sollte :)
 */
List sort(List list) {
    if (list == NULL || list->next == NULL) return NULL;
    // setze mehrere Variablen um immer Zugriff drauf zu haben, was mal das größte war, welches zur Zeit das größte ist etc..
    List current = list, largest = list, prev = list, prevLargest = list;
    // solange wir nicht am Ende der Liste angelangt sind
    while (current != NULL) {
        // wenn der jetzige Wert kleiner als der größte Wert swapping like hell
        if (current->val < largest->val) {
            prevLargest = prev;
            largest = current;
        }
        prev = current;
        current = current->next;
    }

    List tempIntegerList;

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

/**
 * @param head1 : erste Liste, welche verglichen werden soll
 * @param head2 : zweite Liste, welcher verglichen werden soll
 * @return [
 *      True: wenn die beiden Listen gleich sind
 *      False: wenn die beiden Listen nicht gleich sind
 *      ]
 */
Bool check_equal(List head1, List head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->val != head2->val) return False;
        head1 = head1->next;
        head2 = head2->next;
    }

    if (head1 != NULL) return False;
    if (head2 != NULL) return False;
    return True;
}

/**
 * equal(l,l'). Die Funktion equal soll den Wert True liefern, wenn zwei Listen l und l' gleich sind; ansosnten False. Nehmen Sie dabei an, dass Sie mit
 * Hilfe von "=" (bzw. "!=") nur Werte vom Typ Value auf Gleichheit (bzw. Ungleichheit) überprüfen können.
 */
int main(void) {
    List firstList = insert(5, insert(4, insert(3, insert(2, insert(1, insert(0, init()))))));
    List secondList = insert(0, insert(1, insert(2, insert(3, insert(4, insert(5, init()))))));
    printf("--- Liste 1 ---\n");
    showList(firstList);
    printf("--- Liste 2 ---\n");
    showList(secondList);
    printf("--- Equal (without sorting) ---\n");
    if (check_equal(firstList, secondList) == True) printf("True\n");
    else printf("False\n");

    // jetzt einfach sortieren -> bitte nicht beachten, wenn nicht benötigt
    printf("--- Equal (with sorting) ---\n");
    firstList = sort(firstList);
    secondList = sort(secondList);
    if (check_equal(firstList, secondList) == True) printf("True\n");
    else printf("False\n");

}