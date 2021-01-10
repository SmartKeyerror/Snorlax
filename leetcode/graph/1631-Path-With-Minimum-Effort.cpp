
#include <math.h>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

/*
 * 无向图最短路径问题，路径权值即为 abs(heights[a][b] - heights[c][d])，没有负权边，因此可使用 Dijkstra 算法解决。
 */

struct compare {
    bool operator()(vector<int> const& a, vector<int> const& b) {
        // 我们需要一个最小堆，所以堆中的其它元素需要大于堆顶元素
        return a[2] > b[2];
    }
};

class Solution {
private:
    // 有一说一，Flood Fill 算法实现中下面的“套件”是真的挺方便的......我觉得可以专门整一个 Class 出来，哈哈😁
    int m, n;
    vector<vector<int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> visited;

    bool inBoard(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        // 0: x, 1: y, 2: abstract distance
        priority_queue<vector<int>, vector<vector<int>>, compare> heap;

        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        heap.push({0, 0, 0});
        dis[0][0] = 0;

        while (!heap.empty()) {
            vector<int> current = heap.top();
            heap.pop();

            int startx = current[0], starty = current[1], weight = current[2];

            if (visited[startx][starty]) continue;
            visited[startx][starty] = true;

            for (int i = 0; i < 4; i++) {
                int x = startx + delta[i][0], y = starty + delta[i][1];
                if (!inBoard(x, y) || visited[x][y]) continue;
                
                int cost = max(weight, abs(heights[x][y] - heights[startx][starty]));

                if (cost < dis[x][y]) {
                    dis[x][y] = cost;
                    heap.push({x, y, cost});
                }

            }
        }
        return dis[m-1][n-1];
    }
};
