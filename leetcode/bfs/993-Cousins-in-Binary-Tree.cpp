
#include <queue>
#include <unordered_map>

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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) return false;

        queue<TreeNode *> levelQueue;
        levelQueue.push(root);

        TreeNode *nodeX = nullptr, *nodeY = nullptr;
        unordered_map<TreeNode *, TreeNode *> record;

        while (!levelQueue.empty()) {
            // x、y 需要在同一层，并且其父亲节点不相同
            int size = levelQueue.size();

            for (int i = 0; i < size; i++) {
                TreeNode *current = levelQueue.front();
                levelQueue.pop();

                if (current->val == x) nodeX = current;

                else if (current->val == y) nodeY = current;

                if (current->left) {
                    record[current->left] = current;
                    levelQueue.push(current->left);
                }

                if (current->right) {
                    record[current->right] = current;
                    levelQueue.push(current->right);
                }
            }

            if (nodeX || nodeY) break;
        }

        if (nodeX && nodeY && record[nodeX] != record[nodeY]) 
            return true;
        return false;
    }
};
