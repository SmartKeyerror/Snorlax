#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*
 * 我们只需要把 116 问题的队列实现原封不动的 copy 过来就能解决这道问题....
 */
class Solution {
private:
    // 使用队列实现的层序遍历，虽然使用了内存空间，但是理论上可以对任意类型的二叉树执行 connect 操作
    Node *connectUseQueue(Node* root) {
        if (root == nullptr) return root;

        Node *current = root;
        queue<Node *> levelQueue;

        levelQueue.push(current);

        while (!levelQueue.empty()) {
            
            Node *prev = nullptr;
            int queueSize = levelQueue.size();

            for (int i = 0; i < queueSize; i++) {
                current = levelQueue.front();
                current->next = prev;
                prev = current;
                levelQueue.pop();

                if (current->right) levelQueue.push(current->right);

                if (current->left) levelQueue.push(current->left);
            }
        }
        return root;
    }

public:
    Node *connect(Node* root) {
        return connectUseQueue(root);
    }
};
