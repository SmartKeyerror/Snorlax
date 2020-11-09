
#include <vector>
#include <assert.h>

using namespace std;

/*
 * 暴力回溯，无剪枝
 * Runtime: 8 ms, faster than 30.27% of C++ online submissions for Unique Paths III.
 */
class Solution {
    vector<vector<int>> delta = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<bool>> visited;

    int m, n;
    int result = 0, total_zero = 0;
    vector<int> starting, ending;

    bool inGrid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int total) {
        
        if (x == ending[0] && y == ending[1] && total_zero == total - 1) {
            result++;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newx = x + delta[i][0];
            int newy = y + delta[i][1];

            if (inGrid(newx, newy) && grid[newx][newy] != -1 && grid[newx][newy] != 1 && !visited[newx][newy]) {
                visited[newx][newy] = true;
                total += 1;
                dfs(grid, newx, newy, total);
                visited[newx][newy] = false;
                total -= 1;
            }
        }
        return;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {

        assert(grid.size() > 0);

        m = grid.size();
        n = grid[0].size();

        // 初始化 visited 数组
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    starting.push_back(i);
                    starting.push_back(j);
                }

                if (grid[i][j] == 2) {
                    ending.push_back(i);
                    ending.push_back(j);
                } 

                if (grid[i][j] == 0)
                    total_zero++;
            }
        }

        dfs(grid, starting[0], starting[1], 0);

        return result;
    }
};
