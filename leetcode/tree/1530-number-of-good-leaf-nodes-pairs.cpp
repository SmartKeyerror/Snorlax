
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
 * 很有意思的一道题目，求好叶子节点的组合数。提到组合数这个东西
 * 
 * 第一反应就是求出左子树有多少个好叶子节点，右子树有多少个好叶子节点，然后双层 for 循环进行遍历。
 * 
 * 但是好叶子节点本身又和左、右子树的叶子节点到根节点的距离相关，所以这是一道后序遍历的题目。
 * 
 * 对于当前根节点 node 来说，我们先求出到根节点的距离小于等于 distance 的全左子树叶子节点，
 * 然后在求出右子树到根节点小于 distance 的全部叶子节点，由于不关系到底是哪些组合，所以可以使用一个 vector 来保存距离
 * 
 * 然后，遍历两个数组，找出和小于等于 distance 的组合
 * 
 */ 
class Solution {
private:

    int count;

    // 求以 root 为根节点的二叉树所有叶子节点到 root 节点的距离
    vector<int> dfs(TreeNode* root, int distance) {
        if (root == nullptr) return {};

        auto left = dfs(root->left, distance);
        auto right = dfs(root->right, distance);

        // 叶子节点, 距离 root 的距离为 1
        if (left.size() == 0 && right.size() == 0) return {1};
        
        // 统计结果
        for (auto ld : left) {
            for (auto rd : right) {
                if (ld + rd <= distance) count ++;
            }
        }

        // 更新距离
        vector<int> result;

        // 这里进行剪枝的话会有问题
        for (auto ld : left) {
            result.push_back(ld + 1);
        }

        for (auto rd : right) {
            result.push_back(rd + 1);
        }

        return result;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        count = 0;
        dfs(root, distance);
        return count;
    }
};