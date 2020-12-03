
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * 将一棵 BST 转换成一个节点值更大的 BST， 根据 right - root - left 的顺序，每个节点的值等于以遍历节点值的和再加上当前节点值
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
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }
};
