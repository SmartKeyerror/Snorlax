
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


/*
 * 输入两棵二叉树 A 和 B，判断 B 是不是 A 的子结构。(约定空树不是任意一个树的子结构)
 * 
 * B 是 A 的子结构， 即 A 中有出现和 B 相同的结构和节点值。
 * 
 * 假如给定两棵二叉树 A、B，并要求判断它们是不是相同的树（Same Tree）的话，
 * 我们只需要从两棵树的根节点出发，逐一对比根节点、左孩子和右孩子即可，也就是使用一个前序遍历的方式完成。
 * 
 * 而对于子树这道题来说，我们不清楚 A 的起始节点到底是哪一个，所以我们需要逐一的使用 A 中每一个节点充当根节点，然后再进行判断。
 * 
 * 需要注意的是，这道题和 Leetcode 572.subtree of another tree 的条件有稍许区别
 */
class Solution {
private:
    // 使用前序遍历的方式判断 A、B 是否有同一个结构
    bool sameTree(TreeNode* A, TreeNode* B) {
        if (B == nullptr) return true;

        if (A == nullptr) return false;

        if (A->val != B->val) return false;

        if (!sameTree(A->left, B->left)) return false;

        if (!sameTree(A->right, B->right)) return false;

        return true;
    }
public:
    // 时间复杂度 O(mn)，空间复杂度 O(max(h1, h2))
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        // 边界条件判断: 约定空树不是任意一个树的子结构
        if (A == nullptr || B == nullptr) return false;

        // 逐一遍历 A 中的所有节点作为根节点，判断是否为相同的树
        if (sameTree(A, B)) return true;

        if (isSubStructure(A->left, B)) return true;

        if (isSubStructure(A->right, B)) return true;

        return false;
    }
};