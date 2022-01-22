#include "List.h"

/**
 * @param v : Value, welche aus der Liste entfernt werden soll
 * @param l : Liste, aus welcher die Value entfernt werden soll
 * @return List : Liste ohne die Value
 */
void deleteAll(Value v, List *l) {
    while (*l != NULL && (*l)->val == v) *l = (*l)->next;
    List pointer = *l;
    while (pointer != NULL && pointer->next != NULL) {
        if (pointer->next->val == v) {
            List temp = pointer->next;
            while (temp != NULL && temp->val == v)
                temp = temp->next;
            pointer->next = temp;
        }
        pointer = pointer->next;
    }
}

/**
 * deleteAll(v,l): Lösche alle Elemente mit dem Wert v aus der Liste l
 */
int main(void) {
    List firstList = insert(4, insert(4, insert(3, insert(2, insert(1, insert(0, init()))))));

    printf("--- Liste ---\n");
    showList(firstList);

    printf("--- After deletion ---\n");
    deleteAll(4, &firstList);
    showList(firstList);
}