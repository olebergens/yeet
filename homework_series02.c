//
// Created by Ole Bergens on 20.11.21.
//
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
    a = a <= b ? a : b;
    b = b >= t ? b : t;
    return a <= x <= b ? 1 : 0;
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
 * @param x : x-Koordinate des Rechtecks
 * @param y : y-Kooridnate des Rechtecks
 * @param lx : untere linke Ecke des Rechtsecks x-Koordinate
 * @param uy : untere linke Ecke des Rechtsecks y-Koordinate
 * @param rx : obere rechte Ecke des Rechtecks x-Koordinate
 * @param oy : obere rechte Ecke des Rechtecks y-Koordinate
 * @return 1 falls der Abstand zwischen einem der Punkte > 0.5 ist, ansonsten 0.
 */
int rectangle(double x, double y, double lx, double uy, double rx, double oy) {
    if (getDistanceBetweenPoints(x, y, lx, uy) > 0.5) return 1;
    if (getDistanceBetweenPoints(x, y, rx, oy) > 0.5) return 1;
    if (getDistanceBetweenPoints(lx, uy, rx, oy) > 0.5) return 1;
    return 0;
}

