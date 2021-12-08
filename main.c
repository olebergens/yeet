#include "stdio.h"
#include "praktikum.c"
#include "homework_series02.c"
#include "uebung.c"
#include "homework.c"
#include "string.h"
#include "homework_series3.c"

int main(int argc, char *argv[]) {
    int n;
    if (argc < 2 || (n = atoi(argv[1])) < 0) {
        printf("Usage: %s <number-of-disks>\n", argv[0]);
        return -1;
    }

    heapAlgorithm(generateAlphabet(n), n, n);
    printf("%d permutations", countPerm - 1);
    return 0;
}

