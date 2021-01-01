
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits.h>


using namespace std;

/*
 * 本质上是求解 src 节点到所有节点的最短路径，而后取出这些路径中值最大的那一条。由于题目背景为网络包单向传输时间，所以没有负权边，因此可以使用 Dijkstra 方法实现。
 */
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {

        vector<vector<pair<int,int>>> graph(N + 1);

        for (int i = 0; i < times.size(); i++)
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        
        vector<int> dis(N+1, INT_MAX);
        vector<bool> visited(N+1, false);
        dis[K] = 0;

        // pair<distance, node>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        heap.push({0, K});

        while (!heap.empty()) {
            int curret = heap.top().second;
            heap.pop();

            if (visited[curret]) continue;

            visited[curret] = true;

            for (pair<int, int> next: graph[curret]) {
                int node = next.first;
                int distance = next.second;

                if (visited[node]) continue;

                if (dis[curret] + distance < dis[node]) {
                    dis[node] = dis[curret] + distance;
                    heap.push({dis[node], node});
                }
            }
        }

        int maxShortestTime = INT_MIN;
        for (int i = 1; i < N + 1; i++)
            maxShortestTime = max(maxShortestTime, dis[i]);

        return maxShortestTime == INT_MAX ? -1: maxShortestTime;
    }
};