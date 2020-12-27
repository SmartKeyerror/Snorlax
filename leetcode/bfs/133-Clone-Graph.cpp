
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/*
 * 对一个图进行 deep copy
 */
class Solution {
private:
    // Runtime: 8 ms, faster than 93.61% of C++ online submissions for Clone Graph.
    Node *bfs(Node* node) {
        if (node == nullptr) return node;

        queue<Node *> levelQueue;
        unordered_map<Node *, Node *> map;

        Node *copyNode = new Node(node->val);
        levelQueue.push(node);
        map.insert({node, copyNode});
        
        while (!levelQueue.empty()) {
            Node *current = levelQueue.front();
            levelQueue.pop();

            for (Node *child : current->neighbors) {
                if (!map.count(child)) {
                    map[child] = new Node(child->val);
                    levelQueue.push(child);
                }
                map[current]->neighbors.push_back(map[child]);
            }
        }
        return copyNode;
    }

    // Runtime: 12 ms, faster than 48.92% of C++ online submissions for Clone Graph.
    Node *dfs(Node *node, unordered_map<Node *, Node *> &map) {
        if (node == nullptr) return nullptr;

        if (map.count(node)) return map[node];

        Node *newNode = new Node(node->val);
        map[node] = newNode;

        for (Node *child: node->neighbors)
            newNode->neighbors.push_back(dfs(child, map));

        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        return bfs(node);

        // unordered_map<Node *, Node *> map;
        // return dfs(node, map);
    }
};
