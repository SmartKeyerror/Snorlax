#include <stdlib.h>

typedef struct _UnionFind {
    int size;
    int elements[0];
    int rank[0];
} UnionFind;


UnionFind *initUnionFind(int size) {
    UnionFind *u = (UnionFind *)malloc(sizeof(UnionFind) + size * sizeof(int) * 2);

    u->size = size;

    for (int i = 0; i < size; i++) {
        u->elements[i] = i;
        u->rank[i] = 1;
    }

    return u;
}
