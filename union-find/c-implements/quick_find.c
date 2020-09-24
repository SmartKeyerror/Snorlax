#include <stdio.h>

#include "union_find.h"

int get_node(UnionFind *u, int index) {
    return u->elements[index];
}

int is_connected(UnionFind *u, int src, int dst) {
    return get_node(u, src) == get_node(u, dst);
}

void union_node(UnionFind *u, int src, int dst) {
    int src_value = get_node(u, src);
    int dst_value = get_node(u, dst);

    if (src_value == dst_value) return;

    for (int i = 0; i < u->size; i++) {
        if (u->elements[i] == src_value)
            u->elements[i] = dst_value;
    }
}


int main() {
    UnionFind *u = initUnionFind(10);

    union_node(u, 5, 6);
    union_node(u, 2, 5);
    union_node(u, 1, 6);

    printf("node 5 is connected to node 6? %d \n", is_connected(u, 5, 6));
    printf("node 1 is connected to node 3? %d \n", is_connected(u, 1, 3));
    printf("node 1 is connected to node 5? %d \n", is_connected(u, 1, 5));
}