#include <stdlib.h>

#define MAX(x, y) ((x) > (y) ? (x): (y))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root){
    if (root == NULL) return 0;

    int leftMaxDepth = maxDepth(root->left);
    int rightMaxDepth = maxDepth(root->right);

    return MAX(leftMaxDepth, rightMaxDepth) + 1;
}
