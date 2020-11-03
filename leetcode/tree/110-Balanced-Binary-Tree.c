#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX(x, y) ((x) > (y) ? (x): (y))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root, bool *isBalanced);

bool isBalanced(struct TreeNode* root){
    if (root == NULL) return true;

    bool isTreeBalanced = true;

    maxDepth(root, &isTreeBalanced);

    return isTreeBalanced;
}

// 计算以 root 为根的二叉树最大树高，并且记录以 root 为根的二叉树是否平衡
int maxDepth(struct TreeNode *root, bool *isBalanced) {
    if (root == NULL) return 0;

    int leftMaxDepth = maxDepth(root->left, isBalanced);
    int rightMaxDepth = maxDepth(root->right, isBalanced);

    if (abs(leftMaxDepth - rightMaxDepth) > 1)
        *isBalanced = false;

    return MAX(leftMaxDepth, rightMaxDepth) + 1;
}
