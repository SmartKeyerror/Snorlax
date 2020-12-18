#include <vector>

using namespace std;

/*
 * 首先试试暴力解法，对于每一个为海水的格子，我们都将其转换成陆地，然后按照 695. Max Area of Island 的方式求最大岛屿面积
 * 
 * 暴力解法超时
 */
class Solution {
private:
    int m, n;
    vector<vector<int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool inGrid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void dfs(vector<vector<int>>& grid, int startx, int starty, int &count, vector<vector<bool>> &visited) {
        count ++;
        visited[startx][starty] = true;
        for (int i = 0; i < 4; i++) {
            int x = startx + delta[i][0], y = starty + delta[i][1];
            if (inGrid(x, y) && grid[x][y] == 1 && !visited[x][y]) {
                dfs(grid, x, y, count, visited);
            }
        }
    }

    // 好吧，暴力解法果然超时了......
    int brouteSolution(vector<vector<int>>& grid) {
        int result = 0;
        m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                if (grid[i][j] == 0) {
                    grid[i][j] = 1;
                    dfs(grid, i, j, count, visited);
                    result = max(result, count);
                    grid[i][j] = 0;
                } else {
                    dfs(grid, i, j, count, visited);
                    result = max(result, count);
                }
            }
        }
        return result;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        return brouteSolution(grid);
    }
};