
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
 * 求节点 p、q 的最近公共祖先，由于 p、q 在一棵二分搜索树上，那么就可以利用 BST 的性质进行简化
 * 
 *      node        node        node
 *     /    \      /                \
 *    p      q     p、q              p、q
 * 
 * 如上所示，节点 p、q 的可能性一共可以分为三大类:
 *  - 节点 p、q 分布在 node 的两侧，那么此时最近公共祖先必定为 node
 *  - 节点 p、q 分布在 node 的左侧，那么此时最近公共祖先必定在 node 的左子树中
 *  - 节点 p、q 分布在 node 的右侧，那么此时最近公共祖先必定在 node 的右子树中
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

    if (root == NULL) return NULL;

    // p、q 应不为 NULL
    if (p == NULL || q == NULL) return NULL;

    if (p->val < root->val && q->val < root->val)
        // 此时应去 root 的左子树中寻找最近公共祖先
        return lowestCommonAncestor(root->left, p, q);
    if (p->val > root->val && q->val > root->val)
        // 此时应去 root 的右子树中寻找最近公共祖先
        return lowestCommonAncestor(root->right, p, q);

    // 剩下的情况我们直接返回当前的根节点就好了
    return root;
}