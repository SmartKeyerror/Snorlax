
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* 使用栈实现的中序遍历，返回结果数组(数组类型为 int)
 * 由于C并不直接支持动态数组，所以数组在每次添加元素时均需要进行malloc。也可以取巧直接分配容量为100的数组，因为题目中已给出节点数量的限制条件
 * 数组所实现的栈在元素入栈和出栈时均在尾部进行
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){

    *returnSize = 0;

    if (root == NULL) return NULL;

    int *result = malloc(sizeof(int) * (*returnSize));
    
    int length = 0;
    struct TreeNode **stack = malloc(sizeof(struct TreeNode *));

    struct TreeNode *pop_node, *current_root = root;

    stack[length++] = current_root;

    while (length) {

        // 当存在左孩子时，将其入栈
        while(current_root->left != NULL) {
            stack = realloc(stack, sizeof(struct TreeNode *) * (length + 1));       // 没有默认栈实现，每次都需要malloc
            stack[length++] = current_root->left;
            current_root = current_root->left;
        }

        pop_node = stack[--length];

        result = realloc(result, sizeof(int) * (*returnSize + 1));
        result[*returnSize] = pop_node->val;
        *returnSize += 1;

        // 判断当前节点是否存在右孩子，若存在一并压入
        if (pop_node->right != NULL) {
            stack[length++] = pop_node->right;
            current_root = pop_node->right;
        }
    }

    return result;
}
