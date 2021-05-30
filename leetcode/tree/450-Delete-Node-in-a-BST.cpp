

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
    // 获取以 root 为根的二叉搜索树的最小节点，也就是最左边儿的那个节点
    TreeNode *getMinimum(TreeNode *root) {
        if (!root->left)
            return root;
        return getMinimum(root->left);
    }

    // 删除以 root 为根的二叉搜索树的最小节点，并返回新的根节点
    TreeNode *removeMinmum(TreeNode *root) {
        if (root->left == nullptr) {
            TreeNode *rightNode = root->right;
            delete root;
            return rightNode;
        }
        root->left = removeMinmum(root->left);
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;

        // 左子树瞧一瞧
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else {
            // 待删除节点只有左子树的情况
            if (!root->right) {
                TreeNode *leftNode = root->left;
                delete root;
                return leftNode;
            }

            // 待删除节点只有右子树的情况
            if (!root->left) {
                TreeNode *rightNode = root->right;
                delete root;
                return rightNode;
            }

            // 待删除节点既有左子树，又有右子树，那么首先找到后继节点

            // 构造一个新的节点
            TreeNode *successor = new TreeNode(getMinimum(root->right)->val);

            // 挂接上原来的左、右子树
            successor->right = removeMinmum(root->right);
            successor->left = root->left;

            delete root;

            return successor;
        }
    }
};