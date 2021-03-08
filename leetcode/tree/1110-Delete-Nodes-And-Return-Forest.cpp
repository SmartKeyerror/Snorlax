
#include <vector>
#include <unordered_set>

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
 * 挺有意思的一道问题，删除二叉树中的部分节点，返回删除节点后形成的森林。
 */
class Solution {
public:
    TreeNode* dfs(TreeNode *root, vector<TreeNode*>& results, unordered_set<int>& delete_nodes) {
        if (root == nullptr) return nullptr;

        root->left = dfs(root->left, results, delete_nodes);
        root->right = dfs(root->right, results, delete_nodes);

        // 判断当前根节点是否在待删除节点集合内
        if (delete_nodes.count(root->val) == 0) return root;

        if (root->left != nullptr) results.push_back(root->left);

        if (root->right != nullptr) results.push_back(root->right);

        return nullptr;

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        unordered_set<int> delete_nodes;

        for (int num : to_delete) delete_nodes.insert(num);

        if (delete_nodes.count(root->val) == 0) result.push_back(root);

        dfs(root, result, delete_nodes);

        return result;
    }
};