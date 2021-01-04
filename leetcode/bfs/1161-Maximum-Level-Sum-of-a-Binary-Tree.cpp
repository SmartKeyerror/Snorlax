
#include <queue>
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


class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maximal = INT_MIN;
       int level = 0, result = 0;
        queue<TreeNode *> levelQueue;
        levelQueue.push(root);

        while (!levelQueue.empty()) {
            int size = levelQueue.size(), sum = 0;
            level ++;
            for (int i = 0; i < size; i++) {
                TreeNode *current = levelQueue.front();
                levelQueue.pop();
                sum += current->val;
                if (current->left) levelQueue.push(current->left);
                if (current->right) levelQueue.push(current->right);
            }
            if (sum > maximal) {
                result = level;
                maximal = sum;
            }
        }
        return result;
    }
};