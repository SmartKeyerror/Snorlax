

#include <vector>
#include <queue>
#include <limits.h>

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
private:
    int result = INT_MAX;
    vector<bool> visited;
    void dfs(vector<vector<int>> &prices, int k, int current, int dst, int cost) {
                
        if (current == dst) {
            result = min(result, cost);
            return ;
        }

        for (int i = 0; i < prices.size(); i++) {
            // 剪枝条件，当然也可以作为递归终止条件来写，但是能省一个栈帧是一个，干脆怼到一起
            if (prices[current][i] != INT_MAX && !visited[i] && cost + prices[current][i] < result && k - 1 >= 0) {
                visited[i] = true;
                dfs(prices, k - 1, i, dst, cost + prices[current][i]);
                visited[i] = false;
            }
        }
    }

    // Runtime: 236 ms, faster than 7.42% of C++ online submissions for Cheapest Flights Within K Stops.
    int dfsSolution(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // 首先，我们用邻接矩阵的方式把 flights 整理一下，i 为起点， j 为终点
        vector<vector<int>> prices(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < flights.size(); i++)
            prices[flights[i][0]][flights[i][1]] = flights[i][2];
        
        visited = vector<bool>(n, false);
        // 深度优先遍历
        dfs(prices, K + 1, src, dst, 0);

        if (result == INT_MAX) return -1;

        return result;
    }


public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        return dfsSolution(n, flights, src, dst, K);
    }
};
