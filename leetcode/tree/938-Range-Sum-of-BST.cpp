
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * 求 BST 中 val 值在 [low, high] 这一闭区间的所有节点值的和。所以，这和 BST 有什么关系??
 */
class Solution {
private:
    int preorder(TreeNode *root, int low, int high) {
        if (root == nullptr) return 0;
        
        int sum = 0;
        if (root->val >= low && root->val <= high)
            sum += root->val;
        
        sum += preorder(root->left, low, high);
        sum += preorder(root->right, low, high);

        return sum;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return preorder(root, low, high);
    }
};
