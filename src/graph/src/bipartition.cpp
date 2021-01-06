
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * 二分图检测
 */

class Bipartition {
private:
    // -1: not visited, 0: blue, 1: red
    vector<int> visited;
    vector<unordered_set<int>> graph;

    bool dfs(int current, int color) {
        visited[current] = color;
        for (int next : graph[current]) {
            if (visited[next] == -1) {
                if (!dfs(next, 1 - color)) return false;
            } else if (visited[next] == color) return false;
        }
        return true;
    }
public:
    // 图以 Edge lists 的方式传入，每个顶点编号为 0 - vertices-1
    bool isBipartition(int vertices, vector<vector<int>> edges) {
        visited = vector<int>(vertices, -1);
        graph = vector<unordered_set<int>>(vertices);

        for (auto edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
            
        for (int i = 0; i < vertices; i++) {
            if (visited[i] == -1) {
                if (!dfs(i, 0)) return false;
            }
        }
        return true;
    }
};

int main() {

    int vertives = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4}};

    bool isBipartition = Bipartition().isBipartition(vertives, edges);

    cout<<isBipartition<<endl;   

    return 0;
}