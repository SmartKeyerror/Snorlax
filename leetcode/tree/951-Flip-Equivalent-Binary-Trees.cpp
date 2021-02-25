
#include <unordered_map>
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
 * 不管怎么翻转，每一个节点的左右孩子节点一定是相同的，如果不相同，那么说明 Tree-A 不能通过 flip 成为 Tree-B。
 * 
 * 所以第一种方法就是将整个 🌲 记录下来，记录每一个节点以及每一个节点的左右孩子节点，最后再进行比较即可。
 * 
 * 另一种方式就是直接使用 DFS 进行比较，对于 Tree-A 的某一个节点来说，要么 flip 左孩子，要么 flip 右孩子，不可能两个节点都 flip.
 */
class Solution {
public:
    void getTree(TreeNode *root, unordered_map<int, unordered_set<int>>& record) {
        if (root == nullptr) return;

        record[root->val] = {};
        if (root->left)
            record[root->val].insert(root->left->val);
        if (root->right)
            record[root->val].insert(root->right->val);
        
        getTree(root->left, record);
        getTree(root->right, record);
    }

    bool mapSolutioon(TreeNode* root1, TreeNode* root2) {
        unordered_map<int, unordered_set<int>> record1, record2;
        getTree(root1, record1);
        getTree(root2, record2);
        return record1 == record2;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;

        if (root1 == nullptr && root2 != nullptr) return false;

        if (root1 != nullptr && root2 == nullptr) return false;

        if (root1->val != root2->val) return false;

        bool noFlipRes = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);

        if (noFlipRes) return true;

        return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
    }
};