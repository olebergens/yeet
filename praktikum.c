//
// Created by Ole Bergens on 17.11.21.
//
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
    int x, y, p;
    double approx;
    printf("Bitte gib die Anzahl an zu ziehenden Punkten ein: \n");
    fflush(stdout);
    scanf("%d", &p);
    float count_incircle = 0;
    for (int i = 0; i <= p; i++) {
        x = getRangeInt(0, 1);
        y = getRangeInt(0, 1);
        if (wzw(x, y) == 1) count_incircle++;
    }
    printf("Approximation pi: %lf", (count_incircle / (double) p) * 4);
}
