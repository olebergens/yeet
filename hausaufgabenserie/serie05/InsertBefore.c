#include "List.h"

/**
 * @param v : Value, welches in die Liste eingefügt werden soll
 * @param vv : Value, wo die Value danach eingefügt werden soll
 * @param l : Liste, in die die Value eingefügt werden soll
 *
 * Wir gehen durch die Liste durch und schauen, ob ein Element in der Liste ist, welches gleich vv ist.
 * Ist dies der Fall, so fügen wir einfach vor vv die Value v ein.
 */
void insertBefore(Value v, Value vv, List *l) {
    List newList = malloc(sizeof(List));
    List temp = *l;
    if (newList == NULL) {
        printf("Kann das Element nicht in die Liste einfügen.");
        return;
    }
    newList->val = v;
    if ((*l)->val == vv) {
        newList->next = *l;
        *l = newList;
        return;
    }

    while (temp && temp->next) {
        if (temp->next->val == vv) {
            newList->next = temp->next;
            temp->next = newList;
            return;
        }
        temp = temp->next;
    }
}
/**
 * insertBefore(v, v', l): Füge neues Element mit dem Wert v vor dem ersten Element mit Wert v' in der Liste l ein.
 * Sie haben an mindestens einer Stelle die Wahl zwischen zwei Alternativen für das Ergebnis von insertBefore(v, v', l).
 * Begründen Sie Ihre Auswahl.
 *
 * Die zwei Möglichkeiten, welche wir haben, die Funktion zu realisieren sind folgende:
 *      1. wenn v schon in der Liste existiert, dann versetzen wir v einfach vor v' -> somit wird nur l "neu angeordnet" und nicht direkt eine neue Value hinzugefügt
 *      2. wir setzen v vor v' auch wenn v schon in der Liste existieren sollte
 * Wichtig zu wissen ist noch, dass wenn v' NULL sein sollte, ich v vor NULL setzen werde.
 * Ich Entscheide mich für Möglichkeit Nummer 2, da diese um ehrlich zu sein viel einfacher zu implementieren ist. :/
 */
int main(void) {
    List firstList = insert(5, insert(4, insert(3, insert(2, insert(1, insert(0, init()))))));
    printf("--- Liste ---\n");
    showList(firstList);

    printf("--- Liste nach dem einfügen ---\n");
    insertBefore(5, 5, &firstList);
    showList(firstList);

}