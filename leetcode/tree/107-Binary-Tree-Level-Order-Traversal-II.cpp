#include <vector>
#include <queue>
#include<algorithm>

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
 * 和 107 号问题一毛一样，只不过不最终的结果数组 reverse 一下
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> result;

        if (root == NULL)
            return result;
        
        queue<TreeNode *> support_queue;

        support_queue.push(root);

        while (!support_queue.empty()) {
            vector<int> inner_reult;

            int current_queue_size = support_queue.size();
            for (int i = 0; i < current_queue_size; i++) {
                TreeNode *current = support_queue.front();

                inner_reult.push_back(current->val);
                support_queue.pop();

                if (current->left != NULL)
                    support_queue.push(current->left);
                
                if (current->right != NULL)
                    support_queue.push(current->right);
            }

            result.push_back(inner_reult);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};