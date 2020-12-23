
#include <vector>
#include <queue>

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
 * 闭着眼睛都应该能写出来的层序遍历，而且是一颗树，不需要考虑重复访问的问题
 */
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;

        if (root == nullptr) return result;

        queue<Node *> levelQueue;
        levelQueue.push(root);

        while (!levelQueue.empty()) {
            vector<int> levelResult;
            int size = levelQueue.size();

            for (int i = 0; i < size; i++) {
                Node *current = levelQueue.front();
                levelQueue.pop();
                
                levelResult.push_back(current->val);
                
                for (Node *child : current->children)
                    levelQueue.push(child);
            }
            result.push_back(levelResult);
        }
        return result;
    }
};
