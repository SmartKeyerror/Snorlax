
#include <vector>

using namespace std;

class Solution {
private:
    int m, n;

    vector<vector<bool>> visited;

    bool inBoard(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int backtracking(vector<vector<int>>& grid, int startx, int starty) {
        if (!inBoard(startx, starty) || grid[startx][starty] == 0 || visited[startx][starty])
            return 0;
        
        visited[startx][starty] = true;

        int left_right = max(backtracking(grid, startx, starty - 1), backtracking(grid, startx, starty + 1));
        int top_down = max(backtracking(grid, startx - 1, starty), backtracking(grid, startx + 1, starty));

        visited[startx][starty] = false;

        return max(left_right, top_down) + grid[startx][starty];
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    res = max(res, backtracking(grid, i, j));
                }
            }
        }
        return res;
    }
};