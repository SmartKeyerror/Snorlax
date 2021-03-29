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
 * 合并两个 BST，两个方法:
 * 
 * - 遍历两棵二分搜索树，结果保存在一个 vector 中，然后快排解决，时间复杂度 2n + nlogn，空间复杂度 2n
 * - 遍历两棵二分搜索树，结果保存在两个 vector 中，然后使用归并解决，时间复杂度 2n + 2n，空间复杂度 3n
 * 
 * 两个方法效率上不会差太多。
 */
class Solution {
private:
    void dfs(TreeNode *root, vector<int>& elements) {
        if (root == nullptr) return;
        dfs(root->left, elements);
        elements.push_back(root->val);
        dfs(root->right, elements);
        return;
    }

    vector<int> merge_sorted_list(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size(), n2 = v2.size();
        vector<int> result(n1 + n2, 0);
        
        int i = 0, j = 0, k = 0;
        while (k < n1 + n2) {
            if (i >= n1) {
                result[k] = v2[j];
                j++, k++;
                continue;
            }

            if (j >= n2) {
                result[k] = v1[i];
                i++, k++;
                continue;
            }

            if (v1[i] < v2[j]) {
                result[k] = v1[i];
                i++, k++;
            }

            else {
                result[k] = v2[j];
                j++, k++;
            }
        }
        return result;
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        dfs(root1, v1), dfs(root2, v2);
        return merge_sorted_list(v1, v2);
    }
};