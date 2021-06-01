
/*
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 
 * 前序遍历: root - left - right
 * 中序遍历: left - root - right
 * 
 * 所以前序遍历的第一个节点一定是根节点，那么使用这个根节点在中序遍历上就可以找到左、右子树的节点，然后递归调用即可
 */


#include <vector>
#include <unordered_map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    TreeNode* buildTree(
            vector<int>& preorder, int preLeft, int preRight, 
            vector<int>& inorder, int midLeft, int midRight, 
            unordered_map<int, int>& auxilary) {
        
        if (preLeft > preRight || midLeft > midRight) return nullptr;

        TreeNode *root = new TreeNode(preorder[preLeft]);

        int inRootIndex = auxilary[root->val];
        int leftNums = inRootIndex - midLeft;

        root->left = buildTree(preorder, preLeft + 1, preLeft + leftNums, inorder, midLeft, inRootIndex - 1, auxilary);
        root->right = buildTree(preorder, preLeft + leftNums + 1, preRight, inorder, inRootIndex + 1, midRight, auxilary);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> auxilary;

        for (int i = 0; i < inorder.size(); i++) {
            auxilary[inorder[i]] = i;
        }

        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, auxilary);
    }
};