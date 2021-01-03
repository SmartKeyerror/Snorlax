#include <math.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
 * 将 N 个金币平均地分配给二叉树中每一个节点，使得每一个节点都有一个金币。
 * 
 * 我们需要从叶子节点开始进行处理，因为假设叶子节点没有金币，那么必然需要从其父亲节点搬运金币过来进行填充，叶子节点没有孩子节点，所以只能从父亲节点搬过来。
 * 
 * 如果叶子节点的金币数超过 1 的话，那么很明显的，需要将这些金币搬到其父亲节点，然后由父亲节点统一进行分配，要么丢给左孩子，要么丢给其祖先节点。
 * 
 * 所以，必须使用 postorder 进行实现。
 */
class Solution {
private:
    int result = 0;

    int dfs(TreeNode *root) {
        if (!root) return 0;

        // 获取左右子树缺少的，或者是多出的金币总数
        int left = dfs(root->left);
        int right = dfs(root->right);

        result += abs(left) + abs(right);

        return left + right + root->val - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return result;
    }
};
