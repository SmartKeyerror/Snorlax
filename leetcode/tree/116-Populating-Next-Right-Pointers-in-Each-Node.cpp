
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
 * 二叉树层序遍历的应用，可用队列实现
 *
 * Follow up 中有给出不用额外的内存空间实现，并且明确地表示也可以使用递归实现
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

    // 使用 DFS + 循环 实现
    Node *connectUseDFS(Node *root) {
        if (root == nullptr || root->left == nullptr) return root;

        Node *left = root->left;
        Node *right = root->right;
        left->next = right;

        while (left->left != nullptr) {
            left->right->next = right->left;
            left = left->right;
            right = right->left;
        }

        connectUseDFS(root->left);
        connectUseDFS(root->right);

        return root;
    }

public:
    Node *connect(Node* root) {
        // return connectUseQueue(root);
        return connectUseDFS(root);
    }
};