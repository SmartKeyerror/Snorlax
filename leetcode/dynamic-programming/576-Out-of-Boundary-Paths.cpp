
#include <vector>
#include <cstdlib>

using namespace std;

/*
 * There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. 
 * You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). 
 * You can apply at most maxMove moves to the ball.
 * 
 * Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. 
 * Since the answer can be very large, return it modulo 10^9 + 7.
 * 
 * Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
 * Output: 6
 * 
 * 这道题挺有意思的地方就在于需要把球移动到二维矩阵的外面儿，而不是二维矩阵中的某一个点。
 * 
 * 我们可以将球向 4 个方向上移动，并且限制了移动次数，然后需要求越出边界的总路径数
 */

const int mod = 1e9 + 7;

class Solution {
private:
    long long dp[55][55][55];
    int m, n, limit;
public:
    int findPaths(int _m, int _n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        m = _m;
        n = _n;
        limit = maxMove;
        return dfs(startRow, startColumn, 0);
    }

    long long dfs(int x, int y, int moves) {
        if (moves > limit) return 0;
        
        if (x < 0 || y < 0 || x >= m || y >= n) return 1;

        if (dp[x][y][moves] != -1) return dp[x][y][moves];

        dp[x][y][moves] = (dfs(x + 1, y, moves + 1) + dfs(x - 1, y, moves + 1) + dfs(x, y + 1, moves + 1) + dfs(x, y - 1, moves + 1)) % mod;

        return dp[x][y][moves];
    }
};