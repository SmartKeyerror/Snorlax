
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
 * 删除给定 Graph 的一条边，使得 Graph 称为一棵多叉树，也就是使得图中无环。如果有多个解的话，返回在 edges 中出现最晚的那一条。
 * 
 * 可以使用并查集来解决，遍历一遍 edges，对于每一条边的两个顶点都去看下它的实际父亲节点(也就是最早添加的节点)是否是同一个，如果是同一个，那么就说明有环。
 */
class Solution {
private:
    vector<int> parents;

    int find(int node) {
        while (parents[node] != node) {
            parents[node] = parents[parents[node]];     // 路径压缩，减少查找的时间，其实就是指向其祖先节点
            node = parents[node];
        }
        return node;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parents = vector<int>(edges.size() + 1, -1);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            
            // 遍历时进行初始化，初始化时其 parent 节点为自身。
            if (parents[u] == -1) parents[u] = u;
            if (parents[v] == -1) parents[v] = v;

            int pu = find(u), pv = find(v);

            if (pu == pv) return edges[i];

            // union parents。这里还是有优化空间的
            parents[pu] = pv;
        }
        return {};
    }
};
