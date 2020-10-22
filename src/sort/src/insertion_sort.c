#include "sort.h"

#include <stddef.h>
#include <stdbool.h>

void insertion_sort(elementType list[], size_t length, bool (*compare)(elementType a, elementType b)) {
    for (size_t i = 1; i < length; i++) {
        for (size_t j = i; j > 0; j--) {
            
            bool changed = false;
            
            if (!compare(list[j], list[j-1])) {
                elementType temp = list[j];
                list[j] = list[j-1];
                list[j-1] = temp;

                changed = true;
            }

            if (!changed) break;
        }
    }
}
