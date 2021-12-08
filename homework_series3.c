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

int countPerm = 1;
void printArray(char *arr, int permutation) {
    printf("%d: ", countPerm);
    for (int i = 0; i < permutation; i++) {
        printf("%c", arr[i]);
    }
    countPerm++;
    printf("\n");
}

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
