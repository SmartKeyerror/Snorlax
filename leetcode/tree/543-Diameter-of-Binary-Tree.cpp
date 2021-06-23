#include <algorithm>

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
 * 求二叉树的最大展开直径，该最大展开直径中可能不包含根节点
 * 
 *          15
 *         /  \
 *        22  55
 *       /  \
 *      1   11
 *     /      \
 *    9        18
 * 
 * 如上所示，此时的最大展开直径路径为 9-1-22-11-18，并不包含根节点 15
 * 
 * 对于某一个根节点而言，其最大展开直径为: 左子树最大树高 + 右子树最大树高。
 * 
 * 所以，我们的递归函数要做的就是求解某一个节点的最大树高，由外部变量来维护最大展开直径
 * 
 * Runtime: 8 ms, faster than 88.69% of C++ online submissions for Diameter of Binary Tree.
 * Memory Usage: 20.8 MB, less than 93.83% of C++ online submissions for Diameter of Binary Tree.
 * 
 */
class Solution {
private:

    int maxDiameter = 0;

    int postOrder(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int left = postOrder(root->left);
        int right = postOrder(root->right);

        maxDiameter = max(maxDiameter, left + right);

        return left > right ? left + 1: right + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        postOrder(root);
        return maxDiameter;
    }
};
