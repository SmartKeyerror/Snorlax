

#include <vector>

using namespace std;

/*
 * 从 grid[r0][c0] 开始，将所有和 grid[r0][c0] 相同颜色的格子的边涂成 color 这一新的颜色
 * 
 * 有点儿像求周长那道题目，只有最外层的格子我们需要操作，其它的格子不过是个工具人而已。
 */
class Solution {
    int m, n;
    vector<vector<int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> visited;

    bool inGrid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool inEdge(int x, int y) {
        return x == 0 || y == 0 || x == m -1 || y == n - 1;
    }

    void transform(vector<vector<int>>& grid, int srcColor, int newColor, int startx, int starty) {
        visited[startx][starty] = true;
        for (int i = 0; i < 4; i++) {
            int x = startx + delta[i][0], y = starty + delta[i][1];
            if (inGrid(x, y) && !visited[x][y]) {
                if (grid[x][y] != srcColor)     // 弄它!
                    grid[startx][starty] = newColor;
                else
                    transform(grid, srcColor, newColor, x, y);
            } else if (!inGrid(x, y))       // 弄它!
                grid[startx][starty] = newColor;
        }
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return grid;

        m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        transform(grid, grid[r0][c0], color, r0, c0);

        return grid;
    }
};
