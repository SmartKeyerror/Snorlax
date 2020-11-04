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


class Solution {
private:

    // 返回包含当前根节点的最大路径和
    int currentNodeMaxPathSum(TreeNode *root, int &result) {
        if (root == NULL)
            return 0;

        int leftMaxSum = currentNodeMaxPathSum(root->left, result);
        int rightMaxSum = currentNodeMaxPathSum(root->right, result);

        /*
         * 当前节点的最大路径和的情况:
         *  - root->val
         *  - leftMaxSum + root->val
         *  - rightMaxSum + root->val
         *  - leftMaxSum + rightMaxSum + root->val
         */

        // 首先获取左右子树中的最大路径和
        int childMaxSum = max(leftMaxSum, rightMaxSum);

        // 再来看 childMaxSum + root->val 和 root->val 之间的最大值
        int notSureMax = max(childMaxSum + root->val, root->val);

        int maxSum = max(notSureMax, leftMaxSum + rightMaxSum + root->val);

        // 在递归的过程中即更新最终结果
        result = max(maxSum, result);

        return notSureMax;
    }

public:
    int maxPathSum(TreeNode* root) {

        if (root == NULL) 
            return 0;
        
        int result = INT_MIN;

        currentNodeMaxPathSum(root, result);

        return result;
    }
};