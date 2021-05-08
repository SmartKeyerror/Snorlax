
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


class Solution {
private:
    vector<int> result;
public:

    void dfs(Node *root) {
        if (root == nullptr) return;
        result.push_back(root->val);
        for (auto child : root->children)
            dfs(child);
        return;
    }

    vector<int> preorder(Node* root) {
        result.clear();
        dfs(root);
        return result;
    }
};