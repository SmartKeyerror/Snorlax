#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool isSameTree(struct TreeNode* p, struct TreeNode* q){

    if (p == NULL || q == NULL) return p == q;

    if (p->val != q->val) return false;

    bool leftIsSame = isSameTree(p->left, q->left);
    bool rightIsSame = isSameTree(p->right, q->right);

    return leftIsSame && rightIsSame;
}
