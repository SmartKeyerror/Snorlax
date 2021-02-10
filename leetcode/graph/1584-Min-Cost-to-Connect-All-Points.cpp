
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


class UnionFind {
private:
    int numComponents;
    vector<int> parents;

    int find(int u) {
        while (u != parents[u]) {
            parents[u] = parents[parents[u]];
            u = parents[u];
        }
        return u;
    }

public:
    UnionFind(int size) : numComponents(size) {
        parents = vector<int>(size);
        for (int i = 0; i < parents.size(); i++)
            parents[i] = i;
    }

    void unionNode(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return ;
        parents[pu] = pv;
        numComponents --;
    }

    bool isConnected(int u, int v) {
        return find(u) == find(v);
    }

    int getCCNums() {
        return numComponents;
    }
};


/*
 * 最小生成树问题，Greedy + Union Find 解决 (Kruskal)。
 */
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dis = abs(x1 - x2) + abs(y1 - y2);
                edges.push_back({i, j, dis});
            }
        }

        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {return a[2] < b[2];});

        int result = 0, pickedEdges = 0;
        UnionFind uf(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], dis = edges[i][2];
            
            if (!uf.isConnected(u, v)) {
                result += dis;
                uf.unionNode(u, v);
                pickedEdges ++;
            }

            // 简单的优化
            if (pickedEdges == n - 1) break;
        }

        return result;
    }
};