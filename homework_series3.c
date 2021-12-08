#include "stdio.h"

//AUFGABE 01 --> Heap-Algorithm (Bei der Main-Funktion unten die Kommentare wegnehmen wenn es in die endgültige Datei geht)
char* generateAlphabet(int amount) {
    static char alphabet[26];
    int count = 0;
    for (char c = 'A'; c <= 'A' + amount - 1; c++) {
        alphabet[count] = c;
        count++;
    }
    return alphabet;
}

int countPerm = 1;
void printArray(char *arr, int permutation) {
    printf("%d: ", countPerm);
    for (int i = 0; i < permutation; i++) {
        printf("%c", arr[i]);
    }
    countPerm++;
    printf("\n");
}
/**
 * @param alphabet : Array der Eingabe -> Aufgabenstellung sagt
 * @param size
 * @param n
 */
void heapAlgorithm(char* alphabet, int size, int n ) {
    if (size == 1) printArray(alphabet, n);

    for (int i = 0; i < size; i++) {
        heapAlgorithm(alphabet, size - 1, n);
        if (size % 2 == 1) {
            int temp = alphabet[0];
            alphabet[0] = alphabet[size - 1];
            alphabet[size - 1] = temp;
        } else {
            int temp = alphabet[i];
            alphabet[i] = alphabet[size - 1];
            alphabet[size - 1] = temp;
        }
    }
}
/**
 *
int main(int argc, char *argv[]) {
    int n;
    if (argc < 2 || (n = atoi(argv[1])) < 0) {
        printf("Usage: %s <number-of-disks>\n", argv[0]);
        return -1;
    }
    heapAlgorithm(generateAlphabet(n), n, n);
    printf("%d permutations", countPerm - 1);
    return 0;
 */

//AUFGABE 02 --> BUBBLE-SORT (Bei der Main-Funktion unten die Kommentare wegnehmen wenn es in die endgültige Datei geht)
void printIntArray(int arr[], int sizeArr) {
    for (int i = 0; i < sizeArr; i++) printf("%d ", arr[i]);
}
/**
 * Realisierung des Problems über den normalen Bubblesort-Algorithmus
 * Beim Bubblesort Algorithmus wird eine Liste ja eingegeben und durchläuft dann immer paarweise von links nach rechts die Bubblephase.
 *
 * Prinzip: Start mit erster Zahl und vergleicht mit Nachbarn nach Sortierkriterium
 * Sollten beide Elemente nicht in der richtigen Reihenfolge sein werden sie über swap vertauscht.
 * Danach wird das nächste Paar miteinander verglichen und so weiter.
 */
 void bubbleSort(int arr[], int sizeArr) {
    int temp;
    for (int i = 0; i < sizeArr; i++) {
        for (int j = 1; j < sizeArr - i; j++) {
            if (arr[j - 1] > arr[j]) {
                // swapping elements
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
 }

/**
 * int main() {
int arr[] = {21, 60, 32, 01, 41, 34, 5};
int n = sizeof(arr) / sizeof(arr[0]);
bubbleSort(arr, n);
printIntArray(arr, n);
}
 */

