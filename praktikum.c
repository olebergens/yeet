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
                printf(" %d^%d * ", temp, pot);
            else printf("%d *", temp);
            temp = out[i];
            pot = 1;
        } else {
            pot++;
        }
    }
    printf("%d", temp);
}