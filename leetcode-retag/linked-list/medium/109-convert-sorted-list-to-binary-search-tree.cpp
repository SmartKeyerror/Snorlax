
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 首先，二叉树的构建问题一定是一个前序遍历的过程，每次都会首先构建根节点，然后再去构建左、右子树。
 * 
 * 如果是一个有序列表的话，这个问题就会变得很简单，那么我们就可以使用空间换时间的方式来完成这件事情。
 */

class Solution {
private:
    TreeNode *buildBST(const vector<int>& values, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode *root = new TreeNode(values[mid]);

        root->left = buildBST(values, left, mid - 1);
        root->right = buildBST(values, mid + 1, right);

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> values;
        ListNode *current = head;

        while (current != nullptr) {
            values.push_back(head->val);
            current = current->next;
        }
        return buildBST(values, 0, values.size() - 1);
    }
};