
#include <vector>
#include <queue>

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
 * 判断两棵树的叶子节点是否相等(从左至右)，DFS 求解可以
 */
class Solution {
private:
    void midorder(TreeNode* root, vector<int> &leaves) {
        if (root == nullptr) return;
        midorder(root->left, leaves);
        if (root->left == nullptr && root->right == nullptr) leaves.push_back(root->val);
        midorder(root->right, leaves);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        midorder(root1, leaves1);
        midorder(root2, leaves2);

        return leaves1 == leaves2;
    }
};