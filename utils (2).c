```c
#include <stdio.h>
#include "header.h"

void clearInputBuffer(void) {
    while (getchar() != '\n');
}

int getIntInput(void) {
    int value;
    while (scanf("%d", &value) != 1) {
        printf("Invalid input. Enter a number: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
}

float getFloatInput(void) {
    float value;
    while (scanf("%f", &value) != 1) {
        printf("Invalid input. Enter a number: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
}
```