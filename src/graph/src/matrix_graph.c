
#include "graph.h"

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>


MatrixGraph *new_adj_graph(int vertices) {
    MatrixGraph *graph = malloc(sizeof(MatrixGraph));
    graph->vertices = vertices;

    graph->matrix = malloc(sizeof(int *) * vertices);

    for (int i = 0; i < vertices; i++)
        graph->matrix[i] = malloc(sizeof(int) * vertices);
    
    return graph;
}

// 将顶点 src 与顶点 dst 建立连接关系，也就是生成一条边
void add_to_matrix_graph(MatrixGraph *graph, int src, int dst) {
    assert(src < graph->vertices && dst < graph->vertices);
    
    if (graph->matrix[src][dst] == 1) 
        return ;

    graph->matrix[src][dst] = 1;
    graph->matrix[dst][src] = 1;
    graph->edges ++;

    return ;
}

// 判断 src 与 dst 是否直接连接
bool is_matrix_graph_connected(MatrixGraph *graph, int src, int dst) {
    assert(src < graph->vertices && dst < graph->vertices);
    return graph->matrix[src][dst] == 1;
}

// 获取 src 连接的所有顶点, 这里使用 int *result 作为结果的存储，不在函数内部开辟堆空间
int get_neighbors_from_matrix_graph(MatrixGraph *graph, int src, int *result) {
    assert(src < graph->vertices);

    int offset = 0;
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->matrix[src][i] == 1) {
            result[offset] = i;
            offset ++;
        }
    }
    return offset;
}

static void dfs(MatrixGraph *graph, int start, int *result, int offset, bool visited[]) {
    visited[start] = true;
    result[offset] = start;
    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[graph->matrix[start][i]] && graph->matrix[start][i] == 1)
            dfs(graph, graph->matrix[start][i], result, offset + 1, visited);
    }
    return ;
}

// 图的深度优先遍历(连接图，也就是只有一个连通分量的图的遍历)
void matrix_graph_dfs(MatrixGraph *graph, int start, int *result) {
    assert(start < graph->vertices);
    bool visited[graph->vertices];
    dfs(graph, start, result, 0, visited);
}
