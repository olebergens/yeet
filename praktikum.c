#include <stdio.h>
#include "stdlib.h"
#include <math.h>
#include <time.h>

void plot_sin(int indent, char c) {
    for (; indent; --indent) putchar(' ');
    printf("%c", c);
}

void plot_cos(int indent, char c) {
    for (; indent; --indent) putchar(' ');
    printf("%c", c);
}

void plot_cos_sin() {
    double x;
    int indent_sin, indent_cos;
    for (x = -180.0; x <= 180; x+=15) {
        indent_sin = 10 + 10* sin(x / 180.0 * M_PI);
        indent_cos = 10 + 10 * cos(x / 180.0 * M_PI);
        if (indent_sin<indent_cos) plot_sin(indent_sin, '+');
        plot_cos(indent_cos, 'x');
        printf("\n");
        if (indent_sin>indent_cos) plot_cos(indent_cos, 'x');
        plot_sin(indent_sin, '+');
        printf("\n");
        if (indent_sin == indent_cos) plot_sin(indent_sin, '*');
        printf("\n");
    }
}

float getRangeInt(float min, float max) {
    double r = max - min + 1;
    return min + (r * rand() / (RAND_MAX + 1.0));
}
int wzw(int x, int y) {
    return (pow(x, 2) + pow(y, 2)) <= 1 ? 1 : 0;
}

void approx() {
    srand(time(NULL));
    float x, y;
    int p;
    printf("Bitte gib die Anzahl an zu ziehenden Punkten ein: \n");
    fflush(stdout);
    scanf("%d", &p);
    double count_incircle = 0.0;
    for (int i = 0; i <= p; i++) {
        x = getRangeInt(0, 1);
        y = getRangeInt(0, 1);
        if (wzw(x, y) == 1) count_incircle++;
    }
    printf("Approximation pi: %lf", (count_incircle / (double) p) * 4);
}

void primeFactors(long n) {
    printf("%ld = ", n);
    int max = ceil(log10(n) / log10(2));
    long tmp[max];
    int numFactors = 0;

    for (int i = 2; i <= n; i++) {
        // Abfrage: i Primfaktor
        if (n % i == 0) {
            tmp[numFactors++] = i;
            n = n / i;
            i = 1;
        }
    }

    long out[numFactors];
    for (int i = 0; i < numFactors; ++i) out[i] = tmp[i];

    for (int i = 0; i < numFactors; ++i) {
        if (i == numFactors - 1) printf("%ld", out[i]);
        else printf("%ld * ", out[i]);
    }
}

void primeFactorsTwo(long n) {
    printf("%ld = ", n);
    int max = ceil(log10(n) / log10(2));
    long tmp[max];
    int numFactors = 0;
    for (int i = 2; i <= n; ++i) {
        if (n % i == 0) {
            tmp[numFactors++] = i;
            n = n / i;
            i = 1;
        }
    }
    long out[numFactors];

    for (int i = 0; i < numFactors; i++) out[i] = tmp[i];

    long temp = out[0];
    long pot = 1;

    for (int i = 1; i < numFactors; ++i) {
        if (temp != out[i]) {
            if (pot > 1)
                printf(" %ld^%ld * ", temp, pot);
            else printf("%ld *", temp);
            temp = out[i];
            pot = 1;
        } else {
            pot++;
        }
    }
    if (pot > 1) printf("%ld^%ld", temp, pot);
    else printf("%ld", temp);
}


#define MAX 100
void sieve() {
    int prim[MAX + 1];
    for (int i = 0; i <= MAX; i++) prim[i] = 1;

    for (int i = 2; i*i <= MAX; i++) {
        if (prim[i] == 1) {
            for (int j = i*i; j <= MAX; j += i) prim[j] = 0;
        }
    }

    for (int i = 2; i <= MAX; i++) printf("%d ", prim[i]);

    printf("\n");
    for (int i = 2; i <= MAX; i++)
        if (prim[i] == 1) printf("%d ", i);
}

#define TAPE_LENGTH 10
void print_config(int state, int position, int tape[]) {
    printf("Zustand: %d ", state);
    printf("Band: ");
    for (int i = 0; i < TAPE_LENGTH; ++i) {
        if (i == position) printf("[%d] ", tape[i]);
        else printf("%d ", tape[i]);
    }
}

#define STATES 2
#define SYMBOLS 3
void print_definition(int write_symbol[STATES][SYMBOLS], int next_state[STATES][SYMBOLS], int move[STATES][SYMBOLS]) {
    write_symbol[0][0] = 1; next_state[0][0] = 0; move[0][0] = 1;
    write_symbol[0][1] = 0; next_state[0][1] = 0; move[0][1] = 1;
    write_symbol[0][2] = 2; next_state[0][2] = 1; move[0][2] = 0;
    write_symbol[1][0] = 0; next_state[1][0] = 1; move[1][0] = 0;
    write_symbol[1][1] = 1; next_state[1][1] = 1; move[1][1] = 0;
    write_symbol[1][2] = 2; next_state[1][2] = 1; move[1][2] = 0;

    printf("s r | s w m\n");
    int second = 0;
    // erste schleife für second [] [x]<--
    for (int i = 1; i < SYMBOLS + 1; i++) {
        if (second == 0)
            printf("%d %d | %d %d %d \n", 0, i - 1, write_symbol[0][i - 1], next_state[0][i - 1], move[0][i - 1]);
        else if (second == 1) printf("%d %d | %d %d %d \n", 1, i - 1, write_symbol[1][i - 1], next_state[1][i - 1], move[1][i - 1]);

        if (i - 1 == 2){
            second++;
            i = 0;
        }
    }
}

void simulateTuring() {

}