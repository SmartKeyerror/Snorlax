
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * 和 538 号问题一模一样，leetcode 为什么不去重?
 */
class Solution {
    int total = 0;
    
    void traversal(TreeNode* root) {
        if (root == nullptr) return;

        traversal(root->right);

        total += root->val;
        root->val = total;

        traversal(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        traversal(root);
        return root;
    }
};