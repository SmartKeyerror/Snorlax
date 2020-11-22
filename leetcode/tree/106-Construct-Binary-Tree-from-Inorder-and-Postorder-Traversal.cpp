
#include <vector>
#include <unordered_map>

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
 * 从中序遍历和后序遍历中恢复一棵二叉树
 *   
 *   中序遍历: left - root - right
 *   后序遍历: left - right - root
 * 
 * 所以，后序遍历的最后一个元素必为根节点，拿着这个根节点去中序遍历的结果中就可以找到哪些是左子树节点，哪些是右子树节点了
 */
class Solution {
private:
    // 注意下 inRecord 是一个引用传值，按值传参的话会超时
    TreeNode *buildBST(vector<int>& inorder, int inLeft, int inRight, vector<int>& postorder, int postLeft, int postRight, unordered_map<int, int> &inRecord) {
        
        if (inLeft > inRight || postLeft > postRight) return nullptr;

        TreeNode *root = new TreeNode(postorder[postRight]);

        int inRoot = inRecord[root->val];

        int leftNums = inRoot - inLeft;

        root->left = buildBST(inorder, inLeft, inLeft + leftNums - 1, postorder, postLeft, postLeft + leftNums - 1, inRecord);

        root->right = buildBST(inorder, inLeft + leftNums + 1, inRight, postorder, postLeft + leftNums, postRight - 1, inRecord);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if (inorder.size() != postorder.size() || (inorder.size() == 0 && postorder.size() == 0))
            return nullptr;
        
        unordered_map<int, int> inRecord;

        for (int i = 0; i < inorder.size(); i++)
            inRecord[inorder[i]] = i;
        
        return buildBST(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inRecord);
    }
};
