#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodes(struct TreeNode* root){
    if (root == NULL) return 0;

    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);

    return leftNodes + rightNodes + 1;
}