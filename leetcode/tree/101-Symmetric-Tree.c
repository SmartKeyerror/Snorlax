#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSymmetricChild(struct TreeNode *left, struct TreeNode *right);

bool isSymmetric(struct TreeNode* root){

    if (root == NULL) return true;

    return isSymmetricChild(root->left, root->right);

}

// 判断以 left、right 为根的两棵子树是否镜像对称
bool isSymmetricChild(struct TreeNode *left, struct TreeNode *right) {
    if (left == NULL || right == NULL) return left == right;

    if (left->val != right->val) return false;

    return isSymmetricChild(left->left, right->right) && isSymmetricChild(left->right, right->left);
}