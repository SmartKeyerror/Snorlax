#ifndef SORT_H
#define SORT_h

#include <stdbool.h>

typedef int elementType ;

bool less(elementType a, elementType b) {
    return (a < b);
}

bool more(elementType a, elementType b) {
    return (a > b);
}

#endif