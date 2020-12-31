

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    TreeNode *prev;
    bool dfs(TreeNode* root) {
        if (root == nullptr) return true;

        if (prev != nullptr) {
            if (root->val != prev->val)
                return false;
        }

        prev = root;

        if (!dfs(root->left)) return false;

        if (!dfs(root->right)) return false;

        return true;
    }
public:
    bool isUnivalTree(TreeNode* root) {
        return dfs(root);
    }
};