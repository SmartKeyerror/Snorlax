
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/*
 * 二维数组从左上角到右下角的最短路径，行走方向为 8 个方向，且 0 表示畅通，1 表示阻塞，求最短路径长度。
 * 
 * 无权图最短路径问题，BFS 处理即可。
 */
class Solution {
private:
    int m, n;
    vector<vector<int>> delta = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    bool inGrid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
        if (m == 1 && n == 1) return 1;

        queue<pair<int, int>> levelQueue;
        vector<vector<int>> visited(m, vector<int>(n, -1));

        levelQueue.push(make_pair(0, 0));
        visited[0][0] = 1;

        while (!levelQueue.empty()) {
            pair<int, int> current = levelQueue.front();
            levelQueue.pop();

            int startx = current.first, starty = current.second;
            for (int i = 0; i < 8; i++) {
                int x = startx + delta[i][0], y = starty + delta[i][1];
                if (inGrid(x, y) && grid[x][y] == 0 && visited[x][y] == -1) {
                    levelQueue.push(make_pair(x, y));
                    visited[x][y] = visited[startx][starty] + 1;
                    if (x == m - 1 && y == n - 1) return visited[x][y];
                }
            }
        }
        return -1;
    }
};
