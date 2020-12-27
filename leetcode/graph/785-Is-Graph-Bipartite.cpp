
#include <vector>

using namespace std;

/*
 * 二分图检测问题，使用染色的方式实现，DFS 和 BFS 都能实现
 */
class Solution {
private:
    // -1: not visisted, 0: green, 1: blue，choose whatever color you like 😁
    vector<int> visited;

    bool dfs(vector<vector<int>>& graph, int current, int color) {
        visited[current] = color;
        for (int child : graph[current]) {
            if (visited[child] > -1 && visited[child] == visited[current])
                return false;
            else if (visited[child] == -1) {
                if (!dfs(graph, child, 1-color)) 
                    return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        visited = vector<int>(graph.size(), -1);

        // for multi connected component
        for (int i = 0; i < graph.size(); i++) {
            if (visited[i] != -1) continue;
            if (!dfs(graph, i, 0)) return false;
        }
        return true;
    }
};
