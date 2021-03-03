
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;

        if (root == nullptr) return result;

        queue<TreeNode *> levelQueue;
        levelQueue.push(root);

        while (!levelQueue.empty()) {
            int size = levelQueue.size();

            double sum = 0.0;
            for (int i = 0; i < size; i++) {
                TreeNode *current = levelQueue.front();
                levelQueue.pop();

                sum += current->val;

                if (current->left) levelQueue.push(current->left);
                if (current->right) levelQueue.push(current->right);
            }

            result.push_back(sum / size);
        }
        return result;
    }
};