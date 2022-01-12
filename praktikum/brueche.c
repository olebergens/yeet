typedef struct Brueche{
    int zaehler;
    int nenner;
}Rational, *RationalRef;

void printRational(Rational *rational) {
    printf("%d / %d\n", rational->zaehler, rational->nenner);
}

void reduce(RationalRef rational) {
    int a, b, r;
    if (rational->nenner > rational->zaehler) {
        a = rational->zaehler;
        b = rational->nenner;
    } else {
        a = rational->nenner;
        b = rational->zaehler;
    }
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    rational->zaehler = rational->zaehler / a;
    rational->nenner = rational->nenner / a;
}

RationalRef addRational(RationalRef rational1, RationalRef rational2) {
    RationalRef r = malloc(sizeof(RationalRef));
    r->zaehler = (rational1->zaehler * rational2->nenner) + (rational2->zaehler * rational1->nenner);
    r->nenner = rational1->nenner * rational2->nenner;
    return r;
}
int compare(RationalRef rational1, RationalRef rational2) {
    if ((rational1->zaehler * rational2->nenner) == (rational2->zaehler * rational1->nenner)) return 0;
    else if ((rational1->zaehler * rational2->nenner) > rational2->zaehler * rational1->nenner) return 1;
    else return -1;
}

int startRational(void) {
    Rational r1 = {1, 2};
    Rational r2 = {1, 3};
    Rational r3 = {2, 3};

    RationalRef sum = addRational(addRational(&r1, &r2), &r3);
    printf("sum is: ");
    printRational(sum);
    reduce(sum);

    printf("reduced sum is: \n");
    printRational(sum);

    printf("---------\n");
    int i;
    Rational rs[5] = {{1, 2}, {5, 2}, {1, 3}, {1, 4}, {3, 4}};
    qsort(rs, 5, sizeof(Rational), compare);
    for (i = 0; i < 5; i++) printRational(rs+i);


}
