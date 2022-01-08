#include "stdlib.h"
#include "time.h"

int choice(int n) {
    return rand() % n;
}

void constant() {
    if (choice(2)) printf("1");
    else printf("0");
}

void expression() {
    int c = choice(3);
    if (c == 0) variable();
    else if (c == 1) constant();
    else {
        expression();
        printf(" + ");
        expression();
    }
}