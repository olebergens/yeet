#include "List.h"

/**
 * @param v : Value, welches in die Liste eingefügt werden soll
 * @param vv : Value, bevor die Value in die Liste eingefügt werden soll
 * @param l : Liste, in die die Value eingefügt werden soll
 *
 */
void insertAfter(Value v, Value vv, List *l) {
    List newList = malloc(sizeof(List));
    List temp = *l;
    while (temp) {
        if (temp->val == vv) {
            if (newList == NULL) printf("Kann das Element nicht in die Liste einfügen.");
            newList->val = v;
            newList->next = temp->next;
            temp->next = newList;
            return;
        }
        temp = temp->next;
    }
}

int main(void) {
    List firstList = insert(5, insert(4, insert(3, insert(2, insert(1, insert(0, init()))))));
    printf("--- Liste ---\n");
    showList(firstList);

    printf("--- Liste nach dem einfügen ---\n");
    insertAfter(2, 5, &firstList);
    showList(firstList);
}