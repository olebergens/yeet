//
// Created by Ole Bergens on 17.11.21.
//
#include <stdio.h>
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

void approx() {

}