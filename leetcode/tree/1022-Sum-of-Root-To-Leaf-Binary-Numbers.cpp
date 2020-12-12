

#include <vector>
#include <limits.h>

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
 * 求二叉树路径所代表的的 bit 路径数字和，相当于就是求出二叉树 root 节点到叶子节点的全部路径
 */
class Solution {
private:
    int result = 0;
    void preorder(TreeNode *root, int sum) {
        if (root == nullptr) return ;
        // 到叶子节点即可
        if (root->left == nullptr && root->right == nullptr) {
            result += sum * 2 + root->val;
            return ;
        }
        sum = sum  * 2 + root->val;
        preorder(root->left, sum);
        preorder(root->right, sum);
        return ;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        preorder(root, 0);
        return result;
    }
};
