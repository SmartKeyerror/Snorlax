#include <stdio.h>

#include "union_find.h"

int get_root(UnionFind *u, int index) {
    while (u->elements[index] != index) {

        // 路径压缩
        u->elements[index] = u->elements[u->elements[index]];

        index = u->elements[index];
    }
    return u->elements[index];
}

int is_connected(UnionFind *u, int src, int dst) {
    return get_root(u, src) == get_root(u, dst);
}

void union_node(UnionFind *u, int src, int dst) {
    int src_root = get_root(u, src);
    int dst_root = get_root(u, dst);

    if (src_root == dst_root) return ;

    u->elements[src_root] = dst_root;
}

int main() {
    UnionFind *u = initUnionFind(10);

    union_node(u, 5, 6);
    union_node(u, 2, 5);
    union_node(u, 1, 6);
    union_node(u, 6, 8);
    union_node(u, 8, 9);

    printf("node 5 is connected to node 6? %d \n", is_connected(u, 5, 6));
    printf("node 1 is connected to node 3? %d \n", is_connected(u, 1, 3));
    printf("node 1 is connected to node 5? %d \n", is_connected(u, 1, 5));
    printf("node 6 is connected to node 9? %d \n", is_connected(u, 6, 9));

}