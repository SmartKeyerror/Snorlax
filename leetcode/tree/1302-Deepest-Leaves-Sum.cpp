
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


class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;
        queue<TreeNode *> levelQueue;
        levelQueue.push(root);

        while (!levelQueue.empty()) {
            int size = levelQueue.size();

            res = 0;

            for (int i = 0; i < size; i++) {
                TreeNode *current = levelQueue.front();
                levelQueue.pop();

                res += current->val;

                if (current->left) levelQueue.push(current->left);
                if (current->right) levelQueue.push(current->right);
            }
        }
        return res;
    }
};
