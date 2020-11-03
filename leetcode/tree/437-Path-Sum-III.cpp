
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
 * 题解思路: 和 Path Sum II 不同的是， Path Sum III 并不要求起始位置为根节点， 同时也不要求结束位置为叶子节点
 * 对于前一个要求，我们可以将题解分为两部分思考: 
 *  - 首先找到以当前节点为起始位置的路径，这其实就是 Path Sum II，固定一个根节点，在下次递归调用时减去该节点的值
 *  - 另一部分就是不包含当前节点的路径，即在该节点的左子树、右子树中寻找路径
 */

class Solution {
private:
    /*
     * 返回以当前 root 为根路径、总和为 sum 的路径数
     */
    int findCurrentNodePathSum(TreeNode *root, int sum) {

        int result = 0;

        if (root == NULL) return 0;

        if (root->val == sum)
            result += 1;
        
        result += findCurrentNodePathSum(root->left, sum - root->val);
        result += findCurrentNodePathSum(root->right, sum - root->val);

        return result;
    }
public:
    int pathSum(TreeNode* root, int sum) {

        if(root == NULL) return 0;

        int result = 0;

        // 寻找包含当前节点且和为 sum 的路径和
        result += findCurrentNodePathSum(root, sum);

        // 寻找不包含当前节点的、和为 sum 的路径和，此时只需要递归的调用 pathSum 方法，并将 root 排除在外即可。
        result += pathSum(root->left, sum);
        result += pathSum(root->right, sum);

        return result;
    }
};