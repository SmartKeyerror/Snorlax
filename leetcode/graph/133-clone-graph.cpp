#include <vector>
#include <unordered_map>


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
 * 给你无向连通图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
 * 图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。
 * 
 * 深拷贝一个无向连通图，每一个节点可能是多个节点的邻居节点，那么都需要被添加到 neighbors 数组中。
 * 
 * 深拷贝的问题还挺多的，包括链表、树或者是图的深拷贝。深拷贝的问题本质上其实是一个前序遍历的过程。
 * 
 * 以 Tree 为例，当我们拷贝根节点时，需要知道当前根节点的两个孩子节点分别是谁，否则拷贝就是不完整的。
 * 
 * 伪代码如下:
 * 
 * TreeNode *dfs(TreeNode *root) {
 *      if (root == nullptr) return nullptr;
 * 
 *      TreeNode *new = new TreeNode(root->val);
 * 
 *      new->left = dfs(root->left);
 *      new->right = dfs(root->right);
 * 
 *      return new;
 * }
 * 
 * 图的深拷贝要稍微复杂一些，因为对于 Tree 来说，它最多只有一个父亲节点，但是对于图而言，如果使用邻接表来表示的话，节点会在多个地方出现。
 * 
 * 所以就会有重复遍历的问题，在图的遍历中我们使用 visited 数组来表示某一个节点是否已经被遍历过。
 * 
 * 但是这里 cloneGraph 由于需要返回一个新的克隆节点，所以使用一个 hashmap 来建立旧节点-新节点之间的映射关系
 */
class Solution {
private:
    // old-new 映射
    unordered_map<Node *, Node *> map;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        if (map.count(node) != 0) return map[node];

        Node *cloned = new Node(node->val);
        map[node] = cloned;

        for (auto neighbors : node->neighbors) {
            cloned->neighbors.push_back(cloneGraph(neighbors));
        }

        return cloned;
    }
};
