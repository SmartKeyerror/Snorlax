struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * 将一颗 BST 变成“有序链表”结构，使得新的树只有右孩子，并且也是一颗 BST。
 */
class Solution {
private:

    TreeNode *dummy = new TreeNode(0);
    TreeNode *current;

    void inorder(TreeNode *root) {
        if (root == nullptr) return ;

        inorder(root->left);
        current->right = new TreeNode(root->val);
        current = current->right;
        inorder(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (root == nullptr) return root;

        current = dummy;
        inorder(root);
        return dummy->right;
    }
};
