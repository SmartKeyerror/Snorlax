

#include <vector>
#include <math.h>
#include <limits.h>

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
 * 计算根节点到叶子节点的路径和
 */
class Solution {
private:
    vector<vector<int>> result;

    void dfs(TreeNode *root, vector<int> &paths) {

        if (root == nullptr) return;

        paths.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            result.push_back(paths);
            paths.pop_back();
            return;
        }
            
        dfs(root->left, paths);
        dfs(root->right, paths);

        paths.pop_back();
    }

public:
    int sumNumbers(TreeNode* root) {

        vector<int> paths;
        dfs(root, paths);

        int sum = 0;
        for (vector<int> path: result) {
            int pathNbr = 0;
            for (int i = 0; i < path.size(); i++) {
                pathNbr += path[i] * pow(10, path.size() - i -1);
            }
            sum += pathNbr;
        }
        return sum;
    }
};
