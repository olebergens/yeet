#include "stdio.h"

//AUFGABE 02 --> BUBBLE-SORT (Bei der Main-Funktion unten die Kommentare wegnehmen, wenn es in die endgültige Datei geht)
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
                // swapping elements -> könnte man auch als Funktion schreiben und benutzen
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/*
int main() {
    int arr[] = {21, 60, 32, 01, 41, 34, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printIntArray(arr, n);
}
 */