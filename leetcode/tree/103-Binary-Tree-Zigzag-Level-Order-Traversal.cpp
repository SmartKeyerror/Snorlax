
#include <vector>
#include <queue>
#include <algorithm>

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
 * "之"字形的二叉树的广度优先遍历
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int level = 0;
        vector<vector<int>> result;
        TreeNode *current = root;

        if (root == nullptr)
            return result;

        queue<TreeNode *> levelQueue;

        levelQueue.push(current);

        while (!levelQueue.empty()) {
            vector<int> inner;

            int size = levelQueue.size();

            for (int i = 0; i < size; i++) {
                current = levelQueue.front();
                inner.push_back(current->val);
                levelQueue.pop();

                if (current->left) levelQueue.push(current->left);

                if (current->right) levelQueue.push(current->right);
            }

            if (level % 2 == 1)
                reverse(inner.begin(), inner.end());

            level ++;
            result.push_back(inner);
        }
        return result;
    }
};