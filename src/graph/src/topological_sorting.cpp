#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;


/*
 * 拓扑排序
 */

class TopologicalSorting {
private:
    vector<unordered_set<int>> graph;
public:
    // 图以 Edge lists 的方式传入，每个顶点编号为 0 - vertices-1。edges[i][0] -> edges[i][1]，以此表示方向
    vector<int> topoList(int vertices, vector<vector<int>> edges) {
        graph = vector<unordered_set<int>>(vertices);

        for (auto edge : edges)
            graph[edge[0]].insert(edge[1]);
        
        vector<int> indegrees(vertices, 0);
        for (int i = 0; i < graph.size(); i++) 
            for (int neighbor : graph[i]) 
                indegrees[neighbor] ++;

        queue<int> zeroQueue;
        for (int i = 0; i < indegrees.size(); i++) {
            if (indegrees[i] == 0) zeroQueue.push(i);
        }

        vector<int> result;
        while (!zeroQueue.empty()) {
            int current = zeroQueue.front();
            zeroQueue.pop();

            result.push_back(current);

            for (int next : graph[current]) {
                indegrees[next] --;
                if (indegrees[next] == 0) zeroQueue.push(next);
            }
        }

        return result;
    }
};

int main() {

    int vertives = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4}};

    vector<int> result = TopologicalSorting().topoList(vertives, edges);

    for (int i = 0; i < result.size(); i++)
        cout<<result[i]<<", ";

    return 0;
}
