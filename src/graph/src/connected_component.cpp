

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * 计算图中连通分量的个数
 */

class ConnectedComponent {
private:
    vector<bool> visited;
    vector<unordered_set<int>> graph;

    void dfs(int current) {
        visited[current] = true;
        for (int next : graph[current]) {
            if (!visited[next]) {
                dfs(next);
            }
        }
    }
public:
    // 图以 Edge lists 的方式传入，每个顶点编号为 0 - vertices-1
    int ccNums(int vertices, vector<vector<int>> edges) {
        visited = vector<bool>(vertices, false);
        graph = vector<unordered_set<int>>(vertices);

        for (auto edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        int res = 0;
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                dfs(i);
                res ++;
            }
        }
        return res;
    }
};

int main() {

    int vertives = 7;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4},{6,5}};

    int result = ConnectedComponent().ccNums(vertives, edges);

    cout<<result<<endl;   

    return 0;
}