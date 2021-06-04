
#include <vector>
#include <limits.h>
#include <stack>

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
    // 在 [start, end] 的范围内构造 BST，preorder[start] 必然为根节点
    TreeNode *buildBST(vector<int>& preorder, int start, int end) {

        if (start > end) return nullptr;
        
        int mid = start + 1;

        // 找到第一个大于当前根节点的元素索引，作为左、右孩子的分界点
        // 如 [12, 8, 6, 7, 9, 18, 16, 15]，根节点为 12，前序遍历的结果为 root-left-right
        // 所以我们需要使用 12 来找到右子树的第一个节点，也就是 18
        while (mid <= end && preorder[mid] < preorder[start])
            mid ++;
        
        TreeNode *root = new TreeNode(preorder[start]);

        // 构造左子树
        root->left = buildBST(preorder, start + 1, mid - 1);
        // 构造右子树
        root->right = buildBST(preorder, mid, end);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        if (preorder.size() == 0) return nullptr;
        
        // 维护单调递增栈
        stack<TreeNode*> st;

        // 首先创建出根节点，然后扔到 stack 里面儿
        TreeNode* root =  new TreeNode(preorder[0]);
        st.push(root);

        // 根节点我们单拎出来了，所以 i 从 1 开始遍历
        for (int i = 1; i < preorder.size(); i++) {
            int value = preorder[i];

            TreeNode *current = new TreeNode(value);

            if (value < st.top()->val) {
                // 此时当前节点必然是栈顶元素的左孩子节点
                st.top()->left = current;
            } else {
                // 这时候我们得找到当前节点的父亲节点，也就是左边儿第一个小于它的节点
                TreeNode *parrent = nullptr;
                while (!st.empty() && value > st.top()->val) {
                    parrent = st.top();
                    st.pop();
                }
                parrent->right = current;
            }
            st.push(current);
        }

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        if (preorder.size() == 0)
            return nullptr;
        
        return buildBST(preorder, 0, preorder.size() - 1);
    }
};
