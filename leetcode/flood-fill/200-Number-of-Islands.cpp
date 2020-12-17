
#include <vector>
#include <string>
#include <algorithm>

#include <assert.h>

using namespace std;


/*
 * floodfill 算法案例
 * 深度优先搜索处理，和回溯法非常类似，只不过 floodfill 需要将所有的情况均遍历一遍，所以没有显式的回溯。
 */
class Solution {
private:
    // 和 079. World Search 一样，对于在二维平面上的遍历问题，我们都会使用一个辅助向量和一个辅助函数

    // 搜索前进时的辅助向量
    vector<vector<int>> delta = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // 记录已经被标记为“岛屿”的坐标
    vector<vector<bool>> isIsland;

    // 记录 grid 行数与列数, m为行，n为列
    int m, n;

    bool inGrid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void dfs(vector<vector<char>>& grid, int startx, int starty) {
        
        // floodfill 算法通常没有显式的递归终止条件，而是将递归终止条件隐藏在下一次搜索时的条件中

        for (int i = 0; i < 4; i++) {
            int newx = startx + delta[i][0];
            int newy = starty + delta[i][1];

            /*
             * 向下搜索的条件:
             *  - 坐标 (newx, newy) 没有越界
             *  - grid[newx][newy] 是一个岛屿，并且没有在 isIsland 中标记过
             */
            if (inGrid(newx, newy) && grid[newx][newy] == '1' && !isIsland[newx][newy]) {
                isIsland[newx][newy] = true;
                dfs(grid, newx, newy);
            }
        }

        return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        assert(grid.size() != 0);

        m = grid.size();
        n = grid[0].size();

        isIsland = vector<vector<bool>>(m, vector<bool>(n, false));

        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 如果此时的 grid[i][j] == '1'，并且 isIsland[i][j] 为 false 的话，说明我们找到了一个新的岛屿
                // 那么此时的任务就是将 grid[i][j] 这个岛屿相连接的岛屿全部标记一遍
                if (grid[i][j] == '1' && !isIsland[i][j]) {
                    isIsland[i][j] = true;
                    result++;
                    dfs(grid, i, j);
                }
            }
        }

        return result;
    }
};
