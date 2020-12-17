
#include <vector>

using namespace std;

/*
 * 求岛屿的周长，挺有意思的一道题目
 * 
 * 还是那句话，flood fill 算法能解决!
 * 
 * 
 * 另外一种解题思路:
 * 
 * 直接贴答案了: https://leetcode.com/problems/island-perimeter/discuss/653585/Simple-CPP-solution-O(m*n)-With-explained
 * 
 * 很巧妙的思路，从某一个顶点出发，如果当前 grid[i][j] 是岛屿，并且 grid[i][j-1] (左边) 或者是 grid[i-1][j] (右边) 也是岛屿的话，那么说明边有重叠。
 * 在计算的过程中我们需要减去这些重复计算的边。
 */
class Solution {

private:

    int m, n;
    int result = 0;
    vector<vector<int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> visited;

    bool inBoard(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int dfs(vector<vector<int>>& grid, int startx, int starty) {
        int count = 0;
        visited[startx][starty] = true;
        for (int i = 0; i < 4; i++) {
            int x = startx + delta[i][0], y = starty + delta[i][1];
            if (inBoard(x, y)) {
                if (visited[x][y]) continue;
                if (grid[x][y] == 1)
                    dfs(grid, x, y);
                else
                    count ++;
            }
            else count ++;
        }
        result += count;
    }
    
public:

    int mathSolution(vector<vector<int>>& grid) {
        int total = 0, overlapping = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    total ++;
                    if (j > 0 && grid[i][j-1] == 1) overlapping ++;
                    if (i > 0 && grid[i-1][j] == 1) overlapping ++;
                }
            }
        }
        return total * 4 - overlapping * 2;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;

        m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    return result;
                }
            }
        }
        return result;
    }
};
