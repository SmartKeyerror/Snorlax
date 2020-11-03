
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode* root, int *sum) {
    if (root == NULL) return;

    if (root->left != NULL)
        if (root->left->left == NULL && root->left->right == NULL)
            *sum += root->left->val;
    
    dfs(root->left, sum);
    dfs(root->right, sum);
}

int sumOfLeftLeaves(struct TreeNode* root){

    int sum = 0;

    dfs(root, &sum);

    return sum;
}
