
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
 * 返回二叉树的“右视图”，其实就是每一层中最右边的元素，队列实现即可。
 * 如果题目修改要求，求“左视图”的话，对代码稍加修改即可
 */
class Solution {
private:
    vector<int> res;
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return res;

        TreeNode *current = root;
        queue<TreeNode *> levelQueue;

        levelQueue.push(current);

        while (!levelQueue.empty()) {
            int queueSize = levelQueue.size();
            
            // 如果要求“左视图”的话， levelQueue.back() 替换成 levelQueue.front() 即可
            res.push_back(levelQueue.back()->val);
            
            for (int i = 0; i < queueSize; i++) {
                current = levelQueue.front();
                levelQueue.pop();

                if (current->left) levelQueue.push(current->left);

                if (current->right) levelQueue.push(current->right);
            }
        }
        return res;
    }
};
