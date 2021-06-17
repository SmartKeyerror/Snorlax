#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


// 时间复杂度 O(n)，空间复杂度 O(h)，并没有利用完全二叉树的性质
// int countNodes(struct TreeNode* root){
//     if (root == NULL) return 0;

//     int leftNodes = countNodes(root->left);
//     int rightNodes = countNodes(root->right);

//     return leftNodes + rightNodes + 1;
// }



/*
 * 完全二叉树的性质: 叶子节点之间的树高不超过 1，并且最后一层的节点全部向左靠拢
 * 也就是说，从 root 节点出发，一直往左走，就达到了整棵完全二叉树的最大高度
 * 
 * 因此，我们可以使用一个 mostLeft(TreeNode *root) 函数来求解以 root 为根节点的二叉树的最大高度
 * 
 * 假设完全二叉树的高度为 h，首先查看 root 右子树的最左节点，如果它能达到高度 h，那么就说明 root 的整棵左子树都是满二叉树，其节点个数为 2^(h-1) - 1，
 * 那么此时只要知道右子树的节点个数就能知道以 root 为根节点的完全二叉树的节点个数，这时候递归求解即可。
 * 
 * 如果 root 右子树的最左节点不能达到高度 h，那么就说明整棵右子树是完全二叉树，并且其高度为 h-1
 */

int mostLeftLevel(struct TreeNode* root, int level) {
    while (root != NULL) {
        level ++;
        root = root->left;
    }
    return level - 1;
}

int dfs(struct TreeNode* root, int level, int heigh) {
    if (level == heigh) return 1;

    // 此时左子树是一棵满二叉树
    if (mostLeftLevel(root->right, level + 1) == heigh) {
        return (1 << (heigh - level)) + dfs(root->right, level + 1, heigh);
    } else {
        // 此时右子树是一棵满二叉树
        return (1 << (heigh - level - 1)) + dfs(root->left, level + 1, heigh);
    }
}

int countNodes(struct TreeNode* root){
    if (root == NULL) return 0;
    return dfs(root, 1, mostLeftLevel(root, 1));
}