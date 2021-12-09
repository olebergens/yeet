#include "stdio.h"
#include "ctype.h"
#include "praktikum/praktikum.c"
#include "hausaufgabenserie/serie02/homework_series02.c"
#include "uebung/uebung.c"
#include "hausaufgabenserie/serie01/homework.c"
#include "hausaufgabenserie/serie03/Aufgabe01.c"
#include "hausaufgabenserie/serie03/Aufgabe02.c"

#define N 29
#define C_SPACE 26
#define C_COMMA 27
#define C_STOP 28

int getcc() {
    int c, haveSpace = 0;

    while(isspace(c = getchar())) haveSpace = 1;

    if (haveSpace) return (ungetc(c, stdin), C_SPACE);
    else if (c >= 'a' && c <= 'z') return c-'a';
    else if (c >= 'A' && c <= 'Z') return c-'A';
    else if (c == ',') return C_COMMA;
    else if (c == '.') return C_STOP;
    else if (c == EOF) return EOF;
    else return getcc();
}

int main(void) {
    printf("%d", getcc());
}

