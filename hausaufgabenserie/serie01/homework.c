//
// Created by Ole Bergens on 17.11.21.
//
#include "stdio.h"
/**
 * Berechnung der Quadratwurzel aus dem Newton-Verfahren:
 *  f(x) = x^2 - a
 *  f'(x) = 2x
 *  x_(n+1) := x_n - (((x^2)_n) - a) / (2*x_n) = (((2x^2)_n) - ((x^2)_n) + a) / (2x_n) = 1/2(x_n + (a) / (x_n))
 * Für das Newton-Verfahren zur Bestimmung einer sqrt(a) müssen wir folgendes beachten:
 *  -> man setzt n0 auf a.
 *  -> Wiederholt bis n_i^2 ≈ a die unsere gewollte Genauigkeit hat
 *      >> Setzt n_i+1 auf den Mittelwert von n_i und a / n_i
 *  -> letztes n_i ist Näherung für sqrt(a)
 *
 *  @AUTHOR: Ole Bergens (221200097), Nils Martin (NaN)
 */
void newton() {
    double a;
    printf("Bitte gib die Zahl a ein, aus welcher die Quadratwurzel berechnet werden soll: \n a: ");
    scanf("%lf", &a);
    fflush(stdout);
    double n = a;
    while((n * n - a) > DELTA)
        n = (n + a / n) / 2;
    printf("Die Quadratwurzel aus der Zahl %lf ist die Zahl: %lf", a, n);
}

long factorial(int x) {
    long factorial = 1;
    for (int i = 1; i <= x; ++i)
        factorial = factorial * i;
    return factorial;
}

double powBE(double x, int n) {
    int t;
    if (n == 0) return 1;
    t = powBE(x, n/2);
    if (n % 2 == 0) return t * t;
    else return x * t * t;
}

/**
 * sin(x) = E_n=0 (-1)^n * (x^(2n+1) / (2n+1)!) = x/1! - x^3/3! + x^5/5! ± ...
 *        = wenn Durchlaufvariable n modulo 2 keinen Rest hat, müssen wir von unserer Summe das (x^(2n+1) / (2n+1)!) abziehen
 *        = wenn Durchlaufvariable n modulo 2 einen Rest hat, müssen wir zu unserer Summe das (x^(2n+1) / (2n+1)!) rechnen.
 * @AUTHOR: Ole Bergens (221200097), Nils Martin ()
 */
void sinx() {
    double x;
    printf("Bitte gib deinen x-Wert ein, fuer den die Sinusfuntkion berechnet werden soll: \n x: ");
    fflush(stdout);
    scanf("%lf", &x);
    double pi = 3.1415;
    float sum = 0;
    x = x * (pi / 180); // konvertieren von d zu r
    for (int n = 1, i = 1; n <= 20; n++, i += 2) {
        double term = powBE(x, i) / factorial(i);
        if (n % 2 == 0) sum -= term;
        else sum += term;
    }
    printf("sin: %.4lf", sum);
}

