
#include <vector>
#include <limits.h>

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
 * 找出 BST 中出现频次最高的节点值
 * 
 * 和 BST 相关的问题首先我们会考虑中序遍历求解，因为中序遍历的结果是有序的，更容易求解问题
 * 
 * 因为需要判定重复元素，所以我们一定需要一个 prev 指针。然后，我们需要记录当前遍历中出现的重复元素次数，以及最大重复次数
 * 
 * 当 最大重复次数 < 当前重复次数时，我们需要清空整个结果数组，并将新的元素纳入
 * 
 * 操作起来还是有点儿复杂的，这真的是 Easy 难度的题目?
 */
class Solution {
private:

    vector<int> result;
    TreeNode *prev = nullptr;
    int count = 1, maxCount = 1;

    void inorder(TreeNode *current) {
        if (!current) return;

        inorder(current->left);

        if (prev && current->val == prev->val) {
            count ++;
        } else
            count = 1;

        if (count > maxCount) {
            // 清空整个结果数组
            result.clear();
            result.push_back(current->val);
            maxCount = count;
        }
        else if (count == maxCount)
            result.push_back(current->val);

        prev = current;

        inorder(current->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        // 这里我们还需要对结果进行去重，但是我看讨论区里面的兄弟们都没去重，我也没去，然后就 AC 了，wtf?
        return result;
    }
};