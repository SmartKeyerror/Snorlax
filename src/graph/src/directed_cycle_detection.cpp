
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * 有向图环检测
 */

class DirectedCycleDetection {
private:
    // -1: not visited, 0: processing, 1: processed
    vector<int> visited;
    vector<unordered_set<int>> graph;

    bool dfs(int current) {
        visited[current] = 0;
        for (int next : graph[current]) {
            if (visited[next] == -1) {
                if (dfs(next)) return true;
            } else if (visited[next] == 0) return true;
        }
        visited[current] = 1;
        return false;
    }
public:
    // 图以 Edge lists 的方式传入，每个顶点编号为 0 - vertices-1。edges[i][0] -> edges[i][1]，以此表示方向
    bool hasCycle(int vertices, vector<vector<int>> edges) {
        visited = vector<int>(vertices, -1);
        graph = vector<unordered_set<int>>(vertices);

        for (auto edge : edges)
            graph[edge[0]].insert(edge[1]);
        
        for (int i = 0; i < vertices; i++) {
            if (visited[i] == -1) {
                if (dfs(i)) return true;
            }
        }
        return false;
    }
};

int main() {

    int vertives = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0},{3,4},{2,3}};

    bool hasCycle = DirectedCycleDetection().hasCycle(vertives, edges);

    cout<<hasCycle<<endl;   

    return 0;
}
