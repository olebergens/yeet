int max2(int a, int b) {
    return a >= b ? a : b;
}

int max4(int a, int b, int c, int d) {
    return max2(a, b) > max2(c, d) ? max2(a, b) : max2(c, d);
}
/**
    * (i > 1 && i % i == 0 [true])
    */
int isPrime(int p) {
    int s = 1;
    for (int i = 2; i < p; i++) {
        if (p % i != 0) s = 0;
        else s = 1;
    }
    return s;
 }