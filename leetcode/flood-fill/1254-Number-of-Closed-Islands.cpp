
#include <vector>

using namespace std;

/*
 * 求被海水完全包围的岛屿的数量，其中 0 表示陆地，1 表示海水，和其它题目有所区别。
 * 另外需要注意的是，当岛屿在 4 个边时，不能算是完全包围。
 * 
 * 我们仍然使用 DFS 的方式去找到所有的岛屿，只不过在这个过程中我们需要多长一个心眼儿: 那些有挨着边儿的岛屿不计算在内
 */
class Solution {
private:
    int m, n;
    vector<vector<int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> visited;

    bool inGrid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool inEdge(int x, int y) {
        return x == 0 || y == 0 || x == m -1 || y == n - 1;
    }

    void dfs(vector<vector<int>>& grid, int startx, int starty, bool &flag) {
        if (inEdge(startx, starty)) flag = false;
        visited[startx][starty] = true;
        for (int i = 0; i < 4; i++) {
            int x = startx + delta[i][0], y = starty + delta[i][1];
            if (inGrid(x, y) && grid[x][y] == 0 && !visited[x][y]) {
                dfs(grid, x, y, flag);
            }
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;

        m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    bool flag = true;
                    dfs(grid, i, j, flag);
                    if (flag) result ++;
                }
            }
        }
        return result;
    }
};
