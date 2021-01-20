
#include <unordered_set>

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
 * 这道题的难度是 Medium 是我没想到的，中序遍历 + hashset 记录节点值即可。
 */
class FindElements {
private:

    unordered_set<int> record;

    void recoverContaminatedTree(TreeNode* root, int val) {
        if (root== nullptr) return ;

        root->val = val;
        record.insert(val);

        recoverContaminatedTree(root->left, 2 * val + 1);
        recoverContaminatedTree(root->right, 2 * val + 2);
    }
public:
    FindElements(TreeNode* root) {
        recoverContaminatedTree(root, 0);
    }
    
    bool find(int target) {
        return record.count(target);
    }
};
