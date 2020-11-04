
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
 * 使用队列进行层序遍历，最后一层的第一个节点就是结果
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {

        // 题干也给出 root 不为 NULL，所以可不进行空指针判断

        int result;

        queue<TreeNode *> levelQueue;
        levelQueue.push(root);

        while (!levelQueue.empty()) {

            int size = levelQueue.size();

            // 此时队列的首个元素就是当前 level 的最左节点
            result = levelQueue.front()->val;

            // 能用 while 的尽量用 while，for 循环会有效率问题
            while (size--) {
                TreeNode *current = levelQueue.front();

                levelQueue.pop();

                if (current->left)
                    levelQueue.push(current->left);
                
                if (current->right)
                    levelQueue.push(current->right);
            }
        }

        return result;
    }
};