#include "stdio.h"
#include "string.h"

int max2(int a, int b) {
    return a >= b ? a : b;
}

int max4(int a, int b, int c, int d) {
    return max2(a, b) > max2(c, d) ? max2(a, b) : max2(c, d);
}
/**
    * (i > 1 && i % i == 0 [true])
    */
int isPrime(int p) {
    int s = 1;
    for (int i = 2; i < p; i++) {
        if (p % i != 0) s = 0;
        else s = 1;
    }
    return s;
 }



int find(char first[], int lengthFirst, char second[], int lengthSecond) {
    int j, e, p;
    if (lengthSecond > lengthFirst) return -1;
    for (int i = 0; i <= lengthFirst - lengthSecond; i++) {
        p = e = i;
        for (j = 0; j < lengthSecond; j++) {
            if (second[j] == first[e]) e++;
            else break;
        }
        if (j == lengthSecond) return p;
    }
    return -1;
}

int read_int() {
    int c, e;
    while ((c = getchar() - '0') != ' ' - '0' && c != '\n' - '0') {
        e = 10*e+c;
    }
    return e;
}

void reverse() {
    char mystrg[60];
    int length, g;
    scanf("%s", mystrg);
    length = strlen(mystrg);
    for (g = length - 1; g >= 0; g--) {
        printf("%c", mystrg[g]);
    }
}