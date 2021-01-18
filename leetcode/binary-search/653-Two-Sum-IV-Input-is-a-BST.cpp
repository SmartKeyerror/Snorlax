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
 * 在一棵 BST 中判断是否存在 Two Sum 的问题，遇到 BST，首先想到的就是中序遍历
 * 
 * 首先来看能不能在原树上解决这个问题。如果使用二分搜索的方式的话，一定需要最初的 left 以及 right 指针，这个东西需要递归遍历得到，而且指针移动的代价很高，所以放弃在原🌲上解决。
 * 
 * 既然如此，那就中序遍历到一个 vector 中，然后二分搜索处理。
 */
class Solution {
private:
    void midorder(TreeNode* root, vector<int>& vals) {
        if (root == nullptr) return;
        midorder(root->left, vals);
        vals.push_back(root->val);
        midorder(root->right, vals);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> vals;
        midorder(root, vals);

        int left = 0, right = vals.size() - 1;
        while (left < right) {
            if (vals[left] + vals[right] == k) break;
            else if (vals[left] + vals[right] > k) right --;
            else left ++;
        }
        return vals[left] + vals[right] == k && left != right;
    }
};