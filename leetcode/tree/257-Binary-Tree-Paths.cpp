
#include <vector>
#include <string>

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
    vector<string> binaryTreePaths(TreeNode *root) {
        
        vector<string> result;
        result.clear();

        // 判断空树
        if (root == NULL)
            return result;
        
        // 递归终止条件: 由于所求的是路径字符串，所以递归到叶子节点即可
        if (root->left == NULL && root->right == NULL) {
            result.push_back(to_string(root->val));
            return result;
        }

        // 获取左子树路径
        vector<string> leftTreePaths = binaryTreePaths(root->left);
        for (int i = 0; i < leftTreePaths.size(); i++) {
            result.push_back(to_string(root->val) + "->" + leftTreePaths[i]);
        }

        // 获取右子树路径
        vector<string> rightTreePaths = binaryTreePaths(root->right);
        for (int i = 0; i < rightTreePaths.size(); i++) {
            result.push_back(to_string(root->val) + "->" + rightTreePaths[i]);
        }

        return result;
    }
};