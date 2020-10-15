#include "binary_search_tree.h"
#include "../stack/src/stack.h"

#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 0
#define FAIL -1

BinaryTree *new_binary_tree(void) {
    BinaryTree *binary_tree = (BinaryTree *)malloc(sizeof(BinaryTree));

    if (binary_tree == NULL) {
        perror("malloc BinaryTree failed");
        return NULL;
    }

    binary_tree->root = NULL;
    binary_tree->count = 0;
    return binary_tree;
}

Node *new_node(int value) {
    Node *node = (Node *)malloc(sizeof(Node));

    if (node == NULL) {
        perror("malloc Node failed");
        return NULL;
    }

    node->value = value;
    node->left = node->right = NULL;
    return node;
}

void delete_binary_tree(BinaryTree *binary_tree) {
    // 使用栈实现的后序遍历逐一地释放每一个Node的内存空间
}

/*
 * 二分搜索树插入元素
 */
int insert(BinaryTree *binary_tree, int value) {

    Node *node = new_node(value);

    if (node == NULL) {
        return FAIL;
    }

    if (binary_tree->root == NULL) {
        binary_tree->root = new_node(value);
        return SUCCESS;
    }

    Node *parrent;
    Node *current = binary_tree->root;
    
    while (current != NULL) {
        /*
         * 不断遍历，直到找到一个空节点为止，该空节点就是节点插入的位置，所以，我们还需要记录节点的父节点
         */
        parrent = current;

        if (value < current->value) {
            current = current->left;        // 当value小于当前节点值时，于左子树中进行查找
        } else {
            current = current->right;       // 反之，则去右子树中查找
        }
    }

    if (value < parrent->value) {
        parrent->left = node;
    } else {
        parrent->right = node;
    }
    
    return SUCCESS;
}

/*
 * 获取二分搜索树中的最大值
 */
int get_max_value(BinaryTree *binary_tree, int *result) {
    if (binary_tree->root == NULL) {
        return FAIL;
    }

    Node *current = binary_tree->root;

    while (current->right != NULL) {
        current = current->right;
    }

    *result = current->value;

    return SUCCESS;
}

/*
 * 获取二分搜索树中的最小值
 */
int get_min_value(BinaryTree *binary_tree, int *result) {
    if (binary_tree->root == NULL) {
        return FAIL;
    }

    Node *current = binary_tree->root;

    while (current->left != NULL) {
        current = current->left;
    }

    *result = current->value;

    return SUCCESS;
}

/*
 * 递归实现的前序遍历(根节点->左子树->右子树), 中序、后序的遍历只需要调整递归函数中的处理语句即可
 */
void _preorder_recursive(Node *root);

void preorder_recursive(BinaryTree *binary_tree) {
    _preorder_recursive(binary_tree->root);
}

static void _preorder_recursive(Node *root) {
    if (root == NULL) return;

    printf("%d", root->value);
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}
