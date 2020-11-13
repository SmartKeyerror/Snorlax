
#include <vector>
#include <stack>
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


/*
 * Runtime: 12 ms, faster than 85.12% of C++ online submissions for Smallest String Starting From Leaf.
 * Memory Usage: 19.9 MB, less than 79.57% of C++ online submissions for Smallest String Starting From Leaf.
 */
class Solution {
private:
    string result;

    string generateStrFromVector(vector<int> &paths) {
        string s;
        for (int i = paths.size() - 1; i >= 0; i--) {
            s.push_back(char(paths[i] + 97));
        }
        return s;
    }

    void dfs(TreeNode* root, vector<int> &paths) {
        if (root == nullptr) return;

        paths.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            string s = generateStrFromVector(paths);

            if (result.compare("A") == 0)
                result = s;
            
            else if (s.compare(result) < 0)
                result = s;

            paths.pop_back();
            return;
        }

        dfs(root->left, paths);
        dfs(root->right, paths);

        paths.pop_back();

        return;
    }
public:
    string smallestFromLeaf(TreeNode* root) {

        // 将 result 初始化成 A, 据此判断是否是初次达到叶子节点
        result = "A";
        
        vector<int> paths;
        dfs(root, paths);

        return result;
    }
};