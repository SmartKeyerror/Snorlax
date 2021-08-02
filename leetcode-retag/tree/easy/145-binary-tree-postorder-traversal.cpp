
#include <stack>
#include <vector>

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
 * 给定一个二叉树，返回它的后序遍历
 * 
 * 后序遍历: 遍历左子树-遍历右子树-遍历根节点
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        if (root == nullptr) return result;

        stack<TreeNode *> st;

        TreeNode *current = root, *prev = nullptr;

        while (!st.empty() || current != nullptr) {
 
            // 首先将所有的左子树入栈
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            // 获取栈顶节点，但是我们不能将其 pop
            /*
             *       10
             *      /  \
             *     15   20
             *       \
             *        50
             * 
             * 比如这种情况，此时栈顶元素为 15，但是是一棵子树的根节点，此时我们应该先处理其右子树
             */
            current = st.top();

            // 如果当前节点的右子树为空，或者是已经被访问过了的话，直接 pop
            if (current->right == nullptr || prev == current->right) {
                st.pop();
                result.push_back(current->val);
                prev = current;
                current = nullptr;
            } else {
                current = current->right;
            }
        }
    }
};
