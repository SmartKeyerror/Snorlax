

#include <vector>

using namespace std;


/*
 * 又是一道比较典型的 Flood Fill 算法问题，只不过这次问的是完全被海洋包围的所有陆地面积，若陆地中包含边界，则不计入结果之中。
 * 
 * 
 */
class Solution {
private:
    int m, n;
    vector<vector<int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> visited;

    bool inGrid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool inBoundary(int x, int y) {
        return x == 0 || y == 0 || x == m - 1 || y == n - 1;
    }

    void dfs(vector<vector<int>>& grid, int startx, int starty, int& area, bool& hasBoundary) {
        visited[startx][starty] = true;
        if (inBoundary(startx, starty)) hasBoundary = true;
        area ++;

        for (int i = 0; i < 4; i++) {
            int x = startx + delta[i][0], y = starty + delta[i][1];
            if (inGrid(x, y) && !visited[x][y] && grid[x][y] == 1) {
                visited[x][y] = true;
                
                dfs(grid, x, y, area, hasBoundary);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int result = 0;
        m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    int area = 0;
                    bool hasBoundary = false;
                    dfs(grid, i, j, area, hasBoundary);
                    if (!hasBoundary) result += area;
                }
            }
        }
        return result;
    }
};