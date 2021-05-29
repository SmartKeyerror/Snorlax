
#include <vector>
#include <stack>
#include <limits>

using namespace std;


/*
 * 二叉树的前序遍历: 时间复杂度 O(n)，空间复杂度 O(h)，h 为最大树高
 * 
 * 前序遍历有哪些应用? 验证 BST 是否合法
 * 
 * BST 的定义: 
 *  - 根结点的值大于所有的左子树结点的值
 *  - 根结点的值小于所有的右子树结点的值
 *  - 左右子树也必须满足以上特性
 * 
 * 可以看到，BST 的定义其实就是按照前序遍历的方式进行定义的，不管是 root-left-right，还是 root-right-left，
 * 根节点的值必须大于等于左子树所有节点的值，小于等于右子树所有节点的值。因此，我们可以通过前序遍历来检验 BST 是否正确
 * 
 * Leetcode 98. Validate Binary Search Tree，就是验证 BST 的一道题目，题目难度为 Medium，Accepted： 995,278     Submissions： 3,420,348
 * 
 * 我们可以这样来思考，假设根节点总是正确的，那么根节点值域应该在 [INT_MIN, INT_MAX] 之间，当我们遍历到根节点时，即可确认左、右子树的值域范围:
 * 
 * - 左子树的值域为 [INT_MIN, root->value]
 * - 右子树的值域为 [root->value, INT_MAX]
 * 
 * 左右子树同样满足此性质
 * 
class Solution {
private:
    bool answer;

    // 检验以 root 为根，且 root 值域在 [left, right] 的 BST 是否正确
    void verifyBST(TreeNode *root, long left, long right) {
        if (!root || !answer) return;

        // 验证根节点
        answer = root->val > left && root->val < right;

        if (!answer) return;

        // 验证左子树
        verifyBST(root->left, left, root->val);

        // 验证右子树
        verifyBST(root->right, root->val, right);
    }
public:
    bool isValidBST(TreeNode* root) {
        answer = true;
        verifyBST(root, LONG_MIN, LONG_MAX);
        return answer;
    }
};
 * 
 * 
 * 
 */


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

    void preorder(TreeNode *root) {
        if (root == NULL) return;

        result.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
        return;
    }

    vector<int> recursiveSolution(TreeNode *root) {
        result.clear();
        preorder(root);
        return result;
    }

    vector<int> stackSolution(TreeNode *root) {
        result.clear();
        stack<TreeNode *> st;
        
        if (!root) return result;

        st.push(root);

        while (!st.empty()) {
            TreeNode *current = st.top();
            st.pop();

            result.push_back(current->val);

            if (current->right) st.push(current->right);

            if (current->left) st.push(current->left);
        }

        return result;
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        // return recursiveSolution(root);
        return stackSolution(root);

        
    }
};
