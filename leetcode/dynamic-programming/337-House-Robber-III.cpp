#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
 * 打家劫舍终极版: 二叉树中洗劫
 * 
 * 在一棵二叉树中进行洗劫，不能洗劫直接相邻的节点，也就是父子节点，兄弟节点可同时洗劫。
 * 
 * House Robber 问题本质上仍是0-1背包问题，即对于当前的节点，可以选择洗劫，也可以选择不洗劫。那么我们如何在一棵树中来完成洗劫?
 * 
 *          a
 *        /   \
 *       b     c
 *      / \   / \
 *     d   e f   g
 * 
 * 假设我们的二叉树长这个样子，由于我们不能偷相邻的两个节点，也就是说， 假如我们偷了节点 a (root节点) 的话，那么节点 b (左孩子节点) 和节点 c (右孩子节点) 便不能再偷了，只能在 d、e、f、g 这4个节点中选择
 * 相反，如果我们不去偷节点 a 的话，那么节点 b 和节点 c 我们都能偷。
 * 
 * 如此一来，我们的状态转移方程就很清晰了: f(node) = max(V(node)+f(node.left.all)+f(node.right.all), f(node.left)+f(node.right))
 * 
 * 简单来说就是偷了当前根节点，那么只能去左右子节点的子节点进行偷取，否则，可以偷取左右子节点。
 */
class Solution {
private:
    
    unordered_map<TreeNode *, int> memory;
    
    int dfs(TreeNode *root) {
        if (root == nullptr) return 0;
        
        if (memory.find(root) != memory.end()) 
            return memory[root];
        
        int value = 0;
        
        if (root->left)
            value += dfs(root->left->right) + dfs(root->left->right);

        if (root->right)
            value += dfs(root->right->left) + dfs(root->right->right);
        
        // 在选择偷当前根节点和不偷当前根节点之间进行比较
        int maxValue = max(root->val + value, dfs(root->left) + dfs(root->right));

        memory[root] = maxValue;

        return maxValue;
    }
    
public:
    int rob(TreeNode* root) {
        return dfs(root);
    }
};
