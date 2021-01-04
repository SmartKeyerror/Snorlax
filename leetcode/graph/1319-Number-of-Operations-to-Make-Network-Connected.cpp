#include <vector>

using namespace std;

/*
 * 连通分量个数的判断，可使用 dfs 或者是 union-find 解决。
 */

class UF {
private:
    int size = 0;
    int numComponents;
    vector<int> parents;
public:
    UF(int n) {
        size = numComponents = n;
        parents = vector<int>(n);
        for (int i = 0; i < n; i++)
            parents[i] = i;
    }

    int findNode(int u) {
        while(parents[u] != u) {
            parents[u] = parents[parents[u]];       // 注意，并不是所有的 union-find 都需要路径压缩，需要视情况而定
            u = parents[u];
        }
        return u;
    }

    void unionNode(int u, int v) {
        int pu = findNode(u);
        int pv = findNode(v);

        if (pu == pv) return;

        parents[pu] = pv;
        numComponents --;
    }

    bool connected(int u, int v) {
        return findNode(u) == findNode(v);
    }

    int components() {
        return numComponents;
    }
};

class Solution {
private:
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node) {
        visited[node] = true;
        for (int child : graph[node]) {
            if (!visited[child])
                dfs(graph, visited, child);
        }
    }

    // Runtime: 236 ms, faster than 65.87% of C++ online submissions for Number of Operations to Make Network Connected.
    int dfsSolution(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        vector<vector<int>> graph(n);
        for (int i = 0; i < connections.size(); i++) {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }

        int connectedComponent = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(graph, visited, i);
                connectedComponent ++;
            }
        }
        return connectedComponent - 1;
    }

    // Runtime: 172 ms, faster than 99.17% of C++ online submissions for Number of Operations to Make Network Connected.
    int unionFindSolution(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        UF uf = UF(n);
        for (int i = 0; i < connections.size(); i++)
            uf.unionNode(connections[i][0], connections[i][1]);
        
        return uf.components() - 1;
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // return dfsSolution(n, connections);
        return unionFindSolution(n, connections);
    }
};
