#include "stdio.h"
#include "praktikum.c"
#include "homework_series02.c"
#include "uebung.c"
#include "homework.c"
#include "string.h"

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

int main(void) {
    primeFactors(4200);
}

