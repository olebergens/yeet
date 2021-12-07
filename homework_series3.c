#include "stdio.h"

char* generateAlphabet(int amount) {
    static char alphabet[26];
    int count = 0;
    for (char c = 'A'; c <= 'A' + amount - 1; c++) {
        alphabet[count] = c;
        count++;
    }
    return alphabet;
}
void printArray(char *arr, int permutation) {
    for (int i = 0; i < permutation; i++)
        printf("%c", arr[i]);
    printf("\n");
}

void swap(char p[], char q[]) {
    char temp = *p;
    *p = *q;
    *q = temp;
}

void heapAlgorithm(char* alphabet, int size) {
    if (size == 1) {
        printArray(alphabet, size);
        return;
    } else {

        for (int i = 0; i < size - 1; i++) {
            if (size % 2 == 1) swap(&alphabet[0], &alphabet[size - 1]);
            else swap(&alphabet[i], &alphabet[size - 1]);
            heapAlgorithm(alphabet, size - 1);
        }

        for (int i = 0; i < size; i++) printf("%c", alphabet[i]);
    }
}
