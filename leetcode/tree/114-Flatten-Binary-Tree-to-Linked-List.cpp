

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
 * 将一棵二叉树展开成一个链表
 *     
       1           
      / \
     2   5
    / \   \
   3   4   6

 * 展开的链表结构为 1-2-3-4-5-6，结果为前序遍历结果，但是在实际的展开过程中，首先要访问左、右两棵子树。
 * 
 * 首先使用临时变量来保存右子节点，然后断开当前节点与右子节点的连接，将左子节点套在右子节点上，再然后把使用临时变量存储的右子节点套在新的右子节点的右子节点上
 * 
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        if (root->left != nullptr)
            flatten(root->left);
        
        if (root->right != nullptr)
            flatten(root->right);
        
        TreeNode *temp = root->right;
        
        root->right = root->left;
        root->left = nullptr;

        // 找到新的右子节点的最后一个右子节点
        while (root->right != nullptr)
            root = root->right;
        
        root->right = temp;
    }
};
