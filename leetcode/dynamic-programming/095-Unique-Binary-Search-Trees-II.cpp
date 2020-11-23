
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
 * 第 96 号问题的延伸，要求输出所有的二叉树的组合
 * 
 * 整体思路不变，以 1 为 root, 2 为 root，3 为 root，...，直到以 n 为 root。
 * 当以 i 为 root 时，可选择的元素就被分成了两部分，其中小于 i 的元素只能成为其左子树，大于 i 的元素只能成为其右子树，这两部分同样也可以继续如此划分下去，最后再组合起来
 * 
 * 这个过程其实就是分治法，Divide And Conquer，如同归并排序一样
 */
class Solution {
private:

    vector<TreeNode*> divideAndConquer(int start, int end) {
        
        if (start > end) 
            return {nullptr};
        
        vector<TreeNode*> res;

        for (int i = start; i <= end; i++) {

            vector<TreeNode*> left = divideAndConquer(start, i - 1);
            vector<TreeNode*> right = divideAndConquer(i + 1, end);

            // 在 96 号问题中，我们使用的是乘法来确定个数的，本质上就是从 left 数组中取一个，然后再在 right 数组中取一个
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1) return {};
        return divideAndConquer(1, n);
    }
};
