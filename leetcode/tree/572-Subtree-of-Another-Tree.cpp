
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * 判断 t 是否是 s 的子树，需要完全相同，而不是部分相同
 */
class Solution {
    bool dfs(TreeNode* s, TreeNode* t) {
        if (s == nullptr) return t == nullptr;
        if (t == nullptr) return s == nullptr;

        bool left = dfs(s->left, t->left);
        bool right = dfs(s->right, t->right);

        return s->val == t->val && left && right;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {

        if (s == nullptr) return (t == nullptr);
        if (t == nullptr) return (s == nullptr);

        bool result = false;

        if (s->val == t->val)
            result = dfs(s, t);
        if (result) return true;

        bool left = isSubtree(s->left, t);
        if (left) return true;

        bool right = isSubtree(s->right, t);
        if (right) return true;

        return false;
    }
};
