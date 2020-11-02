#include <stdlib.h>

#define MIN(x, y) ((x) < (y) ? (x): (y))
#define MAX(x, y) ((x) > (y) ? (x): (y))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepth(struct TreeNode* root){

    if (root == NULL)
        return 0;

    int leftMinDepth = minDepth(root->left);
    int rightMinDepth = minDepth(root->right);

    // 如果当前节点的左孩子节点或者是右孩子节点为空的话，其最小高度应为左右子树高度的最大值
    if (leftMinDepth == 0 || rightMinDepth == 0)
        return MAX(leftMinDepth, rightMinDepth) + 1;
    else
        return MIN(leftMinDepth, rightMinDepth) + 1;
}
