#include <vector>
#include <stack>

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
private:
    vector<int> result;

    vector<int> recursiveSolution(TreeNode *root) {
        result.clear();
        postorder(root);
        return result;
    }

    void postorder(TreeNode *root) {
        if (root == NULL) return;

        postorder(root->left);
        postorder(root->right);
        result.push_back(root->val);
        return;
    }

    vector<int> stackSolution(TreeNode *root) {
        if (root == nullptr) return result;

        TreeNode *current = root, *prev = nullptr;
        stack<TreeNode *> st;

        while (!st.empty() || current != nullptr) {
            // 首先将所有的左子树入栈
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            current = st.top();

            if (current->right == nullptr || current->right == prev) {
                result.push_back(current->val);
                st.pop();
                prev = current;
                current = nullptr;
            } else {
                current = current->right;
            }
        }
        return result;
    }


public:
    vector<int> postorderTraversal(TreeNode* root) {
        // return recursiveSolution(root);
        return stackSolution(root);
    }
};
