

#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>

using namespace std;

/*
 * 挺有意思的一道题目，给定 n 个城市，并给定城市和城市之间的航班与价格(flights => (src, dst, pric))
 * 问有没有这样一条航线，从 src 到 dst，最多停留 k 次，并且价格最少，如果有的话，给出所花费用。如果没有，则返回 -1。
 * 
 * 简单来说就是 无权最短路径问题 + 有权最短路径问题 的组合体，一套组合拳。除了求有权最短路径以外，我们还得把无权最短路径考虑进去，也就是题目中的 K。
 * 
 * 最短路径问题嘛，解法实在是太多了，带剪枝的 DFS，带剪枝的 BFS，DP，Dijkstra算法等等等等，都能解决这个问题。
 */
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<unordered_map<int, int>> graph(n);
        for (int i = 0; i < flights.size(); i++)
            graph[flights[i][0]].insert({flights[i][1], flights[i][2]});

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;

        heap.push({0, src, K});

        while (!heap.empty()) {
            int currentDis = heap.top()[0], currentNode = heap.top()[1], remainK = heap.top()[2];
            heap.pop();

            if (currentNode == dst) return currentDis;

            if (remainK >= 0) {
                for (auto next : graph[currentNode]) {
                    int node = next.first, weight = next.second;
                    heap.push({currentDis + weight, node, remainK - 1});
                }
            }
        }
        return -1;
    }
};
