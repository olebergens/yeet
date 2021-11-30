#include "stdio.h"
/**
 * @param n : Übergabe des Parameters N bei einer N x K Matrix
 * @param k : Übergabe des Paramaters K bei einer N x K oder K x M Matrix
 * @param m : Übergabe des Parameters M bei einer N x M Matrix
 */
void matrix_product(int n, int k, int m) {
    int matrixA[n][k];
    int matrixB[k][m];
    int matrixOut[n][m];

    for (int i = 1; i < n; n++) {
        for (int j = 1; j < m; j++) {
            for (int l = 1; l < k - 1; l++) {
                matrixOut[i][j] = matrixOut[i][j] + matrixA[i][l] * matrixB[l][j];
            }
        }
    }
}

/**
 * Matrixprodukt durch abtasten einer Textfile..
 * Ich zähle die Leerzeichen um das N, K, M zu filtern der Matrix.
 * Mit einem rewind dann nochmal durchgehen und die Zahlen herauslesen.
 * Dann ausrechnen.
 * Wir sollen die Matrix in Form von: N x M
 */
void matrixProduct() {
    int c;
    int spacesCount = 0, lbCount = 0;
    int matrixA = 0, matrixB = 0, matrixOut = 0;

    while (c != EOF) {
        c = getchar();

    }
    matrixA = 0;
    matrixB = 0;
    matrixOut = 0;
}

/**
 * @param x : Zahl aus der die Quadratwurzel gezogen werden soll
 * @return Wert der Quadratwurzel von x (sqrt(x))
 * Realisierung über das Newton-Verfahren aus der Hausaufgabe 01
 */
const double DELTA = 1.E-5;
double squareRoot(double x) {
    double n = x;
    while ((n * n - x) > DELTA)
        n = (n + x / n) / 2;
    return n;
}

/**
 * @param x : Eingabewert, welcher ueberprueft werden soll ob dieser in dem Intervall liegt
 * @param a : erste Intervallgrenze
 * @param b : zweite Intervallgrenze
 * @return 0 falls x nicht im Intervall liegt, ansonsten 1.
 * Beachte: Die Intervallgrenzen können auch nicht in der richtigen Reihenfolge angegeben werden
 * Getan wird das über eine temporäre Variable t. Diese wird dem Wert a zugewiesen und dann schaut man nach ob a <= b ist, falls true: a false: b setzen
 * Das gleiche dann durch die temp Variable, da ansonsten falls a > b ist a = b ist und dann im Grunde gecheckt wird ob b >= b ist und das ist nicht das was wir wollen
 * Dadurch wird dort die temp Variable benutzt und geschaut ob b >= t ist falls true: b false: t gesetzt.
 */
int contained(double x, double a, double b) {
    double t = a;
    a = a < b ? a : b;
    b = b > t ? b : t;
    return a <= x && x <= b ? 1 : 0;
}

/**
 * @param px : x-Koordinate des Punktes P
 * @param py : y-Koordinate des Punktes P
 * @param qx : x-Koordinate des Punktes Q
 * @param qy : y-Koordinate des Punktes Q
 * @return die Distanz zwischen den beiden Punkten über die Berechnung von Pythagoras
 */
double getDistanceBetweenPoints(double px, double py, double qx, double qy) {
    return squareRoot((qy - py) * (qy - py) + (qx - px) * (qx - px));
}

/**
 * @param x : x-Koordinate
 * @param y : y-Koordinate
 * @param px : Punkt p x-Koordinate
 * @param py : Punkt p y-Koordinate
 * @param qx : Punkt q x-Koordinate
 * @param qy : Punkt q y-Koordinate
 * @return 1 falls der Abstand zwischen Punkt X = (x,y) und Strecke PQ < 0.5 ist ansonsten 0.
 */
int line(double x, double y, double px, double py, double qx, double qy) {
    double nx = py - qy;
    double ny = qx - px;
    double l = getDistanceBetweenPoints(px, py, qx, qy);
    // Koeffizenten a, b, c berechnen um die Gerade zu bestimmen
    // a, b = Koordinaten Normalevektor ;; c Verschiebung von Ursprung entlang Diagonale
    double a = nx / l;
    double b = ny / l;
    double c = -(a*px + b*py);
    return a*x+b*y+c < 0.5 ? 1 : 0;
}

/**
 *           (lx,oy)---------------------(rx,oy)
 *                  |                   |
 *                  |       (x,y)       |
 *                  |                   |
 *           (lx,uy)---------------------(rx,uy)
 *
 * @param x : x-Koordinate des Rechtecks
 * @param y : y-Kooridnate des Rechtecks
 * @param lx : untere linke Ecke des Rechtsecks x-Koordinate
 * @param uy : untere linke Ecke des Rechtsecks y-Koordinate
 * @param rx : obere rechte Ecke des Rechtecks x-Koordinate
 * @param oy : obere rechte Ecke des Rechtecks y-Koordinate
 * @return 1 falls der Abstand zwischen einem der Punkte > 0.5 ist, ansonsten 0.
 */
int rectangle(double x, double y, double lx, double uy, double rx, double oy) {
    if (line(x, y, lx, uy, rx, uy) < 0.5 || line(x, y, lx, uy, lx, oy) < 0.5 || line(x, y, lx, oy, rx, oy) < 0.5 ||
            line(x, y, rx, oy, rx, uy) < 0.5) return 0;
    return 1;
}

void drawHouse(int xKor, int yKor) {
    // um die eingegebenen Werte zu behalten
    int y = yKor;
    int x = xKor;
    // y-Achse
    for (; yKor > 0; yKor--) {
        // x-Achse bis der
        for (float i = 0; i <= xKor; i++) {
            if ((yKor == 1 || yKor == 15) && contained(i, 0, 15)) printf("*");
            if (contained(yKor, 1, 15) && (i == 0 || i == 30)) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}
