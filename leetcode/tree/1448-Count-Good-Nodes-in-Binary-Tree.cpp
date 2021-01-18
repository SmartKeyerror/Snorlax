
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    int res;

    void dfs(TreeNode* root, int currMax) {
        if (root == nullptr) return;

        if (root->val >= currMax) {
            res ++;
            currMax = root->val;
        }

        dfs(root->left, currMax);
        dfs(root->right, currMax);
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return res;
    }
};