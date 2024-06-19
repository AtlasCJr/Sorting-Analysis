#include <time.h>
#include <stdlib.h>
#include <stdio.h>

unsigned long long int setBits() {
    unsigned long long int result = 0;

    result |= ((unsigned long long int)rand() << 48);
    result |= ((unsigned long long int)rand() << 32);
    result |= ((unsigned long long int)rand() << 16);
    result |= ((unsigned long long int)rand());

    return result;
}

void createArray(unsigned long long int** Array, int Length) {

    *Array = (unsigned long long int*) malloc(sizeof(unsigned long long int) * Length);

    if (*Array == NULL) {
        printf("\n\nMemory allocation failed.\n");
        exit(1);
    }

    int i;
    for(i = 0; i < Length; i++) {
        (*Array)[i] = setBits();
    }
}
