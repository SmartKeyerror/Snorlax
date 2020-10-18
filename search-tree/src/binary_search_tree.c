#include "binary_search_tree.h"
#include "../../stack/src/stack.h"

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

Node *new_node(int key, void *value) {
    Node *node = (Node *)malloc(sizeof(Node));

    if (node == NULL) {
        perror("malloc Node failed");
        return NULL;
    }

    node->key = key;
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

void delete_node(Node *node) {
    free(node);
}

void static delete_tree_node(Node *root) {
    if (root == NULL) return;

    delete_tree_node(root->left);
    delete_tree_node(root->right);
    delete_node(root);
}

/*
 * 递归实现的后序遍历释放内存空间
 */
void delete_binary_tree(BinaryTree *binary_tree) {
    delete_tree_node(binary_tree->root);
    free(binary_tree);
}

/*
 * 查找元素
 */
int find(BinaryTree *binary_tree, int find_key, Node *result) {
    Node *current = binary_tree->root;

    while (current != NULL) {
        if (find_key == current->key) {
            *result = *current;
            return SUCCESS;
        } else if (find_key > current->key) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    return FAIL;
}

/*
 * 二分搜索树插入元素
 */
int insert(BinaryTree *binary_tree, int key, void *value) {

    Node *node = new_node(key, value);

    if (node == NULL) {
        return FAIL;
    }

    if (binary_tree->root == NULL) {
        binary_tree->root = node;
        binary_tree->count++;
        return SUCCESS;
    }

    Node *parrent;
    Node *current = binary_tree->root;
    
    while (current != NULL) {
        /*
         * 不断遍历，直到找到一个空节点为止，该空节点就是节点插入的位置，所以，我们还需要记录节点的父节点
         */
        parrent = current;

        if (key < current->key) {
            current = current->left;             // 当key小于当前节点值时，于左子树中进行查找
        } else if (key == current->key) {        // 当key等于当前节点值时，直接返回
            return;
        } else {
            current = current->right;           // 反之，则去右子树中查找
        }
    }

    if (key < parrent->key) {
        parrent->left = node;
    } else {
        parrent->right = node;
    }

    binary_tree->count++;
    
    return SUCCESS;
}

/*
 * 二分搜索树更新元素，若存在所需更新的key则进行更新，否则返回错误
 */
int update(BinaryTree *binary_tree, int key, void *value) {
    Node *current = binary_tree->root;

    while (current != NULL) {
        if (key == current->key) {
            current->value = value;
            return SUCCESS;
        } else if (key > current->key) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    return FAIL;
}

/*
 * 二分搜索树删除元素，若存在删除的key则删除，否则返回错误
 */
int delete(BinaryTree *binary_tree, int key) {

}

/*
 * 获取二分搜索树中的最大值节点
 */
int get_max_value(BinaryTree *binary_tree, Node *result) {
    if (binary_tree->root == NULL) {
        return FAIL;
    }

    Node *current = binary_tree->root;

    while (current->right != NULL) {
        current = current->right;
    }

    *result = *current;

    return SUCCESS;
}

/*
 * 获取二分搜索树中的最小值节点
 */
int get_min_value(BinaryTree *binary_tree, Node *result) {
    if (binary_tree->root == NULL) {
        return FAIL;
    }

    Node *current = binary_tree->root;

    while (current->left != NULL) {
        current = current->left;
    }

    *result = *current;

    return SUCCESS;
}

/*
 * 递归实现的前序遍历(根节点->左子树->右子树), 中序、后序的遍历只需要调整递归函数中的处理语句即可
 */
static void _preorder_recursive(Node *root);

void preorder_recursive(BinaryTree *binary_tree) {
    _preorder_recursive(binary_tree->root);
}

static void _preorder_recursive(Node *root) {
    if (root == NULL) return;

    printf("%d, ", root->key);
    _preorder_recursive(root->left);
    _preorder_recursive(root->right);
}

void preorder(BinaryTree *binary_tree) {
    
    Stack *stack = new_stack(binary_tree->count, sizeof(Node *));
    if (stack == NULL) return;

    /*
     * 这里需要注意的是，泛型栈必须传入想要保存的元素的指针
     * 虽然 binary_tree->root 本身就是一个指针，但是我们不能直接将 binary_tree->root 传入
     * 应该使用更高层的指针来保证原有指针不会在调用 push 以及 pop 方法时受到“损坏”
     */
    push(stack, &binary_tree->root);

    Node *process_node;

    while (!is_stack_empty(stack)) {
        pop(stack, &process_node);

        printf("%d, ", process_node->key);

        if (process_node->right != NULL) {
            push(stack, &process_node->right);
        }

        if (process_node->left != NULL) {
            push(stack, &process_node->left);
        }
    }
}
