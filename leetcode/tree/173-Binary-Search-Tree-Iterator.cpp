

#include <vector>

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
 * 中序遍历一次将 BST 中所有的元素打到 vector 中，由 vector 来提供迭代器相关的功能
 */
class BSTIterator {
private:

    vector<int> nodes;
    vector<int>::iterator iter;

    void inTraversal(TreeNode* root) {
        if (root == nullptr) return;
        inTraversal(root->left);
        nodes.push_back(root->val);
        inTraversal(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        inTraversal(root);
        iter = nodes.begin();
    }
    
    /** @return the next smallest number */
    int next() {
        return *iter++;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return iter != nodes.end();
    }
};
