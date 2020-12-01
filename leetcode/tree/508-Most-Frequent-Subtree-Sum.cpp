

#include <vector>
#include <unordered_map>

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
 * 求出现频率最高的子树和，子树和的定义为 left + right + root
 * 
 * 依旧使用 DFS 遍历整颗树，由于子树和可以分为3部分: left, right, left + right + root，所以使用后序遍历实现。
 * 
 * 比较蛋疼的地方在于频率计算，可以使用 vector 在遍历的过程中维护，也可以使用 map 在遍历完成以后再挑选出频率最高的和
 * 
 * 作为一只合格的菜鸡，我选择 HashMap
 */
class Solution {
private:
    unordered_map<int, int> frequency;

    int postOrder(TreeNode *root) {
        if (root == nullptr) return 0;

        int left = postOrder(root->left);
        int right = postOrder(root->right);

        frequency[root->val + left + right] ++;
        return root->val + left + right;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        postOrder(root);

        int maxFreq = 0;
        vector<int> res;

        for (auto &freq: frequency) {
            if (freq.second > maxFreq) {
                res.clear();
                res.push_back(freq.first);
                maxFreq = freq.second;
            }
            else if (freq.second == maxFreq)
                res.push_back(freq.first);
        }
        return res;
    }
};
