

#include <vector>
#include <queue>
#include <limits.h>
#include <iostream>

using namespace std;

/*
 * 挺有意思的一道题目，给定 n 个城市，并给定城市和城市之间的航班与价格(flights => (src, dst, pric))
 * 问有没有这样一条航线，从 src 到 dst，最多停留 k 次，并且价格最少，如果有的话，给出所花费用。如果没有，则返回 -1。
 */
class Solution {
private:
    int result = INT_MAX;
    vector<bool> visited;
    void dfs(vector<vector<int>> &prices, int &k, int current, int dst, int stoped, int cost) {

        if (stoped > k) return ;
        
        if (stoped == k - 1 && current != dst) return ;
        
        if (current == dst) {
            result = min(result, cost);
            return ;
        }

        for (int i = 0; i < prices.size(); i++) {
            if (prices[current][i] != INT_MAX && !visited[i]) {
                visited[i] = true;
                dfs(prices, k, i, dst, stoped + 1, cost + prices[current][i]);
                visited[i] = false;
            }
        }
    }

    int dfsSolution(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // 首先，我们用邻接矩阵的方式把 flights 整理一下，i 为起点， j 为终点
        vector<vector<int>> prices(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < flights.size(); i++)
            prices[flights[i][0]][flights[i][1]] = flights[i][2];
        
        visited = vector<bool>(n, false);
        // 深度优先遍历
        dfs(prices, K, src, dst, 0, 0);

        return result;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        return dfsSolution(n, flights, src, dst, K);
    }
};

int main() {
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    int k = 1;
    int src = 0, dst = 2;
    printf("%d \n", Solution().findCheapestPrice(3, flights, src, dst, k));
}