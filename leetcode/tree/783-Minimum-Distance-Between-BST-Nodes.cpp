
#include <limits.h>
#include <algorithm>
#include <math.h>

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
 * 求 BST 中两个节点间的最小距离。由于是 BST，所以只需要维护一个 prev 指针，让其指向在 inorder 过程中 root 指针所指向的前一个指针即可。
 */
class Solution {
private:
    TreeNode *prev;
    int result = INT_MAX;

    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);

        if (prev != nullptr)
            result = min(result, abs(root->val - prev->val));
        
        prev = root;

        inorder(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return result;
    }
};
