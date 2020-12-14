
#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>

// Adjacency Matrix Graph, 由邻接矩阵所实现的图
typedef struct MatrixGraph {
    int vertices;       // 顶点数
    int edges;          // 边数
    int **matrix;       // 邻接矩阵，即二维数组, 这里使用 int 而不是 bool 的原因在于 int 也可以表示带环图、平行图
} MatrixGraph;


// 我放弃了... C 写这玩意儿太难受了....

#endif