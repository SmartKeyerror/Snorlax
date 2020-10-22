#include "sort.h"

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>


void bubble_sort(elementType list[], size_t length, bool (*compare)(elementType a, elementType b)) {
    for (size_t i = 0; i < length - 1; i++) {
        
        bool changed = false;

        for (size_t j = 0; j < length - 1 - i; j++) {

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