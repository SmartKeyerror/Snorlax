
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
 * 严格意义上来说，该题考察的是对 队列 这一数据结构的熟练使用， 和树其实没多大关系
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

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

        return result;
    }
};