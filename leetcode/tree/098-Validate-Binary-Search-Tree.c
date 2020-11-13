
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// MD leetcode 竟然会传 INT_MAX，所以 treeMin 和 treeMax 均设置成 long long 类型
bool check(struct TreeNode* root, long long treeMin, long long treeMax) {
    if (root == NULL)
        return true;

    if (root->val <= treeMin || root->val >= treeMax)
        return false;
    
    bool left = check(root->left, treeMin, root->val);
    bool right = check(root->right, root->val, treeMax);

    return left && right;
}

bool isValidBST(struct TreeNode* root){
    return check(root, LLONG_MIN, LLONG_MAX);
}
