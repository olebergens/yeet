#include "stdio.h"
#include "praktikum.c"
#include "homework_series02.c"
#include "uebung.c"
#include "homework.c"


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

int main(void) {
    char c1[] = "foo bar baz";
    char c2[] = "foo";
    char c3[] = "bar";
    char c4[] = "baz";
    char c5[] = "gak";
    printf("%d\n", find(c1, 11, c2, 3));
    printf("%d\n", find(c1, 11, c3, 3));
    printf("%d\n", find(c1, 11, c4, 3));
    printf("%d\n", find(c1, 11, c5, 3));
}

