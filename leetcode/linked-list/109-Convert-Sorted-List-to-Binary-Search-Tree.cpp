

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
 * 将一个有序链表转换成 BST，最简单的办法就是将其扔到一个列表中，而后由列表构建，即每次取数组的中点作为 root 构建
 * 
 * Runtime: 28 ms, faster than 96.48% of C++ online submissions for Convert Sorted List to Binary Search Tree.
 * Memory Usage: 33.5 MB, less than 18.23% of C++ online submissions for Convert Sorted List to Binary Search Tree.
 * 
 * 空间换时间，ᕕ( ᐛ )ᕗ
 */
class Solution {
private: 
    TreeNode* sortedVectorToBST(vector<int> &nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedVectorToBST(nums, left, mid - 1);
        root->right = sortedVectorToBST(nums, mid + 1,right);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int> nums;
        ListNode *current = head;

        while (current) {
            nums.push_back(current->val);
            current = current->next;
        }

        return sortedVectorToBST(nums, 0, nums.size() - 1);
    }
};