
#include <vector>
#include <limits.h>
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
 * 求 BST 中最小的绝对距离，也就是任意两个节点间的最小 val 差。
 * 中序遍历得到有序的结果之后在结果数组中寻找即可
 */
class Solution {

    vector<int> traversalRes;

    void inOrder(TreeNode* root) {
        if (root == nullptr) return ;
        inOrder(root->left);
        traversalRes.push_back(root->val);
        inOrder(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);

        int res = INT_MAX;
        for (int i = 1; i < traversalRes.size(); i++) 
            if (traversalRes[i] - traversalRes[i-1] < res)
                res = traversalRes[i] - traversalRes[i-1];
        return res;
    }
};
