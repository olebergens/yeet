#include "List.h"
#include "stdio.h"
#include "stdlib.h"

#define DEFAULT 0

List init() {
    return NULL;
}

Bool empty(List l) {
    return l ==  NULL;
}

List insert(Value v, List l) {
    List e = malloc(sizeof(Elem));
    e->val = v;
    e->next = l;
    return e;
}

Value head(List l) {
    if (l) return l->val;
    else printf("{head} empty list\n");
    return DEFAULT;
}

List tail(List l) {
    return l ? l->next : l;
}

Value nth(List l, unsigned int n) {
    return n > 0 ? nth(tail(l), n-1) : head(l);
}

Bool isin(Value n, List l) {
    return empty(l) ? False : (head(l) == n ? True : isin(n, tail(l)));
}

void iterate(List l, VProc p) {
    for(; !empty(l); l=tail(l)) p(head(l));
}

List append(List la, List lb) {
    return la ? insert(head(la), append(tail(la), lb)) : lb;
}

Value last(List l) {
    if (l) return l->next ? last(l->next) : l->val;
    else printf("{last} empty list\n");
    return DEFAULT;
}

unsigned int length(List l) {
    return empty(l) ? 0 : 1 + length(tail(l));
}

void show(Value v) {
    printf("%d\n", v);
}

void showList(List l) {
    iterate(l, show);
}