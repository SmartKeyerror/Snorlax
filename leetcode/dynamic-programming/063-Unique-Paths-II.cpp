
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        // 判断开始或者是结束位置是否存在障碍物
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) dp[i][j] = 1;
                
                else if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                
                // 处理第 0 行
                else if (i == 0) dp[i][j] = dp[i][j-1];

                // 处理第 0 列
                else if (j == 0) dp[i][j] = dp[i-1][j];
                
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

