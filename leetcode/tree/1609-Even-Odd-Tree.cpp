
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
 * 层数从 0 开始计算，偶数层中的节点都应该是奇数，并且从左至右递增；奇数层应该都是偶数，并且从左至右递减。
 * 
 * 层序遍历一把梭即可。
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode *> levelQueue;
        levelQueue.push(root);

        int curLevel = 0;

        while (!levelQueue.empty()) {
            int size = levelQueue.size();
            
            TreeNode *prev = nullptr;

            for (int i = 0; i < size; i++) {
                TreeNode *current = levelQueue.front();
                levelQueue.pop();

                if (curLevel & 1) {
                    // 奇数层
                    if (current->val & 1) return false;
                    if (prev != nullptr && current->val >= prev->val) return false;
                } else {
                    // 偶数层
                    if (!(current->val & 1)) return false;
                    if (prev != nullptr && current->val <= prev->val) return false;
                }

                prev = current;

                if (current->left) levelQueue.push(current->left);
                if (current->right) levelQueue.push(current->right);
            }
            curLevel ++;
        }
        return true;
    }
};