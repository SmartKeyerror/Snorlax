#ifndef SORT_H
#define SORT_H

#include <stdbool.h>
#include <stddef.h>

typedef int elementType ;

bool less(elementType a, elementType b);

bool more(elementType a, elementType b);

void bubble_sort(elementType list[], size_t length, bool (*compare)(elementType a, elementType b));

void insertion_sort(elementType list[], size_t length, bool (*compare)(elementType a, elementType b));

void merge_sort(elementType list[], size_t length, bool (*compare)(elementType a, elementType b));

#endif