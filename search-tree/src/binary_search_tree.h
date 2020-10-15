#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <stddef.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node; 


typedef struct binary_tree {
    Node *root;
    size_t count;
} BinaryTree;

#endif