
#include <vector>

using namespace std;

/*
 * 挺有意思的一道题目。
 * 
 * 使用 DP 的思路处理，对于 grid[i][j] 而言，如果 grid[i][j] = '\' 的话，那么我们应该看它右边儿格子里是什么东西，如果也是 '\' 的话，那么小球就可以走到 grid[i+1][j+1]。
 * 相反的，如果是 `/` 的话，很明显的，此路不通，返回 -1。
 * 
 * 如果 grid[i][j] = '/' 的话，我们需要看它左边儿的格子的情况，如果是 '/' 的话，小球就可以走到 grid[i+1][j-1]，反之小球不能继续向下行走，返回 -1 即可。
 */
class Solution {
private:

    int m, n;

    bool inGrid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int dfs(vector<vector<int>>& grid, int startx, int starty) {
        if (startx == m) return starty;

        if (!inGrid(startx, starty)) return -1;

        if (grid[startx][starty] == 1) {
            if (inGrid(startx, starty + 1) && grid[startx][starty + 1] == 1)
                return dfs(grid, startx + 1, starty + 1);
        } else {
            if (inGrid(startx, starty - 1) && grid[startx][starty - 1] == -1)
                return dfs(grid, startx + 1, starty - 1);
        }
        return -1;
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        
        vector<int> result;

        for (int i = 0; i < n; i++)
            result.push_back(dfs(grid, 0, i));
        
        return result;
    }
};