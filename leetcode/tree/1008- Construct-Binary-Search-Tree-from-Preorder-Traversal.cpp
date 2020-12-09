
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
 * 从前序遍历的结果中恢复一棵二分搜索树
 * 
 * 前序遍历: root - left - right，那么结果数组中的第一个元素必然为 BST 的根。
 * 除此以外，其实没什么更有价值的信息了。既可以循环遍历的方式，也可以使用递归找中点的方式来构造 BST
 */
class Solution {

private:

    TreeNode *buildBST(vector<int>& preorder, int start, int end) {

        if (start > end)
            return nullptr;
        
        int mid = start + 1;

        while (mid <= end && preorder[mid] < preorder[start])
            mid ++;
        
        TreeNode *root = new TreeNode(preorder[start]);

        root->left = buildBST(preorder, start + 1, mid - 1);
        root->right = buildBST(preorder, mid, end);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        if (preorder.size() == 0)
            return nullptr;
        
        return buildBST(preorder, 0, preorder.size() - 1);
    }
};
