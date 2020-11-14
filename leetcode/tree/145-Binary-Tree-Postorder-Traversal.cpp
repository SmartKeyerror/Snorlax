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

    void postorder(TreeNode *root) {
        if (root == NULL) return;

        postorder(root->left);
        postorder(root->right);
        result.push_back(root->val);
        return;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        result.clear();
        postorder(root);
        return result;
    }
};
