
/*
 * 挺有意思的一道题目，垂直遍历二叉树
 * 
 * 若当前节点坐标为 (x, y) 的话，那么左孩子节点坐标为 (x + 1, y - 1)，右孩子节点坐标为 (x + 1, y + 1)
 * 
 * 遍历结果使用 col 坐标的升序进行排列，当 col 坐标相同时，按照元素大小进行排列
 * 
 * 遍历的过程中记录下节点坐标即可，这道题的难点其实在于如何排序。
 * 
 * 首先，使用一个 map 来记录 col 列中所有的节点，遍历 map 时本身就是有序的。
 * 
 * 其次，我们还得记录下节点的 row 坐标以及 val 值，若 row 坐标相同则按照 val 值排序，否则按照 row 坐标排序
 */

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:

    typedef pair<int, int> Node;

    map<int, vector<Node>> mp;

    void dfs(TreeNode *root, int x, int y) {
        if (root == nullptr) return;

        mp[y].push_back({root->val, x});

        // 左孩子
        dfs(root->left, x + 1, y - 1);

        // 右孩子
        dfs(root->right, x + 1, y + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;

        dfs(root, 0, 0);

        for (auto t = mp.begin(); t != mp.end(); t++) {
            auto values = t->second;
            
            sort(values.begin(), values.end(), [](const Node& a, const Node& b) {
                return a.second == b.second ? (a.first < b.first) : (a.second < b.second);
            });
            
            vector<int> temp;
            for (const auto& value : values)
                temp.push_back(value.first);
            
            result.push_back(temp);
        }

        return result;
    }
};