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
 *          a
 *        /   \
 *       b     c
 *      / \   / \
 *     d   e f   g
 * 
 * 假设 f(n) 表示偷当前节点的最大收益，g(n) 表示不偷当前节点的最大收益，显而易见地我们可以得到 f(n) 的结果:
 *      f(n) = n->val + g(n->left) + g(n-right)
 * 
 * 如果说我们不偷当前节点的话，那么就可以去左、右两棵子树中寻找最大收益。对于左子树，存在两种情况，对于右子树，也存在两种情况，则有:
 *      g(n) = max{ max{f(n->left), g(n->left)}, max{f(n->right), g(n->right)} }     
 * 
 */

struct Status {
    int selected;
    int notselected; 
};

class Solution {
private:
    Status dfs(TreeNode* root) {
        if (root == nullptr) return {0, 0};

        Status left = dfs(root->left);
        Status right = dfs(root->right);

        int selected = root->val + left.notselected + right.notselected;
        int notselected = max(max(left.selected, left.notselected), max(right.selected, right.notselected));

        return {selected, notselected};
    }
public:
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;

        Status res = dfs(root);

        return max(res.selected, res.notselected);
    }
};
