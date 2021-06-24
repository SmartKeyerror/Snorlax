
#include <vector>
#include <string>
#include <assert.h>
#include <algorithm>

using namespace std;


/*
 * f(m, n) = f(m, n-1) + f(m-1, n)
 * 因为只能往右或者是往下移动， 那么移动到终点的格子要么是从正上方的格子向下移动，要么是左边的格子向右移动，没有其它的可能了(自上而下)
 * 
 * 如果是自下而上的话， f(m, n-1) + f(m-1, n) = f(m, n)，最基本解就是起点位置，值为0
 * 
 *          x  x  x  x   x
 * 
 *          x  x  x  x   o
 *                       ↓ (1 way)
 *          x  x  x  o → x
 *                  (1 way)
 * 
 */
class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 第 0 行和第 0 列需要初始化成 1，因为不管是  memory[0][3] 还是 memory[3][0]，实际上都只有一条路径

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
