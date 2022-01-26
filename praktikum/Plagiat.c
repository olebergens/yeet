//
// Created by Ole Bergens on 26.01.22.
//
#include "stdlib.h"
#include "stdio.h"

char *dynamicString() {
    char *str = NULL;
    int i = 0, j = 2, c = 0;
    str = (char*) malloc(sizeof(char));
    if (str == NULL) {
        printf("Error while allocating memory\n");
        exit(EXIT_FAILURE);
    }
    while ((c = getc(stdin)) && c != EOF) {
        str[i] = c;
        str = realloc(str, j * sizeof(char));
        if (str == NULL) {
            printf("Error while allocating memory\n");
            free(str);
            exit(EXIT_FAILURE);
        }
        i++;
        j++;
    }
    str[i] = '\0';
    return str;
}

void startPlagiat() {
    printf("%s", dynamicString());
}