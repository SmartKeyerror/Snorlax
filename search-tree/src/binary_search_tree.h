#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <stddef.h>

typedef struct node {
    int key;
    void *value;
    struct node *left;
    struct node *right;
} Node; 

typedef struct binary_tree {
    Node *root;
    size_t count;
} BinaryTree;

BinaryTree *new_binary_tree(void);

Node *new_node(int key, void *value);

void delete_binary_tree(BinaryTree *binary_tree);

int find(BinaryTree *binary_tree, int find_key, Node *result);

int insert(BinaryTree *binary_tree, int key, void *value);

int update(BinaryTree *binary_tree, int key, void *value);

void delete(BinaryTree *binary_tree, int key);

int delete_min(BinaryTree *binary_tree, Node *min_node);

int delete_max(BinaryTree *binary_tree, Node *max_node);

int get_max_value(BinaryTree *binary_tree, Node *result);

int get_min_value(BinaryTree *binary_tree, Node *result);

void preorder_recursive(BinaryTree *binary_tree);

void preorder(BinaryTree *binary_tree);

void midorder(BinaryTree *binary_tree);

void postorder(BinaryTree *binary_tree);

void levelorder(BinaryTree *binary_tree);

#endif