
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 求二叉树中距离 target 为 K 的所有节点，节点使用其值返回。
 * 
 * 二叉树我们可以近似地看成是一个有向图，我们只很轻松的从父亲节点到两个孩子节点，但是反过来却有一些困难。如果把这道题换成一个无向图的距离为 K 的节点的话，
 * 一个 BFS 就能搞定。所以，我们可以尝试着将这个二叉树变成一个无向图，然后再进行 BFS。
 */
class Solution {
private:
    vector<int> result;
    unordered_map<TreeNode *, int> visited;
    unordered_map<TreeNode *, vector<TreeNode *>> graph;

    void dfs(TreeNode* root, TreeNode *parrent) {
        if (root == nullptr) return ;
        
        if (parrent)
            graph[root].push_back(parrent);
        parrent = root;

        if (root->left) graph[root].push_back(root->left);
        if (root->right) graph[root].push_back(root->right);
        
        dfs(root->left, parrent);
        dfs(root->right, parrent);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (root == nullptr) return result;
        if (K == 0) return {target->val};

        dfs(root, nullptr);
        if (graph.count(target) == 0) return result;

        queue<TreeNode *> levelQueue;
        levelQueue.push(target);
        visited.insert({target, 0});

        while (!levelQueue.empty()) {
            int size = levelQueue.size();
            for (int i = 0; i < size; i++) {
                TreeNode *current = levelQueue.front();
                levelQueue.pop();

                for (TreeNode *child: graph[current]) {
                    if (!visited.count(child)) {
                        levelQueue.push(child);
                        visited[child] = visited[current] + 1;

                        if (visited[child] == K) {
                            result.push_back(child->val);
                        }
                        else if (visited[child] > K)
                            return result;
                    }
                }
            }
        }
        return result;
    }
};
