
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * 无向图环检测
 */

class UndirectedCycleDetection {
private:
    vector<bool> visited;
    vector<unordered_set<int>> graph;

    bool dfs(int current, int parrent) {
        visited[current] = true;
        for (int next : graph[current]) {
            if (!visited[next]) {
                if (dfs(next, current)) return true;
            } else if (visited[next] && next != parrent) return true;
        }
        return false;
    }
public:
    // 图以 Edge lists 的方式传入，每个顶点编号为 0 - vertices-1
    bool hasCycle(int vertices, vector<vector<int>> edges) {
        visited = vector<bool>(vertices, false);
        graph = vector<unordered_set<int>>(vertices);

        for (auto edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                if (dfs(i, i)) return true;
            }
        }
        return false;
    }
};

int main() {

    int vertives = 5;
    vector<vector<int>> edges = {{0,1},{0,2},{2,1},{3,4},{2,3}};

    bool hasCycle = UndirectedCycleDetection().hasCycle(vertives, edges);

    cout<<hasCycle<<endl;   

    return 0;
}