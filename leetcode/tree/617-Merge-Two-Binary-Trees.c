
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


// 原有函数原型即为递归原型
struct TreeNode *mergeTrees(struct TreeNode *t1, struct TreeNode *t2) {
    if (t1 == NULL && t2 == NULL)
        return NULL;
    
    if (t1 == NULL)
        return t2;
    
    if (t2 == NULL)
        return t1;
    
    t1->val += t2->val;
    
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);

    return t1;
}

