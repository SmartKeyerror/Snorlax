
#include <vector>
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

/*
 * 寻找二叉树每一层的最大值，层序遍历没跑了
 * (另外，这道题的难度竟然是 Medium?)
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;

        if (root == nullptr) return result;

        queue<TreeNode *> levelQueue;
        
        levelQueue.push(root);

        while (!levelQueue.empty()) {

            int size = levelQueue.size(), curMax = INT_MIN;
            while (size--) {
                TreeNode *current = levelQueue.front();

                if (current->val > curMax) curMax = current->val;

                levelQueue.pop();

                if (current->left)
                    levelQueue.push(current->left);
                
                if (current->right)
                    levelQueue.push(current->right);
            }
            result.push_back(curMax);
        }

        return result;
    }
};
