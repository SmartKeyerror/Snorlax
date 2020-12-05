
#include <vector>

using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/*
 * N 叉树的深度优先遍历问题，求 N 叉树的最大高度
 * 
 * 明确递归函数定义: maxDepth 为求以 root 为根的最大多叉树树高
 */
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        
        int depth = 0;
        for (Node *child: root->children)
            depth = max(depth, maxDepth(child));
        return depth + 1;
    }
};
