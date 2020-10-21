#include "sort.h"

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>


void bubble_sort(elementType list[], size_t length, bool (*compare)(elementType a, elementType b)) {
    for (int i = 0; i < length - 1; i++) {
        
        bool changed = false;

        for (int j = 0; j < length - 1 - i; j++) {

            if (compare(list[j], list[j+1])) {
                elementType temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
                changed = true;
            }

        }

        if (!changed) break;
    }
}

int main() {
    elementType list[] = {10, 15, 22, 88, 70, 90, 100, 5, 9, 45, 30, 22};
    bubble_sort(list, sizeof(list) / sizeof(elementType), more);

    for (int i = 0; i < sizeof(list) / sizeof(elementType); i++) {
        printf("%d, ", list[i]);
    }
}

