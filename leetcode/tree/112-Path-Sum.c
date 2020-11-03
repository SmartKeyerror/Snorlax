
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
 * 以下为错误代码，递归终止条件不应该为 root == NULL，因为当 root 为 NULL 时，我们并不能确定其父节点是否为叶子节点
 *      5
 *     / \
 *   NULL 15
 *         \
 *          20
 * 以上述二叉树为例，当 sum 为 5 时，按照递归终止条件当进入左子树寻找 sum 为 0 的路径时将返回 true，然而节点 5 并非叶子节点。
 */
bool wrongCode(struct TreeNode* root, int sum){
    if (root == NULL) 
        return sum == 0;
    return wrongCode(root->left, sum - root->val) || wrongCode(root->right, sum - root->val);
}

bool hasPathSum(struct TreeNode* root, int sum){

    // 传入空树直接返回 false
    if (root == NULL) return false;

    // 正确的递归终止条件应为： 当 root 为叶子节点 且此时 sum 的值与当前节点的值相同
    if (root->left == NULL && root->right == NULL)
        return root->val == sum;
    
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}