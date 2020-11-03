
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
    vector<vector<int>> result;

    void dfs(TreeNode *root, int sum, vector<int> &res) {

        if (root == NULL) return;

        res.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                result.push_back(res);
            }
            // 不管有没有结果，都需要将之前添加的节点从 res 中 pop 掉
            res.pop_back();
            return;
        }

        dfs(root->left, sum - root->val, res);
        dfs(root->right, sum - root->val, res);

        res.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<int> res;
        dfs(root, sum, res);
        return result;
    }
};