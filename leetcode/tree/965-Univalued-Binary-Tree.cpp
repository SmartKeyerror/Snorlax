

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    bool dfs(TreeNode* root, int val) {
        if (root == nullptr) return true;

        if (root->val != val) return false;

        if (!dfs(root->left, val)) return false;

        if (!dfs(root->right, val)) return false;

        return true;
    }
public:
    bool isUnivalTree(TreeNode* root) {
        return dfs(root, root->val);
    }
};