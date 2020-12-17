
#include <vector>

using namespace std;

/*
 * 求最大岛屿面积，200. Number of islands 问题的另外一种问法，仍然使用 flood fill 算法实现，其实就是 DFS
 */
class Solution {
private:
    int m, n;
    int result = 0;
    vector<vector<int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};     // 我们仍然定义 4 个方向上的单位向量
    vector<vector<bool>> visited;

    bool inGrid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void dfs(vector<vector<int>>& grid, int startx, int starty, int &count) {
        count ++;
        visited[startx][starty] = true;
        for (int i = 0; i < 4; i++) {
            int x = startx + delta[i][0], y = starty + delta[i][1];
            if (inGrid(x, y) && grid[x][y] == 1 && !visited[x][y]) {
                dfs(grid, x, y, count);
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;

        m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int count = 0;
                    dfs(grid, i, j, count);
                    result = max(result, count);
                }
            }
        }
        return result;
    }
};
