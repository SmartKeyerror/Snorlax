#ifndef __UNION_FIND__
#define __UNION_FIND__

#include <stdlib.h>

typedef struct UnionFind {
    int size;
    int elements[0];
} UF;

UF *initUnionFind(int size) {
    UF *u = (UF *)malloc(sizeof(UF) + size * sizeof(int));

    u->size = size;

    for (int i = 0; i < size; i++) {
        u->elements[i] = i;
    }

    return u;
}

#endif