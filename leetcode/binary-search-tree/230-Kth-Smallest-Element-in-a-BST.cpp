
#include <vector>
#include <assert.h>

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
 * 寻找 BST 中 第 K 小的节点值
 * 对于一棵 BST 而言，其 中序遍历 的结果就是一个有序列表，其中最简单粗暴的方法就是把整个 BST 遍历一遍放入数组，然后在数组中寻找即可。
 * 借助上面的思路，其实不用完全地遍历整棵树，只要数组的 size 和 k 相同即可，那么此时中序遍历所得到的结果数组中，最后一个元素就是第 k 小的值
 */

class Solution {
private:
    vector<int> result;
    void midorder_dfs(TreeNode* root, int k) {
        if (root == NULL) return;

        midorder_dfs(root->left, k);

        result.push_back(root->val);
        if (result.size() == k) return;

        midorder_dfs(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {

        assert(k > 0 && root != NULL);

        result.clear();

        midorder_dfs(root, k);

        assert(k <= result.size());

        return result[k-1];
    }
};
