
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <iostream>

using namespace std;


class Dijkstra {
private:
    vector<unordered_map<int, int>> graph;
public:
    // 图以 Edge lists 的方式传入，每个顶点编号为 0 - vertices-1。edges[i][0] 与 edges[i][1] 表示连接的两个顶点，edges[i][2] 表示距离
    // 有向图和无向图均可使用 Dijkstra 求解最短路径，所以这里使用无向图，且图中没有负权边
    vector<int> dijkstra(int vertices, vector<vector<int>> edges, int src) {

        graph = vector<unordered_map<int, int>>(vertices);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], dis = edges[i][2];
            graph[u].insert({v, dis}), graph[v].insert({u, dis});
        }

        vector<int> distance(vertices, INT_MAX);
        distance[src] = 0;
        
        vector<bool> visited(vertices, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        heap.push({0, src});

        while (!heap.empty()) {
            int current = heap.top().first;
            heap.pop();

            visited[current] = true;

            for (auto next : graph[current]) {
                int node = next.first;
                if (visited[node]) continue;
                else if (distance[current] + graph[current][node] < distance[node]) {
                    distance[node] = distance[current] + graph[current][node];
                    heap.push({node, distance[node]});
                }
            }
        }
        
        return distance;
    }
};

int main() {
    int vertices = 6, src = 0;
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 3, 3}, {1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {2, 4, 1}, {1, 5, 12}, {2, 5, 6}, {4, 5, 4}
    };
    vector<int> dis = Dijkstra().dijkstra(vertices, edges, src);

    for (int i = 1; i < vertices; i++) 
        cout<<"顶点 "<<src<<" 到顶点 "<<i<<" 的最短路径为: "<<dis[i]<<endl;
}