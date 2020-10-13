#include <stdio.h>

#include "union_find.h"

int find(UF *u, int index) {
    return u->elements[index];
}

int is_connected(UF *u, int src, int dst) {
    return find(u, src) == find(u, dst);
}

void union_node(UF *u, int src, int dst) {
    int src_value = find(u, src);
    int dst_value = find(u, dst);

    if (src_value == dst_value) return;

    for (int i = 0; i < u->size; i++) {
        if (u->elements[i] == src_value)
            u->elements[i] = dst_value;
    }
}


int main() {
    UF *u = initUnionFind(10);

    union_node(u, 5, 6);
    union_node(u, 2, 5);
    union_node(u, 1, 6);

    printf("node 5 is connected to node 6? %d \n", is_connected(u, 5, 6));
    printf("node 1 is connected to node 3? %d \n", is_connected(u, 1, 3));
    printf("node 1 is connected to node 5? %d \n", is_connected(u, 1, 5));
}