
#include <vector>

using namespace std;


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
    vector<int> result;

    void preorder(TreeNode *root) {
        if (root == NULL) return;

        result.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
        return;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        result.clear();
        preorder(root);
        return result;
    }
};
